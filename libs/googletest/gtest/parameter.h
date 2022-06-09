#pragma once

#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>


//值参数化测试
inline unsigned NaiveAddUpTo(unsigned n)
{
    unsigned sum = 0;
    for (unsigned i = 1; i <= n; ++i)
        sum += i;
    return sum;
}

inline unsigned FastAddUpTo(unsigned n)
{
    return n * (n + 1) / 2;
}
class AddUpToTest : public testing::TestWithParam<unsigned>
{
public:
    AddUpToTest() { n_ = GetParam(); }

protected:
    unsigned n_;
};
