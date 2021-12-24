#include "test_pub.h"
#include "../myinc.h"
int get_age()
{
    std::cout << "Call " << __func__ << endl;
    return 12;
}

TEST_F(GTestPub, TestFunction) //此时使用的是TEST_F宏
{
    MOCKER(get_age)
        .will(testing::Return(8));
    int nn = pub->doSomeThing();
    EXPECT_EQ(nn, 14);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}