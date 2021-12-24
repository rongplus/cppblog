#include <atomic>
#include <cassert>
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

std::atomic<int> cnt = {0};
void f() {
  for (int n = 0; n < 1000; ++n) {
    cnt.fetch_add(1, std::memory_order_relaxed);
  }
}

/*
 * A class that has thread object as member variable
 */
class ThreadWrapper {
  // std::thread object
  std::thread threadHandler;
  std::thread threadHandler11;

public:
  // Delete the copy constructor
  ThreadWrapper(const ThreadWrapper &) = delete;
  // Delete the Assignment opeartor
  ThreadWrapper &operator=(const ThreadWrapper &) = delete;
  // Parameterized Constructor
  ThreadWrapper(std::function<void()> func);
  // Move Constructor
  ThreadWrapper(ThreadWrapper &&obj);
  // Move Assignment Operator
  ThreadWrapper &operator=(ThreadWrapper &&obj);
  // Destructor
  ~ThreadWrapper();

  static void thread1(ThreadWrapper *p);
  static int aaa;
  int bbb = 0;
  std::string name = "dddd";
  bool running = true;
};
int ThreadWrapper::aaa = 55;
// Parameterized Constructor
ThreadWrapper::ThreadWrapper(std::function<void()> func) : threadHandler(func) {
  threadHandler11 = (std::thread(ThreadWrapper::thread1, this));
}

void ThreadWrapper::thread1(ThreadWrapper *p) {
  int i = 0;
  while (p->running) {
    std::cout << i << "----" << p->name << aaa << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(2));
    i++;
  }
}

// Move Constructor
ThreadWrapper::ThreadWrapper(ThreadWrapper &&obj)
    : threadHandler(std::move(obj.threadHandler)) {
  std::cout << "Move Constructor is called" << std::endl;
}
// Move Assignment Operator
ThreadWrapper &ThreadWrapper::operator=(ThreadWrapper &&obj) {
  std::cout << "Move Assignment is called" << std::endl;
  if (threadHandler.joinable())
    threadHandler.join();
  threadHandler = std::move(obj.threadHandler);
  return *this;
}
// Destructor
ThreadWrapper::~ThreadWrapper() {
  if (threadHandler.joinable())
    threadHandler.join();
  // running = false;
  if (threadHandler11.joinable())
    threadHandler11.join();
}

int main() {

  // Creating a std::function object
  std::function<void()> func = []() {
    // Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // Print thread ID
    std::cout << "From Thread ID : " << std::this_thread::get_id() << "\n";
  };
  {
    // Create a ThreadWrapper object
    // It will internally start the thread
    ThreadWrapper wrapper(func);
    // When wrapper will go out of scope, its destructor will be called
    // Which will internally join the member thread object
  }
  std::vector<std::thread> v;
  for (int n = 0; n < 10; ++n) {
    v.emplace_back(f);
  }
  for (auto &t : v) {
    t.join();
  }
  assert(cnt == 10000); // never failed
  std::cout << "done" << std::endl;
  return 0;
}