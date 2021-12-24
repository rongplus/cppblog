#include<iostream>
#include <assert.h>
#include <memory>
#include <math.h>
using namespace std;

class A
{
public:
   A() { cout << "A constructed" << endl;}
   A(int i){value = i; cout << "A 1" << endl;}
   ~A() { cout << "A destructed" << endl;}
   int GetVal()
   {
       cout << __func__ << endl;
      return value;
   }
   int value = 10;
};

void test( shared_ptr<A> a)
{
    int i = 0;
};

void testU (unique_ptr<A> a)
{
     cout << __func__ << endl;
    int n = 0;
}
void testUR( unique_ptr<A> &a)
{
    if (a){
        cout << __func__ << endl;
        a->GetVal();
    }
    
     cout << __func__ << endl;
    int n = 4;
}
int main()
{
    shared_ptr<A> a = make_shared<A>();
    test(a);
    shared_ptr<A> b = a;
    unique_ptr<A> c = make_unique<A>();
    testU(move(c));
    
    assert(c == nullptr);
    if (c == nullptr)
    {
        cout << "No A" << endl;
    }
    else
        c->GetVal();
    testUR(c);
    if (c == nullptr)
    {
        cout << "No A" << endl;
    }
    else
        c->GetVal();

    cout << "Done" <<endl;

    return 0;
}