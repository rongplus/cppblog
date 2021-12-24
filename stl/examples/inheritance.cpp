//少年方世玉 少年张三丰  办案小组  小谢尔顿 马尔科姆一家
#include <iostream>
#include <list>
#include <memory>
using namespace std;

/*
/// 1,default constructor if no any constructor defined by user.
/// 2, copy constructor
/// 3, copy assignment operator
/// 4, destructor

/// 5, move constructor
/// 6 move assignment operator.


*/

/*
hide function.

*/
class Testor
{
public:
    Testor(){}
    operator string() const { return "Testor";}
    operator int() const {return 10;}
    virtual ~Testor() { cout << "testor ~~" << endl;}

    virtual void doJob(){}
    virtual void doJob(int a){}

    Testor(const Testor& e){}
    Testor(const Testor&& e){}
    Testor& operator = (Testor&& t){}
    Testor& operator = (Testor& t){}




};

class TestorSub : public Testor
{
public:
    //this will hide the dojob(int) from base class.
    void doJob( ) { cout <<name <<  " do job" << endl;}
    string name = "bob";
     ~TestorSub() { cout << "TestorSub ~~" << endl;}
};
void main_exit() 
{

}//main_exit函数在main函数返回后调用


int main()
{
    Testor tt;
    string name = tt;
    int age = tt;
    cout << "I am " << name << " age:" << age << endl; 

    Testor* t1 = new Testor();
    TestorSub* t2 = dynamic_cast<TestorSub*>(t1);
    //if (t2)
    //    t2->doJob();

    t2->doJob(3);

    cout << "endl" << endl;

    shared_ptr<Testor> p1 = make_shared<TestorSub>();
    TestorSub* p2 = dynamic_cast<TestorSub*>(p1.get());

    shared_ptr<TestorSub> p3 = dynamic_pointer_cast< TestorSub >(p1);

    unique_ptr<TestorSub> p4 (new TestorSub());
    return 0;
}
