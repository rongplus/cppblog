#pragma once

#include <string>

class Observer1 {
public:
  Observer1();
  ~Observer1();

  Observer1(const Observer1 &ob);
  void notified(const std::string &msg);

protected:
  std::string m_name;

private:
  int m_value;
};