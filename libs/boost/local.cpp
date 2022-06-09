#include <iostream>
#include <locale>

int main() {
  std::locale::global(std::locale("German"));
  std::locale loc;
  std::cout << loc.name() << std::endl;
}