#ifndef __INCOMECENTER_H__
#define __INCOMECENTER_H__
#include <functional>
#include <string>
#include <vector>

using OBCallBack = std::function<void(const std::string &)>;
typedef bool (*FuncP)(const std::string &);

class IncomeCenter {
public:
  IncomeCenter();
  void addObserverCallBack(OBCallBack cb);
  void removeObserverCallBack(OBCallBack cb);

  void addObserverFun(FuncP cb);
  void removeObserverFun(FuncP cb);

  void notifyAll();
  void notifyAll(std::string &msg);
  void notifyAll(OBCallBack cb, const std::string &msg);

  void add(FuncP c);

private:
  std::vector<OBCallBack> m_ltCallBack;
  std::vector<FuncP> m_ltFuncs;
  FuncP ff;
};

#endif // __INCOMECENTER_H__