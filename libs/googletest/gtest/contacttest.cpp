#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../contactclient/contact.h"

using namespace testing;
using namespace std;

class TestContact : public Test
{
public:
    TestContact() { cout << "TestContact Created" << endl;}
    virtual void SetUp() override
    {

    }

    virtual void TearDown() override
    {

    }

    Contact* m_contact = nullptr;

};

TEST_F(TestContact, ConstructorTest) //此时使用的是TEST_F宏
{
    string name = "Jakc";
    string gender = "girl"; 
    list<string> phones;
    list<string> addresses;
   m_contact = new Contact(name);
   EXPECT_THAT( m_contact->name(),Eq(name));
   EXPECT_THAT( m_contact->gender(), Eq("man"));
   EXPECT_THAT( m_contact->phones(), Eq(phones));
   EXPECT_THAT( m_contact->addresses(), Eq(addresses));

}