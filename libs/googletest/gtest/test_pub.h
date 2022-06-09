#pragma once

#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>


int get_age();

class TestPub
{
public:
    TestPub() = default;

    int doSomeThing()
    {
        return get_age()+ 10;
    }
};

class GTestPub : public testing::Test
{
public:
    GTestPub()
    {
        // EXPECT_CALL(pub, doSomeThing())
        // .Times(2)              //! 期望被调两次
        // .WillOnce(testing::Return(2))   //! 第一次返回值为2
        // .WillOnce(testing::Return(10)); //! 第二次返回值为10;
        // .WillOnce( InvokeWithoutArgs([]{ do something ; testing::Return(10);})); //! 第二次返回值为10;
    }

    MOCK_METHOD0(get_age, int());

    TestPub* pub = new TestPub();

};

