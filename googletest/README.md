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
Output:
```
./a.out 

>[==========] Running 1 test from 1 test suite.
>[----------] Global test environment set-up.
>[----------] 1 test from TestContact
>[ RUN      ] TestContact.ConstructorTest
>TestContact Created
>[       OK ] TestContact.ConstructorTest (0 ms)
>[----------] 1 test from TestContact (0 ms total)

>[----------] Global test environment tear-down
>[==========] 1 test from 1 test suite ran. (0 ms total)
>[  PASSED  ] 1 test.

```
========================================
- [X] c++11
- [X] c++14
- [X] Windows
- [X] MacOS