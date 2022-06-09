#include "observer4.h"
#include <iostream>
Observer4::Observer4() {
  std::cout << "Observer 4 - created" << std::endl;
  m_name = "oo4";
}
Observer4::~Observer4() { std::cout << "Observer 4 - delete" << std::endl; }
void Observer4::notified(const std::string &msg) {
  std::cout << "Observer 4 - "
            << "Got message " << msg << "-this=" << m_name << std::endl;
}
