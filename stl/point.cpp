
#include <iostream>

void fun(int *&q) // q是指针变量ptr的引用
{
  int *x = new int(10);
  q = x; // q指向&x,因为q既是ptr,故ptr也指向&x
}

void fun2(int **q) {
  int x = 10;
  *q = &x; // q指向&x,因为q既是ptr,故ptr也指向&x
}

int main() {
  {
    int *p = nullptr;
    fun(p);
    std::cout << *p << std::endl;
  }
  {
    int *p = nullptr;
    fun2(&p);
    std::cout << *p << std::endl;
  }
}