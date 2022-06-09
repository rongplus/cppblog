#include <iostream>
#include <memory>
#include <string>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

int main()
{
    std::mutex m;
    std::condition_variable cv;
    std::string new_string;
    bool error = false;

    auto io_thread = std::thread([&]{
        std::string s;
        while(!error && std::getline(std::cin, s, '\n'))
        {
            auto lock = std::unique_lock<std::mutex>(m);
            new_string = std::move(s);
            if (new_string == "quit") {
                error = true;
            }
            lock.unlock();
            cv.notify_all();
        }
        auto lock = std::unique_lock<std::mutex>(m);
        error = true;
        lock.unlock();
        cv.notify_all();
    });

    auto current_string = std::string();
    for ( ;; )
    {
        auto lock = std::unique_lock<std::mutex>(m);
        cv.wait(lock, [&] { return error || (current_string != new_string); });
        if (error)
        {
            break;
        }
        current_string = new_string;
        lock.unlock();

        // now use the string that arrived from our non-blocking stream
        std::cout << "new string: " << current_string;
        std::cout.flush();
        for (int i = 0 ; i < 10 ; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << " " << i;
            std::cout.flush();
        }
        std::cout << ". done. next?\n";
        std::cout.flush();
    }
    io_thread.join();
    return 0;
}