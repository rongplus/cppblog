#include "observer1.h"

#include <iostream>

Observer1::Observer1(std::string str, int n) {
  std::cout << "Observer " << str << " - created" << std::endl;
  m_name = str;
  m_pValue = new int(n);
}
Observer1::~Observer1() {
  std::cout << "Observer " << m_name << " - deleted" << std::endl;
}
Observer1::Observer1(const Observer1 &ob) {
  m_name = ob.m_name;
  std::cout << "Observer 1 - copy" << std::endl;
}

void Observer1::notified(const std::string &msg) {
  std::cout << "Observer 1 - " << m_name << " Got message " << msg
            << " this= " << m_name << " value " << *m_pValue << std::endl;
}
