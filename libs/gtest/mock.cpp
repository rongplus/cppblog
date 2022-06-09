#include "mock.h"

using ::testing::_;
using ::testing::Return;



TEST(demo, 1)
{
    MockParent p;
    Target t(&p);

    //! 设置 p.getNum() 方法的形为
    EXPECT_CALL(p, getNum())
        .Times(2)              //! 期望被调两次
        .WillOnce(Return(2))   //! 第一次返回值为2
        .WillOnce(Return(10)); //! 第二次返回值为10

    //! 设置 p.setResult(), 参数为2的调用形为
    EXPECT_CALL(p, setResult(2))
        .Times(1);

    EXPECT_CALL(p, print(_)) //! 表示任意的参数，其中 _ 就是 ::testing::_ ，如果冲突要注意
        .Times(2);

    EXPECT_EQ(t.doThis(), 10);
}

TEST(demo, 2)
{
    MockParent p;
    Target t(&p);

    EXPECT_CALL(p, calc(1, 2.2))
        .Times(1)
        .WillOnce(Return(3));

    EXPECT_EQ(t.doThat(), 3);
}