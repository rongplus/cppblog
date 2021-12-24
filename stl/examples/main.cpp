#include "../myinc.h"
#include "test.h"

using namespace std;

class Abc
{
public:
    Abc() { cout << __func__ << endl; }
    ~Abc() { cout << __func__ << endl; }
};

class Test
{
public:
    Test()
    {
        cout << __func__ << endl;

        try{
 a = new Abc();
        throw 9;
        }
        catch(...)
        {
            delete a;
            throw;
        }

       
    }
    ~Test()
    {
        cout << __func__ << endl;
        delete a;
    }

    Abc *a = nullptr;
};
 int main()
{
    std::cout << aget() << endl;
    ainit();
    std::cout << aget() << endl;
    aset(12);
    std::cout << aget() << endl;

    try
    {
        //Test* t = new Test();
        unique_ptr<Test> p =  make_unique<Test>();
    }
    catch(...)
    {
        cout << "got error" << endl;
    }
}