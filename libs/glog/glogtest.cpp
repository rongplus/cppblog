
//this two defenition is for windows
#define GLOG_NO_ABBREVIATED_SEVERITIES
#define GOOGLE_GLOG_DLL_DECL

#include <windows.h>
#undef ERROR

#include <glog/logging.h>
//cl glogtest.cpp -I D:\3rdLib\include D:\3rdLib\libs\glog.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
//g++ logtest.cpp -std=c++14 -lglog -o log/
   int main(int argc, char* argv[]) {
     // Initialize Google's logging library.
    FLAGS_logtostderr = false;
    FLAGS_log_dir = "D:/Dowdload2022/log";
google::InitGoogleLogging(argv[0]);
google::SetLogDestination(google::GLOG_INFO,"D:/Dowdload2022/log" );

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
std::basic_streambuf

   LOG(INFO) << "info test";  //输出一个Info日志
LOG(WARNING) << "warning test";  //输出一个Warning日志
LOG(ERROR) << "error test";  //输出一个Error日志
LOG(FATAL) << "fatal test";  //输出一个Fatal日志，这是最严重的日志并且输出之后会中止程序

google::ShutdownGoogleLogging();

   }