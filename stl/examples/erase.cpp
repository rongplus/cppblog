#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
    //vector遍历删除
    std::vector<int> v(8);
    std::generate(v.begin(), v.end(), std::rand);
    std::cout << "after vector generate...\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));

    for (auto x = v.begin(); x != v.end(); )
    {
        if (*x % 2)
            x = v.erase(x);
        else
            ++x;
    }

    std::cout << "after vector erase...\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));

    //map遍历删除
    std::map<int, int> m = {{1,2}, {8,4}, {5,6}, {6,7}};

    for (auto x = m.begin(); x != m.end(); )
    {
        if (x->first % 2)
            m.erase(x++);
        else
            ++x;
    }

    for (auto &v:m)
    {
        std::cout << v.first << " " << v.second << std::endl;
    }

     wchar_t *pi  = L"北京adas，你好！";
  std::wcout << pi <<std::endl;

    return 0;
}