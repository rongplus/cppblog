#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    auto fun1 = [=](int b) {
        cout << "a=" << a << " b= " << b << endl;
    };
    auto fun2 = [&](int b) {
        cout << "a=" << a << " b= " << b << endl;
    };

    a = 30;
    fun1(a);
    fun2(a);

    return 0;
}
///out put: notice the value of a.
///a=10 b= 30
///a=30 b= 30
///
