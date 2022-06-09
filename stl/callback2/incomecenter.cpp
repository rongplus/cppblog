#include "incomecenter.h"
#include <iostream>
IncomeCenter::IncomeCenter() {}

void IncomeCenter::addObserverCallBack(OBCallBack cb) {
  m_ltCallBack.push_back(cb);
}

void IncomeCenter::removeObserverCallBack(OBCallBack cb) {
  auto it = std::find(m_ltCallBack.begin(), m_ltCallBack.end(), cb);
  // auto it = std::find(m_ltFuncs.begin(), m_ltFuncs.end(), nullptr);
  //   if (it != m_ltCallBack.end())
  //     m_ltCallBack.erase(it);
  //   std::cout << "remove one" << std::endl;
}

void IncomeCenter::addObserverFun(FuncP cb) { m_ltFuncs.push_back(cb); }
void IncomeCenter::removeObserverFun(FuncP cb) {
  auto it = std::find(m_ltFuncs.begin(), m_ltFuncs.end(), nullptr);
  if (it != m_ltFuncs.end())
    m_ltFuncs.erase(it);
  std::cout << "remove one" << std::endl;
}

void IncomeCenter::notifyAll() {
  std::string msg = "say hello form center";
  for (auto cb : m_ltCallBack) {
    cb(msg);
  }
}

void IncomeCenter::notifyAll(std::string &msg) {
  for (auto cb : m_ltCallBack) {
    cb(msg);
  }

  for (auto cb : m_ltFuncs) {
    cb(msg);
  }
}

void IncomeCenter::notifyAll(OBCallBack cb, const std::string &msg) { cb(msg); }

void IncomeCenter::add(FuncP c) {
  m_ltFuncs.push_back(c);
  ff = c;
  std::string msd = "from call";
  ff(msd);
  for (auto cb : m_ltFuncs) {
    cb(msd);
  }
}
