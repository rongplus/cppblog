#pragma once

#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>
#include <string>

using namespace std;

class Parent
{
public:
    virtual ~Parent() {}

    virtual int getNum() const = 0;
    virtual void setResult(int value) = 0;
    virtual void print(const string &str) = 0;
    virtual int calc(int a, double b) = 0;
};

class Target
{
public:
    Target(Parent *parent) : parent_(parent)
    {
    }

    int doThis()
    {
        int v = parent_->getNum();
        parent_->setResult(v);
        while (v-- > 0)
        {
            parent_->print(to_string(v));
        }
        return parent_->getNum();
    }

    int doThat()
    {
        return parent_->calc(1, 2.2);
    }

private:
    Parent *parent_;
};

class MockParent : public Parent
{
public:
    //! MOCK_[CONST_]METHODx(方法名, 返回类型(参数类型列表));
    MOCK_CONST_METHOD0(getNum, int()); //! 由于 getNum() 是 const 成员函数，所以要使用 MOCK_CONST_METHODx
    MOCK_METHOD1(setResult, void(int));
    MOCK_METHOD1(print, void(const string &));
    MOCK_METHOD2(calc, int(int, double));
};