#include "mockclient.h"
#include "../contactclient/contactmanager.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;
using namespace std;

class TestManager : public Test
{
protected:
    ContactManager m_manager;
    NiceMock<MockClient> m_mock;
};

TEST_F(TestManager, TakeItTest)
{
    Contact ct("Jake");
    EXPECT_CALL(m_mock, get10Contact()).WillOnce(Return(&ct));
    Abc cc;
    EXPECT_CALL(m_mock,get11Contact(_)).WillOnce(DoAll(  SaveArg<0>(&cc),Invoke([&]()
    {
        //pCt->name();
        cc.a = 10;
        Return(0);}
        ))
    );
    Abc* pc = nullptr;
    EXPECT_CALL(m_mock,get12Contact(_)).WillOnce(DoAll(  SaveArg<0>(&pc),Invoke([&]()
    {
        //pCt->name();
        pc->a = 10;
        Return(0);}
        ))
    );


    Contact* pcccccc = nullptr;
    EXPECT_CALL(m_mock,get13Contact(_)).WillOnce(DoAll(  SaveArg<0>(&pcccccc),Invoke([&]()
    {
        //pCt->name();
        pcccccc->setName();
        
        Return(0);}
        ))
    );

    m_manager.init();
    EXPECT_EQ(m_manager.getContacts().size(), 2);
    //EXPECT_THAT(m_manager.getContacts()[0].name(), Eq("Jake"));
}