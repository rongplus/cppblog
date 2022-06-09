#include <iostream>
#include <string>
using namespace std;
// 1、没有使用模板的时候友元函数的调用
namespace U1 {

class People {
private:
  int age;

public:
  People(){};
  People(int a) { age = a; };
  void print();
  friend void friendPrint(const People &cn_p);
};
void friendPrint(const People &cn_p) { cout << cn_p.age << endl; }
int main() {
  People p(12);
  friendPrint(p);

  return 0;
}
} // namespace U1
/*
2、友元函数参数中不带模板的情况**；
则是在类模板中声明该类的友元函数，
但是却指定明确的类模板参数类型，
这种情况其实相当于削弱了类模板参数的模板化

*/

namespace U2 {

template <typename T> class People {
private:
  T age;

public:
  People(){};
  People(T a) { age = a; };
  void print();

  //这种使用友元函数的情况实际是削弱了模板参数在使用
  //因为把传参T可以表示任何类型的在这种友元函数这里写死成固定类型了，其他类型就不兼容了
  //在任何使用使用类模板的时候都要用<>指定参数类型
  //并且这里可以根据传参的类型从而参数类型不同可以进行函数重载
  friend void friendPrint(const People<string> &cn_p);
  friend void friendPrint(const People<double> &cn_p);
};
//在任何使用使用类模板的时候都要用<>指定参数类型
void friendPrint(const People<string> &cn_p) { cout << cn_p.age << endl; }
void friendPrint(const People<double> &cn_p) { cout << cn_p.age << endl; }

int main() {
  //改用传string 则p的age是string形式表示
  People<string> p("1s3");
  friendPrint(p);
  People<double> p1(12.3);
  friendPrint(p1);

  return 0;
}

} // namespace U2
/*
3、友元函数参数中带模板参数但是其友元函数的声明定义都在类模板内部
这种情况该友元函数可以适配任何模板参数了。
注意；该函数仍然是友元函数而不是成员函数，仍属于外部函数，因此使用的时候也要<>指定参数类型

*/

namespace U3 {

template <typename T> class People {
private:
  T age;

public:
  People(){};
  People(T a) { age = a; };
  void print();

  //友元函数在内部实现也要用<>指定，但是可以继续沿用T模板参数类型表示
  //在类模板外部的任何情况都要加，友元函数不是类的成员函数，是外部的，则也要加<>指定的
  friend void friendPrint(const People<T> &cn_p) { cout << cn_p.age << endl; }
};
int main() {
  //改用传string 则p的age是string形式表示
  People<string> p("1s3");
  friendPrint(p);
  People<double> p1(12.3);
  friendPrint(p1);

  return 0;
}
} // namespace U3

/*
4、友元函数参数中带模板参数并且该友元函数在类模板内部声明，外部定义
需注意几点
**声明时函数名加<T>后缀，而定义时不用加、**
需要class和friend function的2个前置声明、
调用friend function时可加<实参类型>后缀，也可以不加，但是加就必须加对了。

//因为下面友元函数的声明用到了这个类，则也需要类模板声明
template <typename T> class People;
//因为都为模板类型，则编译器编译的时候需要提前声明
template <typename T> void friendPrint(const People<T> &cn_p);

*/
template <typename T> class People {
private:
  T age;

public:
  People(){};
  People(T a) { age = a; };
  void print();

  //友元函数在内部实现也要用<>指定，但是可以继续沿用T模板参数类型表示
  //在类模板外部的任何情况都要加，友元函数不是类的成员函数，是外部的，则也要加<>指定的
  friend void friendPrint<T>(const People<T> &cn_p);
};
template <typename T> void friendPrint(const People<T> &cn_p) {
  cout << cn_p.age << endl;
}
int main() {
  //改用传string 则p的age是string形式表示
  People<string> p("1s3");
  friendPrint(p);
  People<double> p1(12.3);
  friendPrint(p1);

  return 0;
}

namespace U5 {
#include <iostream>
#include <string>

using namespace std;

template <typename T> class People {
public:
  T age;
  People(){};
  People(T a) { age = a; };

  //在内部成员函数在使用类模板的时候也是需要<>指定类型的
  People<T> operator+(const People<T> &rightPeo);
};
//在外部使用类模板类的时候如果还没有确定类型，
//则需要template再次使用typename来暂时代替参数类型
template <typename T>
People<T> People<T>::operator+(const People<T> &rightPeo) {
  this->age += rightPeo.age;
  return *this;
}

int main() {
  People<int> p1(12);
  People<int> p2(12);
  People<int> p3;
  p3 = p1 + p2;
  cout << p3.age << endl;

  return 0;
}

} // namespace U5