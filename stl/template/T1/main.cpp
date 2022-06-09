#include "a.h"
static int abc = 11;

//关于宽字符的使用
#include <iostream>

#include <locale>
#include <stdlib.h>

class A1 {
private:
  /* data */
public:
  A1(/* args */);
  ~A1();

  void Add(int a) { std::cout << "a::add" << std::endl; }
  virtual void Work(int) { std::cout << "a::work" << std::endl; }
  virtual void Work(int, int) { std::cout << "a::work" << std::endl; }
};

A1::A1(/* args */) {}

A1::~A1() {}

class B1 : public A1 {
private:
  /* data */
public:
  B1(/* args */);
  ~B1();
  void Add(int a, int b) { std::cout << "b::add" << std::endl; }
  void Work(int, int) { std::cout << "b::work" << std::endl; }
};

B1::B1(/* args */) {}

B1::~B1() {}

void Foo(int x = 0, int y = 0) {}
int main(int argv, char args[]) {

  setlocale(LC_ALL, "chs"); //这就是设定为本地，中文简体
  wchar_t *p2 = L"1234frd";
  std::wcout << p2 << std::endl;
  wchar_t *pi = L"北京adas，你好！";
  std::wcout << pi << std::endl;

  getchar();
  MyTemp1<int> a;
  std::cout << __func__ << std::endl;

  B1 b;
  b.Add(10, 20);
  b.Work(10);

  return 0;
}