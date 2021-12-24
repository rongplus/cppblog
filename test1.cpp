#include <iostream>
using namespace std;
class A
{
public:
    operator int() { return 1; }
    operator char*() { return NULL; }
};
int main()
{
    A a;
    int n;
    char* p = "New Dragon Inn";
    n = static_cast <int> (3.14);  // n 的值变为 3
    cout << "Result = " << n << " p is: "<< p << "p = " << *p<<endl;
    n = static_cast <int> (a);  //调用 a.operator int，n 的值变为 1
    cout << "Result = " << n << " p is: "<< p << "p = " << *p<<endl;
    p = static_cast <char*> (a);  //调用 a.operator char*，p 的值变为 NULL
    cout << "Result = " << n << " p is: "<< p << "p = " << *p<<endl;
    //n = static_cast <int> (p);  //编译错误，static_cast不能将指针转换成整型
    cout << "Result = " << n << " p is: "<< p << "p = " << *p<<endl;
    //p = static_cast <char*> (n);  //编译错误，static_cast 不能将整型转换成指针
    cout << "Result = " << n << " p is: "<< p << "p = " << *p<<endl;

    main1();
    return 0;
}

#include <iostream>
using namespace std;
class B
{
public:
    int i;
    int j;
    A(int n):i(n),j(n) { }
};
int main1()
{
    B a(100);
    int &r = reinterpret_cast<int&>(a); //强行让 r 引用 a
    r = 200;  //把 a.i 变成了 200
    cout << a.i << "," << a.j << endl;  // 输出 200,100
    int n = 300;
    B *pa = reinterpret_cast<B*> ( & n); //强行让 pa 指向 n
    pa->i = 400;  // n 变成 400
    pa->j = 500;  //此条语句不安全，很可能导致程序崩溃
    cout << n << endl;  // 输出 400
    long long la = 0x12345678abcdLL;
    pa = reinterpret_cast<B*>(la); //la太长，只取低32位0x5678abcd拷贝给pa
    unsigned int u = reinterpret_cast<unsigned int>(pa);//pa逐个比特拷贝到u
    cout << hex << u << endl;  //输出 5678abcd
    typedef void (* PF1) (int);
    typedef int (* PF2) (int,char *);
    PF1 pf1;  PF2 pf2;
    pf2 = reinterpret_cast<PF2>(pf1); //两个不同类型的函数指针之间可以互相转换
}