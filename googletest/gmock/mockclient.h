#pragma once
#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>
#include <string>
#include "../contactclient/contactclient.h"
#include "../contactclient/contact.h"
using namespace std;

class MockClient
{
public:
    MockClient();

    MOCK_METHOD(void ,initContact,());
    MOCK_METHOD(void* ,get10Contact,());
    MOCK_METHOD(void ,get11Contact,(Abc &cc));
    MOCK_METHOD(void ,get12Contact,(Abc *cc));
    MOCK_METHOD(void ,get13Contact,(Contact *cc));
};
