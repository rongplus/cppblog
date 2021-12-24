#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>
#include <map>
#include "expect.h"
#include "gassert.h"
#include "mock.h"
#include "parameter.h"

using namespace std;

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}