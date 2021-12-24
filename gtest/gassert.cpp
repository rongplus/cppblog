#include "gassert.h"

int divide(int dividend, int divisor)
{
    if (!divisor)
    {
        throw std::length_error("can't be divided by 0"); // 故意的
    }
    return dividend / divisor;
}


 MOCK_METHOD1(Do1, void(const string &));

TEST(Divide, ByZero)
{
    EXPECT_NO_THROW(divide(-1, 2));

    EXPECT_ANY_THROW({
        int k = 0;
        divide(k, k);
    });

    EXPECT_THROW(divide(100000, 0), std::invalid_argument);
}