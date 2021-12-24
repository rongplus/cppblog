#include "../myinc.h"

//#include <cassert>
#include <vector>

struct ABC
{

};


int main()
{

ABC abc;
    int* pData = reinterpret_cast<int*>(&abc);
    std::vector<int> vt(pData,pData+6);
    //not as efficent as above one
    //std::copy(pData,pData+6,vt.begin());
    return 0;
}