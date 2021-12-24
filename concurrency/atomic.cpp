// atomic::load/store example
#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::memory_order_relaxed
#include <thread>         // std::thread
#include <mutex>

static std::atomic<int> foo (0);

void set_foo(int x) {
  foo.store(x,std::memory_order_relaxed);     // set value atomically
}

void print_foo() {
  int x;
  do {
    x = foo.load(std::memory_order_relaxed);  // get value atomically
  } while (x==0);
  std::cout << "foo: " << x << '\n';
}


std::atomic<int> foo1(0);

void set_foo1(int x)
{
  for (int n=0; n<100; ++n)
    if( (foo1 ++)%80==0)
    std::cout << "80 times====" << foo1 << std::endl;
}

std::mutex gWriteLogMutex;
#include <vector>
class ConsumerWriter
{
public:
  void write(int num,std::string name)
  {
    std::lock_guard<std::mutex> g(gWriteLogMutex);
    std::cout << "Consumer ("<< name << ") write --> " << num << std::endl;
  }
};

class TestMultiConsumer
{
public:
  TestMultiConsumer(std::string name):name_(name)
  {
    
  }
  ~TestMultiConsumer()
  {
    std::cout << "End TestMultiConsumer at :" << index_ << std::endl;
  }

  void log()
  {
    for (int n=0; n<100; ++n)
    if( (index_ ++)%80==0)
    {
      write_->write(index_,name_);
      _sleep(3);
    }
  }
  static std::atomic<int> index_;
  static std::unique_ptr< ConsumerWriter> write_;
  std::string name_;

};

std::atomic<int> TestMultiConsumer::index_=0;
std::unique_ptr< ConsumerWriter> TestMultiConsumer::write_ = std::make_unique<ConsumerWriter>( );

void TestConsumerWorker(std::string name)
{
  TestMultiConsumer cm(name);


}
int main ()
{
  std::thread first (print_foo);
  std::thread second (set_foo,10);
  first.join();
  second.join();

  std::vector<std::thread> lt;

  for(int n=0; n<10;n++)
  {
    std::thread second (set_foo1,10);
    lt.push_back(std::move(second));
  }

  for (auto &t: lt)
  {
   // std::cout << "joined" << std::endl;
    t.join();
  }

  TestMultiConsumer m("test -1");

   std::thread t1(&TestMultiConsumer::log, &m);
   std::thread t2(&TestMultiConsumer::log, &m);
   std::thread t3(&TestMultiConsumer::log, &m);
   std::thread t4(&TestMultiConsumer::log, &m);
   std::thread t5(&TestMultiConsumer::log, &m);

   TestMultiConsumer cm22("test -2");

   std::thread d1(&TestMultiConsumer::log, &cm22);
   std::thread d2(&TestMultiConsumer::log, &cm22);
   std::thread d3(&TestMultiConsumer::log, &cm22);
   std::thread d4(&TestMultiConsumer::log, &cm22);
   std::thread d5(&TestMultiConsumer::log, &cm22);
   std::thread d6(&TestMultiConsumer::log, &cm22);
   std::thread d7(&TestMultiConsumer::log, &cm22);

   t1.join();
   t2.join();
   t3.join();
   t4.join();
   t5.join();
   d1.join();
   d2.join();
   d3.join();
   d4.join();
   d5.join();
   d6.join();
   d7.join();

  std::cout << "value = " << foo1 << std::endl;
  return 0;
}