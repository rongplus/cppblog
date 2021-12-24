// CPP program to illustrate
// difference b/w std::remove
// and std::vector::erase algorithm

#include <iostream>
#include <assert.h>
#include <memory>
#include <math.h>
#include <bitset>
#include <vector>
#include <list>
using namespace std;

int main()
{
    std::list<int> vec{10, 20, 30, 30, 20, 10, 10, 20};
    std::list<int>  ve{10, 20, 30, 30, 20, 10, 10, 20};

    // Print original vector
    std::cout << "Original vector :";
    for (int n: vec)
        std::cout << " " << n;
    std::cout << " size = " << vec.size() << "\n";

    // Iterator that store the position of last element
    std::list<int>::iterator pend;

    // std :: remove function call
    vec.remove(20);

    // Print the vector after std :: remove
    std::cout << "Range contains:";
    for (int n: vec)
        std::cout << ' ' << n;
    std::cout << " size = " << vec.size() << "\n";

    // Print original vector
    std::cout << "Original Vector :";
    for (int n :ve)
        std::cout << " " << n;
    std::cout <<" size = " << ve.size() <<  "\n";

    // std :: vector :: erase function call
    // erase the first 3 elements of vector vector
    auto it = ve.begin();
    it++;
    ++it;
    ++it;
    ve.erase(ve.begin(), it);

    // Print the vector
    std::cout << "Vector contains :";
    for (int i : ve)
        std::cout << " " <<i;
    std::cout << " size = " << ve.size() << "\n";

    for (auto it = ve.begin(); it!=ve.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
