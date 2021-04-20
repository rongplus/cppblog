#pragma once
#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>
#include <string>
#include "../contactclient/contactclient.h"
using namespace std;

class MockClient
{
public:
    MockClient();

    MOCK_METHOD(void ,initContact,());
};
