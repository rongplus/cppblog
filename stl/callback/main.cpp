
#include <iostream>

#include "observer1.h"
#include "observer2.h"
#include "observer3.h"
#include "observer4.h"
#include "observer5.h"

#include "incomecenter.h"

using namespace std;

struct Foo {
  int value;
  void f() { std::cout << "f(" << this->value << ")\n"; }
  void g() { std::cout << "g(" << this->value << ")\n"; }
};
void apply(Foo *foo1, Foo *foo2, void (Foo::*fun33)()) {
  (foo1->*fun33)(); // call fun on the object foo1
  (foo2->*fun33)(); // call fun on the object foo2
}
bool printMsg(const string &msg) {
  cout << "Call print Msg - " << msg << endl;
  return true;
}

int main() {
  cout << "Test started---" << endl;

  IncomeCenter ct;
  Observer1 o1("test1", 9); // = new Observer1();

  string mss = "From Main";

  OBCallBack f1 =
      std::bind(&Observer1::notified, ref(o1), std::placeholders::_1);

  ct.addObserverCallBack(&f1); // todo pass msg
  //{
  Observer4 o4;
  // = new Observer4();
  OBCallBack f = std::bind(&Observer4::notified, o4, std::placeholders::_1);
  ct.addObserverCallBack(&f); // todo pass msg
  // delete o4;
  //}
  {
    Observer1 o11("test2", 10);
    OBCallBack f2 = std::bind(&Observer1::notified, o11, std::placeholders::_1);

    ct.addObserverCallBack(&f2); // todo pass msg
    // delete o11;
  }

  Observer1 o11("test3", 18);
  OBCallBack f3 =
      std::bind(&Observer1::notified, ref(o11), std::placeholders::_1);

  ct.addObserverCallBack(&f3); // todo pass msg

  auto calld = std::mem_fn(&Observer5::notified);
  // calld(o5, mss);
  ct.notifyAll();
  ct.notifyAll(mss);

  mss = "Another Main message - ";

  ct.notifyAll(std::bind(&Observer1::notified, o1, std::placeholders::_1), mss);

  ct.removeObserverCallBack(&f1);

  return 0;
}