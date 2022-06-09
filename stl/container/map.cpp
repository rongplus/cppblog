#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
  map<int, string> m;
  m[1] = "a";
  m[10] = "b";

  cout << m[0] << endl;
  map<string, string> m2;
  m2["a"] = "abc";
  m2["b"] = "bbc";

  cout << m2["a"] << endl;
  cout << "---- no sort -------" << endl;

  for (auto it = m2.begin(); it != m2.end(); ++it) {
    cout << it->first << "-" << it->second << endl;
  }

  for (auto &it : m2)
    cout << it.first << "=" << it.second << endl;

  auto it = m2.find("a");
  if (it != m2.end())
    cout << "found" << endl;
  else
    cout << "no a" << endl;

  return 0;
}