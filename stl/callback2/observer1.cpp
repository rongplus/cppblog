#include "observer1.h"

#include <iostream>

Observer1::Observer1() {
  std::cout << "Observer 1 - created" << std::endl;
  m_name = "oo1";
}
Observer1::~Observer1() { std::cout << "Observer 1 - delete" << std::endl; }
Observer1::Observer1(const Observer1 &ob) {
  m_name = ob.m_name;
  std::cout << "Observer 1 - copy" << std::endl;
}

void Observer1::notified(const std::string &msg) {
  std::cout << "Observer 1 - "
            << "Got message " << msg << " this= " << m_name << std::endl;
}
