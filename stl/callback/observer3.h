#pragma once

#include <string>

class Observer3
{
public:
    Observer3();
    void notified(const std::string &msg);
protected:
    std::string m_name;

private:
    int m_value;
};