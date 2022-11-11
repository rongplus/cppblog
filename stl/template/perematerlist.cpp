
#include <iostream>

using namespace std;

template <typename T> void printPP(const T &t) { std::cout << t << ", "; }

template <typename T, typename... Args>
void printPP(const T &t, const Args &...rest) {
  std::cout << t << ", ";

  printPP(rest...);
}

int main() {
  printPP(1, 2, "haha"); //"1, 2, haha"
  return 0;
}