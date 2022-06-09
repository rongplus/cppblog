
#include <iostream>
#include <string>

using namespace std;

template <typename T> struct counter {
  static int objects_created;
  static int objects_alive;

  counter() {
    ++objects_created;
    ++objects_alive;
    static_cast<T *>(this)->printCount();
  }

  counter(const counter &) {
    ++objects_created;
    ++objects_alive;
  }

protected:
  ~counter() // objects should never be removed through pointers of this type
  {
    --objects_alive;
  }
};
template <typename T> int counter<T>::objects_created(0);
template <typename T> int counter<T>::objects_alive(0);

class X : public counter<X> {
  // ...
public:
  X() {}
  void printCount() {
    std::cout << "X Total(alive,created)= " << objects_alive << ","
              << objects_created << endl;
  }
};

class Y : public counter<Y> {
  // ...
public:
  Y() {}
  void printCount() {
    std::cout << "Y Total(alive,created)= " << objects_alive << ","
              << objects_created << endl;
  }
};

int main() {
  X x;
  // x.printCount();

  Y y;
  // y.printCount();
  X x2;

  Y y2;
  Y y3;

  // x2.printCount();
  // y2.printCount();
}