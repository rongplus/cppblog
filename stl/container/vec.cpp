#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> vec;
    vec.push_back(0);

    map<int,string> m;
    m[1] = "a";
    m[10] = "b";

    cout << m[0] << endl;
    map<string,string> m2;
    m2["a"] = "abc";
    m2["b"] = "bbc";

    cout << m2["a"] << endl;
    cout << "---- no sort -------" << endl;

    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(8);

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << "----  sort -------" << endl;

    //vec.sort();
    std::sort(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;
    }

    for (int &v: vec)
    {
        cout << v;
    }

    return 0;
}