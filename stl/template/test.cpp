#include <iostream>
#include <type_traits>

class A {
public:
  A() = default;
};

int main() {
  A *a = new A();
  std::cout << (typeid(*a) == typeid(A)) << std::endl;
  // std::cout << type_info(a);
}