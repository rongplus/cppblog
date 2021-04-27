=====================================

Using Google Test Framework in daily work.
=====================================

* [Contact Client](contactclient) Code should be tested by Google Unit Test Framework.
* [Contact Server](contactserver) Code should be tested by Google Unit Test Framework.
* [Mock class](gmock) mock class used in google unit test
* [Unit Test](gtest) Unit test cases
* [makefile](makefile) linux makefile
* [Another_makefile](makefile_1) another Linux makefile

=========================================

Unit Test Output:
```
./a.out 

[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TestContact
[ RUN      ] TestContact.ConstructorTest
TestContact Created
[       OK ] TestContact.ConstructorTest (0 ms)
[----------] 1 test from TestContact (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.

```

```
GMock in Unit Test
./test 
[==========] Running 12 tests from 6 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TestContact
[ RUN      ] TestContact.ConstructorTest
TestContact Created
Construct Jakc
[       OK ] TestContact.ConstructorTest (0 ms)
[----------] 1 test from TestContact (0 ms total)

[----------] 1 test from TestCM
[ RUN      ] TestCM.ConstructorTest
TestContact Created
Construct Jack
Construct Mick
Construct Jons
[       OK ] TestCM.ConstructorTest (0 ms)
[----------] 1 test from TestCM (0 ms total)

[----------] 1 test from TestManager
[ RUN      ] TestManager.TakeItTest
Construct Jake
Abc.a = 177996901
Abc.a = 10
contact.name = MockName
[       OK ] TestManager.TakeItTest (0 ms)
[----------] 1 test from TestManager (0 ms total)

[----------] 3 tests from hhhhhh/CMParameterTest
[ RUN      ] hhhhhh/CMParameterTest.Calibration/0
Construct meeny
[       OK ] hhhhhh/CMParameterTest.Calibration/0 (0 ms)
[ RUN      ] hhhhhh/CMParameterTest.Calibration/1
Construct miny
[       OK ] hhhhhh/CMParameterTest.Calibration/1 (0 ms)
[ RUN      ] hhhhhh/CMParameterTest.Calibration/2
Construct moe
[       OK ] hhhhhh/CMParameterTest.Calibration/2 (0 ms)
[----------] 3 tests from hhhhhh/CMParameterTest (0 ms total)

[----------] 3 tests from gggg/CMParameterTest
[ RUN      ] gggg/CMParameterTest.Calibration/0
Construct meeny1
[       OK ] gggg/CMParameterTest.Calibration/0 (0 ms)
[ RUN      ] gggg/CMParameterTest.Calibration/1
Construct miny1
[       OK ] gggg/CMParameterTest.Calibration/1 (0 ms)
[ RUN      ] gggg/CMParameterTest.Calibration/2
Construct moe1
[       OK ] gggg/CMParameterTest.Calibration/2 (0 ms)
[----------] 3 tests from gggg/CMParameterTest (0 ms total)

[----------] 3 tests from gggg/CMParameterTest1
[ RUN      ] gggg/CMParameterTest1.Calibration/0
Construct abc
Construct dde
Construct vachan
[       OK ] gggg/CMParameterTest1.Calibration/0 (0 ms)
[ RUN      ] gggg/CMParameterTest1.Calibration/1
Construct hello
Construct World
Construct vachan
[       OK ] gggg/CMParameterTest1.Calibration/1 (0 ms)
[ RUN      ] gggg/CMParameterTest1.Calibration/2
Construct test 
Construct me
Construct vachan
[       OK ] gggg/CMParameterTest1.Calibration/2 (0 ms)
[----------] 3 tests from gggg/CMParameterTest1 (0 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 6 test suites ran. (1 ms total)
[  PASSED  ] 12 tests.
```
========================================

- [X] c++11
- [X] c++14
- [X] Windows
- [X] MacOS