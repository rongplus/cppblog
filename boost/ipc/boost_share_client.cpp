// boosttest.cpp : 定义控制台应用程序的入口点。
//

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

struct ShareInfo
{
    int a;
    std::string s;
};

using namespace std;
using namespace boost::interprocess;

int main(int argc, char *argv[])
{
    cout << "argc" << argc << argv[0];

       {
        //1 创建共享内存
        shared_memory_object shm(open_only, "SharedMemory", read_only);

        //2 映射共享内存
        mapped_region region(shm, read_only);

        //3 检查共享内存是否被初始化为1
        ShareInfo* strRead = static_cast<ShareInfo*>(region.get_address());

        std::cout << strRead->a << "--" <<strRead->s << endl;
         //printf( tostrRead->a);
        //printf( strRead->s);
    }

    getchar( );
    return 0;
}

// g++ -I/Users/admin/work/boost1/include shareM.cpp -o share