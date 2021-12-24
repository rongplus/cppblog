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
bool com(const string &s1, const string &s2)
{
    return s1.compare(s2)<0;
}
int main()
{
    list<string> lt;
    lt.push_back("b");
    lt.push_back("b3");
    lt.push_back("b5");
    lt.push_back("b9");
    lt.push_back("b4");
    lt.push_front("a1");

    cout << "----print------" << endl;
    for (auto it = lt.begin(); it != lt.end(); ++it)
    {
        cout << *it << endl;
        *it = "100";
    }

    cout << "---sort -print------" << endl;
    lt.sort(com);

    //sort(lt.begin(), lt.end(),com);
    for (auto it = lt.begin(); it != lt.end(); ++it)
    {
        cout << *it << endl;
    }


cout << "--sort 2 --print------" << endl;
    for (auto &v : lt)
    {
        cout << v << endl;
    }


cout << "--point list" << endl;
    list<int*> lt2;
    lt2.push_back( new int(10));
    lt2.push_back( new int(5));
    int *p1 = new int(19);
    lt2.push_back(p1);
    lt2.sort();
 

    for (auto v : lt2)
    {
        cout << v  << " " << *v<< endl;
    }

    cout  << p1 << endl;


    return 0;
}