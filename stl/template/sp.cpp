#include <functional>
#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2> //声明的模板参数个数为2个
class Operator                      //正常的类模板
{
public:
  void add(T1 a, T2 b) {
    cout << a + b << endl;
    cout << "" << __LINE__ << endl;
  }
};

template <> //不需要指定模板类型,因为是完全特化的类模板
class Operator<int, int> //指定类型参数,必须为2个参数,和正常类模板参数个数一致

{

public:
  void add(int a, int b)

  {
    cout << "" << __LINE__ << endl;
    cout << a + b << endl;
  }

  friend ostream &operator<<(ostream &os, const Operator<int, int> &pt) {
    os << "( "
       << " )";
    return os;
  };
  friend istream &operator>>(istream &os, Operator<int, int> &) {
    int x;
    os >> x;
    return os;
  }
};

void printUserFunc(std::function<int(int, int, int)> func, int a, int b,
                   int c) {
  func(a, b, c);
}
int realFun(int x, int y, int z) {
  cout << x << " " << y << " " << z << endl;
  return 10;
}

template <typename Func> void printUserFunc1(Func func, int a, int b, int c) {
  func(a, b, c);
}

int main()

{

  Operator<int, int> Op1; //匹配完全特化类模板:class Operator< int,int>

  Operator<int, float> Op2; //匹配正常的类模板

  cout << Op1;
  Op1.add(1, 2);
  Op2.add(1, 2);

  printUserFunc(realFun, 10, 20, 30);
  printUserFunc1(realFun, 10, 20, 20);

  return 0;
}