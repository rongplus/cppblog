#include<iostream>
#include <assert.h>
#include <memory>
#include <math.h>
using namespace std;


class People
{
public:
    People() = default;

    virtual  void sayHei(){ cout << "n=" << n << endl;}

    int n = 10;
};

class Senier : public People
{
    public:
    Senier() = default;
    void sayHello() {cout << "hello" << m << endl;}
    int m = 19;

};
//static_cast, dynamic_cast,const_cast,reinterpret_cast，
int main()
{
    People p;
    //Senier* s = &p;
    Senier ss;
    People* pp = &ss;

    cout << "Test 1--" << pp << ", " << &ss << endl;

    Senier* s1 = static_cast<Senier*>(&p);
    cout << "Test 2--" << &p << ", " << s1 << endl;
    s1->sayHello();

    s1 = dynamic_cast<Senier*>(&p);
    cout << "Test 3--" << &p << ", " << s1 << endl;

    return 0;
}