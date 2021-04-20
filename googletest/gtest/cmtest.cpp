#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../contactclient/contactmanager.h"

using namespace testing;
using namespace std;

class TestCM : public Test
{
public:
    TestCM() { cout << "TestContact Created" << endl;}
    virtual void SetUp() override
    {
        m_cm = new ContactManager();
        m_names = { "Jack", "Mick","Jons"};
        for (auto s: m_names)
        {
            Contact ct(s);
            m_cm->addContact(ct);
        }

       
    }

    virtual void TearDown() override
    {
        delete m_cm;
    }

    ContactManager* m_cm = nullptr;
    vector<string> m_names;

};

TEST_F(TestCM, ConstructorTest) //此时使用的是TEST_F宏
{
    int index = 0;
    for (auto it = m_cm->getContacts().begin(); it != m_cm->getContacts().end(); ++it)
    {
        EXPECT_THAT( ((it))->name(),Eq( m_names[index++]));
    }

  

}


class CMParameterTest : public testing::TestWithParam<const char*>
{
public:
    CMParameterTest() { 
        name = GetParam(); 
        Contact ct(name);
            m_cm->addContact(ct);
        }

protected:
    string name;
    ContactManager* m_cm = new ContactManager();
};


TEST_P(CMParameterTest, Calibration)
{
    auto con = *(m_cm->getContacts().begin());
    EXPECT_EQ(  con.name(), name);
}

INSTANTIATE_TEST_CASE_P(
    hhhhhh,                // prefix
    CMParameterTest,           // test case name
    //testing::Range(1u, 3u) // parameters
    ::testing::Values("meeny", "miny", "moe")
);

INSTANTIATE_TEST_CASE_P(
    gggg,                // prefix
    CMParameterTest,           // test case name
    //testing::Range(1u, 3u) // parameters
    ::testing::Values("meeny1", "miny1", "moe1")
);




class CMParameterTest1 : public testing::TestWithParam<  vector<string>  >
{
public:
    CMParameterTest1() { 
        names = GetParam(); 
        for (auto s: names)
        {
            Contact ct(s);
            m_cm->addContact(ct);
        }
        
        }

protected:
    vector<string>  names;
    ContactManager* m_cm = new ContactManager();
};


TEST_P(CMParameterTest1, Calibration)
{
    auto all = m_cm->getContacts();
    auto c1 = all.begin();
    c1++;
    auto con = *(c1);
    EXPECT_EQ( all.size(), names.size());
    EXPECT_EQ(  con.name(), names[1]) << con.name() << names[1];
}


INSTANTIATE_TEST_CASE_P(
    
    gggg,                // prefix
    CMParameterTest1,           // test case name
    //testing::Range(1u, 3u) // parameters
    ::testing::Values( vector<string>   { "abc","dde","vachan"},
    vector<string>   { "hello","World","vachan"},
    vector<string>   { "test ","me","vachan"})
);