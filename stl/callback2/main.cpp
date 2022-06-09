
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
  Observer1 *o1 = new Observer1();

  string mss = "From Main";
  ct.addObserverCallBack(std::bind(&Observer1::notified, o1,
                                   std::placeholders::_1)); // todo pass msg

  Observer2 o2;
  Observer3 o3;
  Observer5 o5;

  OBCallBack f1 =
      std::bind(&Observer2::notified, ref(o2), std::placeholders::_1);

  ct.addObserverCallBack(f1); // todo pass msg
  ct.addObserverCallBack(std::bind(&Observer3::notified, o3,
                                   std::placeholders::_1)); // todo pass msg
  ct.addObserverCallBack(std::bind(&Observer5::notified, o5,
                                   std::placeholders::_1)); // todo pass msg
  {
    Observer4 *o4 = new Observer4();
    ct.addObserverCallBack(std::bind(&Observer4::notified, o4,
                                     std::placeholders::_1)); // todo pass msg
    delete o4;
  }
  ct.add(&printMsg);
  // ct.addObserverFun((o2.notified)); // todo add more functions
  // ct.addObserverCallBack(  std::mem_fn(&Observer3::notified) );
  // ct.addObserverCallBack(o4.notified);
  // ct.addObserverCallBack(o5.notified);
  // ct.addObserverCallBack( std::mem_fn(&Observer5::notified)); //todo
  auto calld = std::mem_fn(&Observer5::notified);
  // calld(o5, mss);
  ct.notifyAll();
  ct.notifyAll(mss);
  ct.addObserverCallBack(&printMsg);
  ct.addObserverCallBack(std::bind(&Observer5::notified, o5,
                                   std::placeholders::_1)); // todo pass msg

  ct.removeObserverCallBack(f1);

  mss = "Another Main message - ";

  ct.notifyAll(std::bind(&Observer1::notified, o1, std::placeholders::_1), mss);

  // ct.add(&std::bind(&Observer1::notified,o1,std::placeholders::_1));
  Foo foo1{1};
  Foo foo2{2};
  apply(&foo1, &foo2, &Foo::f);
  apply(&foo1, &foo2, &Foo::g);

  return 0;
}