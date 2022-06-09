
const int v = 4;
#include <iostream>
bool isBadVersion(int n) { return n >= v; }

class Solution {
public:
  int firstBadVersion(int n) {
    int s = 0, e = n, m = n / 2;
    std::cout << "1 (s,m,e) = (" << s << "," << m << "," << e << ")"
              << std::endl;
    while (s < e) {
      if (!isBadVersion(m)) {
        s = m + 1;
      } else {
        e = m - 1;
      }
      m = (e + s) / 2;
      std::cout << "2 (s,m,e) = (" << s << "," << m << "," << e << ")"
                << std::endl;
    }
    return s + 1;
  }
};

int main() {
  Solution s;
  std::cout << s.firstBadVersion(5) << std::endl;
  return 0;
}