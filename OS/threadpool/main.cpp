
//this two defenition is for windows
//#define GLOG_NO_ABBREVIATED_SEVERITIES
//#define GOOGLE_GLOG_DLL_DECL

#include <windows.h>
#include <iostream>
#undef ERROR

#include <glog/logging.h>

#include <thread>
#include "ThreadPool.h"
#include <utility>
#include <tuple> 
#include <assert.h>

/* tasks with returned value, no arguments */
void test1()
{
    /* Compute square of numbers. */
    ThreadPool pool(4);
    std::vector<std::future<int>> results;

    for (int i = 0; i < 8; ++i)
    {
        auto future = pool.enqueue([i] {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return i * i;
            });
        results.emplace_back(std::move(future));
    }

    for (auto& result : results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
}
bool isAscending(std::vector<int>& nums, int l, int r)
{
    for (int i = l; i + 1 < r; ++i)
        if (nums[i] > nums[i + 1])
            return false;
    return true;
}
/* tasks with returned values, and arguments. */
void test2()
{
    /* Multiple threads sorting */
    constexpr int N = 1e7;
    std::vector<int> nums(N);

    srand(time(nullptr));
    for (int i = 0; i < N; ++i)
        nums[i] = rand();

    ThreadPool pool(4);
    std::vector<std::future<std::pair<int, int>>> res;
    constexpr int step = N / 4;

    /* Sort numbers in range [l, r). */
    auto sort_task = [&nums](int l, int r) {
        std::this_thread::sleep_for(std::chrono::seconds(rand()%5));
        std::sort(nums.begin() + l, nums.begin() + r);
        return std::make_pair( l, r );
    };

    for (int i = 0; i < 4; ++i)
    {
        auto future = pool.enqueue(sort_task, i * step, (i + 1) * step);
        res.emplace_back(std::move(future));
    }

    /* x.get() will wait for the completion of thread */
    for (auto& x : res)
    {
        int myint; int mychar;
  

       auto p = x.get();
       p.first; p.second;
        assert(isAscending(nums, p.first, p.second));
        std::printf("Pass [%d, %d). \n", p.first, p.second);
    }
}

std::string worker(std::string name)
{
    for (int n = 0; n < 1000000; ++n)
    {
        std:
        LOG(INFO) <<   name << " cookies";
        DLOG(INFO) << name <<  "Found cookies";

        //DLOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

        DLOG_EVERY_N(INFO, 10) << name <<  "Got the " << google::COUNTER << "th cookie";

        LOG(INFO) << name<< "info test";  //输出一个Info日志
        LOG(WARNING)<< name << "warning test";  //输出一个Warning日志
        LOG(ERROR)<< name << "error test";  //输出一个Error日志
    }

    return name.append(" -done\n");
}

std::string worker1(std::string name,int n)
{
    for (int n = 0; n < 10; ++n)
    {
   
        //LOG(INFO) << name << " cookies";
        //DLOG(INFO) << name << "Found cookies";

        //DLOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

        DLOG_EVERY_N(INFO, 10) << name << " Got the " << google::COUNTER << "th cookie";

        //LOG(INFO) << name << "info test";  //输出一个Info日志
        LOG(WARNING) << name << "->warning test";  //输出一个Warning日志
        //LOG(ERROR) << name << "error test";  //输出一个Error日志
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return name.append(" -done\n");
}

void test3()
{
    /* Compute square of numbers. */
    ThreadPool pool(10);
    std::vector<std::future<std::string>> results;

    for (int i = 0; i < 35; ++i)
    {
        std::string name = "test" + std::to_string(i);
        auto future = pool.enqueue(worker1,name,i);
        results.emplace_back(std::move(future));
    }

    for (auto& result : results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
}

template<typename T>
void printPP(const T& t) {
    std::cout << t << ", "; 
}


template<typename T, typename... Args>
 void printPP(  const T& t, const Args&... rest) {
    std::cout << t << ", ";
   
     printPP(  rest...);
}

//cl glogtest.cpp -I D:\3rdLib\include D:\3rdLib\libs\glog.lib
//g++ logtest.cpp -std=c++14 -lglog -o log/
int main(int argc, char* argv[]) {
    // Initialize Google's logging library.
    FLAGS_logtostderr = false;
    FLAGS_log_dir = "D:/Dowdload2022/log";
    google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::GLOG_INFO, "D:/Dowdload2022/log");

    google::SetStderrLogging(google::GLOG_INFO);
    google::SetLogFilenameExtension("log_");//google::InitGoogleLogging(argv[0]);
    FLAGS_colorlogtostderr = true;  // Set log color
    FLAGS_logbufsecs = 0;  // Set log output speed(s)
    FLAGS_max_log_size = 1024;  // Set max log file size
    FLAGS_stop_logging_if_full_disk = true;  // If disk is full




    int num_cookies = 100;
    // ...
    LOG(INFO) << "Found " << num_cookies << " cookies";
    DLOG(INFO) << "Found cookies";

    DLOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

    DLOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";
   
    LOG(INFO) << "info test";  //输出一个Info日志
    LOG(WARNING) << "warning test";  //输出一个Warning日志
    LOG(ERROR) << "error test";  //输出一个Error日志
    //LOG(FATAL) << "fatal test";  //输出一个Fatal日志，这是最严重的日志并且输出之后会中止程序
     //std::thread io_thread  (worker, "test"); 
     test1();
     test2();
     test3();
     //io_thread.join();
    google::ShutdownGoogleLogging();

    printPP( 1, 2, "haha");//"1, 2, haha"

}


