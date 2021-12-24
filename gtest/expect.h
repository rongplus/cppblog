#pragma once

#include <gmock/gmock.h>
//include the google test dependencies
#include <gtest/gtest.h>
#include <map>
using namespace std;


class TestMap : public testing::Test
{
public: //添加日志static
    //void SetUpTestSuite() { cout << "SetUpTestCase" << endl; }
    static void TearDownTestCase() { cout << "TearDownTestCase" << endl; }
    virtual void SetUp() //TEST跑之前会执行SetUp
    {
        cout << "SetUp" << endl;
        test_map.insert(make_pair(1, 0));
        test_map.insert(make_pair(2, 1));
        test_map.insert(make_pair(3, 2));
        test_map.insert(make_pair(4, 3));
        test_map.insert(make_pair(5, 4));
    }
    virtual void TearDown() //TEST跑完之后会执行TearDown
    {
        cout << "TearDown" << endl;
        test_map.clear();
    }
    map<int, int> test_map;
};
