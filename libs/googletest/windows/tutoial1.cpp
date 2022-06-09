

#include <gmock/gmock.h>
// include the google test dependencies
#include "factory.h"
#include <gtest/gtest.h>
#include <map>

using namespace std;

class TestMap : public testing::Test {
public: //添加日志static
  // void SetUpTestSuite() { cout << "SetUpTestCase" << endl; }
  static void TearDownTestCase() { cout << "TearDownTestCase" << endl; }
  virtual void SetUp() // TEST跑之前会执行SetUp
  {
    cout << "SetUp" << endl;
    test_map.insert(make_pair(1, 0));
    test_map.insert(make_pair(2, 1));
    test_map.insert(make_pair(3, 2));
    test_map.insert(make_pair(4, 3));
    test_map.insert(make_pair(5, 4));
  }
  virtual void TearDown() // TEST跑完之后会执行TearDown
  {
    cout << "TearDown" << endl;
    test_map.clear();
  }
  map<int, int> test_map;
  factory fa;
};

TEST_F(TestMap, Find) //此时使用的是TEST_F宏
{
  map<int, int>::iterator it = test_map.find(1);
  ASSERT_NE(it, test_map.end());
}

TEST_F(TestMap, GetA) //此时使用的是TEST_F宏
{

  EXPECT_EQ(fa.GetA(), 10);
}

TEST_F(TestMap, GetB) //此时使用的是TEST_F宏
{

  EXPECT_EQ(fa.GetB(), 10);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  // testing::InitGoogleTest(&argc, argv);
  // testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

// cl -I D:\3rdLib\googletest\googletest\include -I
// D:\3rdLib\googletest\googlemock\include .\tutoial1.cpp cl -I
// D:\3rdLib\googletest\googletest\include -I
// D:\3rdLib\googletest\googlemock\include .\tutoial1.cpp