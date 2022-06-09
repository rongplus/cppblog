#include "parameter.h"

TEST_P(AddUpToTest, Calibration)
{
    EXPECT_EQ(NaiveAddUpTo(n_), FastAddUpTo(n_));
}

INSTANTIATE_TEST_CASE_P(
    hhhhhh,                // prefix
    AddUpToTest,           // test case name
    testing::Range(1u, 3u) // parameters
);