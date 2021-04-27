#ifndef __INCOMECENTER_H__
#define __INCOMECENTER_H__
#include <string>
#include <functional>
#include <vector>

using OBCallBack = std::function<void(const std::string&)>;
class IncomeCenter
{
public:
    IncomeCenter();
    void addObserverCallBack(OBCallBack cb);
    void removeObserverCallBack(OBCallBack cb);

    void notifyAll();
    void notifyAll(std::string& msg);
private:
    std::vector<OBCallBack> m_ltCallBack;
};

#endif // __INCOMECENTER_H__