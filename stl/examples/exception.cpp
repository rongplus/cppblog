#include <iostream>
#include <list>
using namespace std;

class EA
{
public:
         EA(string str) { from = str; cout << "born = " << str << endl; }
        ~EA() { cout << "!A =" << from << endl;  throw 20;}

        EA& operator=(const EA& rEa)
        {
                from = rEa.from;
        }
        EA(EA &dd)
        {
                from = dd.from;
        }
private:
        string from;
};

class EB
{
public:
        EB(string str) { from = str;cout << "born = " << str << endl; }
        ~EB() { cout << "!B =" << from << endl; }
        string from;
};

void f1()
{
        EA ea("f1");
       // EA dd = string("dd");
        EB eb("f1");
        throw("f1");
}

void f2()
{
        EA ea("f2");
        EB eb("f2");
        f1();
        throw("f2");
}

void f3()
{
        EA ea("f3");
        EB eb("f3");

        f2();
        throw("f3");
}

void testExceptionFromDestruct()
{
       try{
               EA ea("Test");
       }
       catch(int n)
       {
               cout <<__func__ << " catched int" << endl;
       }
       catch(const std::exception& e)
        {
                std::cerr << e.what() << '\n';
        }
}


void myTerminate() { cout << "by default terminate"; }

void testExceptionFromFunction()
{
        try
        {
                f3();
        }
        catch (const std::exception &e)
        {
                std::cerr << e.what() << '\n';
        }
}

int main()
{
        set_terminate(myTerminate);
        //set_unexpected(my_unexpected);
        testExceptionFromDestruct();
        // catch( const char* ch)
        // {
        //     cout <<"get = " <<  ch << endl;
        // }

        return 0;
}