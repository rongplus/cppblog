#include "mockclient.h"
namespace
{
MockClient *m_mock;
}

MockClient::MockClient() 
{
    m_mock = this;
}


TEST(TestMapabc, Find) //此时使用的是TEST_F宏
{
    //EXPECT_CALL()
    initContact();
    EXPECT_EQ(1,1);
}

void initContact()
{
    m_mock->initContact();
}
//TEST_F(MockClient, TestFuncd) //此时使用的是TEST_F宏
//{
 //  EXPECT_EQ(1,1);
//}