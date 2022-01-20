

#include <iostream>
#include <vcruntime_typeinfo.h>

void function2(const char *Var) // 参数指针所指内容为常量
{
  char aa[8];
  Var = aa;
  // *Var = aa[0];
}
void function3(char *const Var) // 参数指针为常量
{
  char aa[8];
  // Var = aa;
  *Var = aa[0];
}

class Abc {
public:
  Abc() {}

private:
  ~Abc() {}
};

void test() {
  int i = 1;
  printf("%d,%d\n", ++i, ++i); // 3,3
  printf("%d,%d\n", ++i, i++); // 5,3
  printf("%d,%d\n", i++, i++); // 6,5
  printf("%d,%d\n", i++, ++i); // 8,9
}

template <typename T>
void f(T) /* a */
{
  std::cout << "a" << std::endl;
}

template <typename T>
void f(T *) /* b */
{
  std::cout << "b" << std::endl;
}

template <>
void f<int>(int *) /* c */
{
  std::cout << "c" << std::endl;
}
#define SQR(X) X *X

int maindd() {
  int a = 10;
  int k = 2;
  int m = 1;

  a /= SQR(k + m) / SQR(k + m);
  printf("%d/n", a);

  return 0;
}
int main() {
  // Abc abc;
  Abc *aa = new Abc();
  // delete aa;
  Abc *dd = new Abc();
  auto b = typeid(aa) == typeid(Abc);
  auto bbbb = typeid(aa).name();
  // type_info(*aa);

  int i = 0x12345678;

  if (*((char *)&i) == 0x12)
    std::cout << "big" << std::endl;
  else
    std::cout << "small" << std::endl;

  std::cout << i << std::endl;

  char *a = (char *)(&i);

  std::cout << (int)a[0] << "-" << (int)a[1] << "-" << (int)a[2] << "-"
            << (int)a[3] << std::endl;

  test();

  int *p;
  f(p);
  maindd();
  return 0;
}