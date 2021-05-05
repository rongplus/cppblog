// boosttest.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace std;
using namespace boost::interprocess;

struct ShareInfo
{
    int a;
    std::string s;
};

int main(int argc, char *argv[])
{
    cout << "argc" << argc << argv[0];

    //1 删除共享内存
    struct shm_remove
    {
        shm_remove()
        {
            printf("Remover----\n");
            shared_memory_object::remove("SharedMemory");
        }
        ~shm_remove()
        {
            printf("----Remover\n");
            shared_memory_object::remove("SharedMemory");
        }
    } remover;

    //2 创建共享内存段
    shared_memory_object shm(create_only, "SharedMemory", read_write);

    //3 设置共享内存大小
    shm.truncate(100);

    //4 映射共享内存片段
    mapped_region region(shm, read_write);

    //5 初始化为1
    std::memset(region.get_address(), 2, region.get_size());

    ShareInfo *strTest = static_cast<ShareInfo*>(region.get_address());

strTest->s = "hello world";
strTest->a = 10;


    getchar();
    return 0;
}

// g++ -I/Users/admin/work/boost1/include shareM.cpp -o share