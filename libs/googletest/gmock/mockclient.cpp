#include "mockclient.h"

#include "../contactclient/contactclient.h"
namespace
{
MockClient *m_mock;
}

MockClient::MockClient() 
{
    m_mock = this;
}

void initContact()
{
    m_mock->initContact();
}

void* get10Contact() 
{
	return m_mock->get10Contact();
}


void get11Contact(Abc &cc) 
{
	return m_mock->get11Contact(cc);

}
void get12Contact(Abc *c) 
{
	return m_mock->get12Contact(c);

}
void get13Contact(Contact *c) 
{
	m_mock->get13Contact(c);

}

//TEST_F(MockClient, TestFuncd) //此时使用的是TEST_F宏
//{
 //  EXPECT_EQ(1,1);
//}Jennifer-cao

