#include <atomic>
#include <iostream>
#include <memory.h>

int main() {

  std::atomic<int> p;
  int *q = new int(10);

  std::atomic_store_explicit(&p, *q, std::memory_order_release);
  std::cout << p << std::endl;
  return 0;
}