#include <boost/bind.hpp>
#include <boost/system/system_category.hpp>
#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>

void Print(const boost::system::error_code & ,
           boost::asio::deadline_timer * t,int * count)
{
    if(*count < 5)
    {
        std::cout<<*count<<std::endl;
        ++(*count);
        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(boost::bind(Print,boost::asio::placeholders::error,t,count));
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    boost::asio::io_service io;
    int count = 0;
    boost::asio::deadline_timer t(io,boost::posix_time::seconds(1));
    t.async_wait(boost::bind(Print,boost::asio::placeholders::error,&t,&count));
    io.run();
    return 0;
}