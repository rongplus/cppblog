#include <iostream>
#include <stdexcept>
#include <functional>

using namespace std;

/// set custom terminate function
///
void myTerminate() { cout << "by default terminate"; }

///set_unexpected example
///
void myunexpected()
{
    cout << "unexpected called\n";
    throw 0; // throws int (in exception-specification)
}

void normal_throw_function()
{
    try
    {
        // code here
        throw 1;
    }
    catch (int param)
    {
        cout << "int exception OK --- " << endl;
    }
    catch (char param)
    {
        cout << "char exception\n";
    }
    catch (...)
    {
        cout << "default exception\n";
    }
}

void throw_in_catch()
{
    try
    {

        throw string("zero salary");
        cout << " try throw_in_catch" << endl;
    }
    catch (string s)
    {
        cout << "catch throw_in_catch : " << s << endl;
        throw; //继续抛出捕获的异常
    }
    cout << "tax counted" << endl;
}

void get_exception()
{
    try
    {
        throw_in_catch();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (string s)
    {
        cout << "catch get_exception : " << s << endl;
    }
}




void Throw() { throw 1; }

void NoBlockThrow() { Throw(); }

void BlockThrow() noexcept { Throw(); }

int test_throw()
{
    try
    {
        Throw();
    }
    catch (...)
    {
        cout<<"Found throw."<<endl; //Found throw.
    }

    try
    {
        NoBlockThrow();
    }
    catch (...)
    {
        cout<<"Throw is not blocked."<<endl; //Throw is not blocked.
    }

// noexcept function exception will not catched and go to default function
    try
    {
        cout << "test noexcept line = " << __LINE__ << endl;
        BlockThrow(); //terminate called after throwing an instance of'int'
    }
    catch (...)
    {
        cout<<"Found throw 1."<<endl;
    }
}

int main()
{
    //regist custom terminate function
    set_terminate(myTerminate);
    // set_unexpected
    std::set_unexpected(myunexpected);

    normal_throw_function();

    get_exception();

    test_throw();

    return 0;
}