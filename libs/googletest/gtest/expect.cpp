#include "expect.h"

TEST_F(TestMap, Find) //此时使用的是TEST_F宏
{
    map<int, int>::iterator it = test_map.find(1);
    ASSERT_NE(it, test_map.end());
}
TEST_F(TestMap, Size) { ASSERT_EQ(test_map.size(), 5); }