#include <iostream>

template <typename T> class MyTemp1 {
private:
  /* data */
public:
  MyTemp1(/* args */);
  ~MyTemp1();
};

template <typename T> MyTemp1<T>::MyTemp1(/* args */) {}
template <typename T> MyTemp1<T>::~MyTemp1() {}