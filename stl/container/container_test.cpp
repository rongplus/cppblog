#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


class A{
public:
virtual void set(const string & var1, const string & var2){
  m_var1 = var1;  //copy
  m_var2 = var2;  //copy
  cout << "call lvale" << endl;

 
}
 void job() { cout << "do function--- " << endl;}
void set(string && var1, string && var2)
{
  //avoid unnecessary copy!
  m_var1 = std::move(var1);  
  m_var2 = std::move(var2);
  cout << "call rvale" << endl;
}

string m_var1, m_var2;
};

class B : public A
{
    public:
    B() = default;
};


int main()
{

    vector<int > vec = {1,2,3,4};
    int a = *vec.begin();
    int b = vec.front();
    auto c = vec.end();
    b = *(--c);

   
A a1;
//temporary, move! no copy!
string a11 = "temporary str1";
string a2 = "temporary str2";

a1.set( std::forward<string> (a11), std::forward<string>(a2));
a1.set("temporary str1","temporary str2");

cout << "after = "  << a11 << " " << a2 << endl;


B *bb = dynamic_cast<B*>(&a1);
cout << "bb is " << bb << endl;
bb->job();

const string ss = "ddd";
string* ss1 = const_cast<string*>(&ss);
*ss1 = "ad";

cout << "ss = " << ss << endl;



    return 0;
}