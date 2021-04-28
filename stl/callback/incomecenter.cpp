#include "incomecenter.h"
IncomeCenter::IncomeCenter() 
{
    
}

void IncomeCenter::addObserverCallBack(OBCallBack cb) 
{
    m_ltCallBack.push_back(cb);
}

void IncomeCenter::removeObserverCallBack(OBCallBack cb) 
{
    
}

void IncomeCenter::notifyAll() 
{
    std::string msg = "say hello form center";
    for (auto cb: m_ltCallBack)
    {
        cb(msg);
    }
}

void IncomeCenter::notifyAll(std::string& msg) 
{
    for (auto cb: m_ltCallBack)
    {
        cb(msg);
    }
}

void IncomeCenter::notifyAll(OBCallBack cb, const std::string& msg) 
{
    cb(msg);
}

void IncomeCenter::add(FuncP c) 
{
    m_ltFuncs.push_back(c);
   ff = c;
   std::string msd = "from call";
ff(msd);
for (auto cb: m_ltFuncs)
    {
        cb(msd);
    }
}

