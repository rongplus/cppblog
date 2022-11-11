#include <iostream>
#include <map>
#include <string>
#include <tuple>

using namespace std;

struct NonCopyable {
  NonCopyable(int a, char b) {} // Dummy
  NonCopyable(const NonCopyable &) = delete;
  NonCopyable &operator=(const NonCopyable &) = delete;
};

struct UsesNonCopyable {
  UsesNonCopyable(const NonCopyable &) {}
  UsesNonCopyable(const UsesNonCopyable &) = delete;
  UsesNonCopyable &operator=(const UsesNonCopyable &) = delete;
};

int main() {
  map<int, UsesNonCopyable> m;
  int ll;
  m.emplace(std::piecewise_construct, std::forward_as_tuple(10),
            std::forward_as_tuple(NonCopyable{10, 'a'}));

  return 0;
}