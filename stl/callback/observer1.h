#pragma once

#include <string>

class Observer1
{
public:
    Observer1();
    void notified(const std::string &msg);
protected:
    std::string m_name;

private:
    int m_value;
};