#pragma once

#include <string>

class Observer5
{
public:
    Observer5();
    void notified(const std::string &msg);
protected:
    std::string m_name;

private:
    int m_value;
};