#include <cinttypes>
#include <iostream>


#include <bits/stdc++.h>

using namespace std;
// locale loc("chs");
int main() {
  wchar_t wStr[] = L"我使用了wcha_t类型";
  // wcout.imbue(loc);
  wcout << wStr << endl;
  int a = 10;

  auto fun1 = [=](int b) { cout << "a=" << a << " b= " << b << endl; };
  auto fun2 = [&](int b) { cout << "a=" << a << " b= " << b << endl; };

  a = 30;
  fun1(a);
  fun2(a);

  std::printf("%zu\n", sizeof(std::int64_t));
  std::printf("%s\n", PRId64);
  std::printf("%+" PRId64 "\n", INT64_MIN);
  std::printf("%+" PRId64 "\n", INT64_MAX);

  std::int64_t n = 7;
  std::printf("%+" PRId64 "\n", n);

  std::printf("uint8 %+" PRId64 "\n", UINT8_MAX);

  int n = 0;
  switch (n) {
  case 1: {
  }
  /* code */
  break;

  default:
    break;
  }

  return 0;
}