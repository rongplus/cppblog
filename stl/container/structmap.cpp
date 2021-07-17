#include <iostream>
#include <future>
#include <thread>
#include <chrono>

#include <map>

using namespace std;

struct Point3D
{
    Point3D(int a, int b,int c)
    {
        x= a;
        y= b;
        z = c;
    }
    int x;
    int y;
    int z;
    bool operator< (const Point3D &p) const
    {
        return x < p.x;
    }
};



int main()
{
    map <Point3D, int> pointMap;
    //std::map<char,int> 
    pointMap.insert( make_pair<Point3D,int>( Point3D(1,2,3),5));

    for (auto value : pointMap)
    {
       cout <<  value.first.x << " - " << value.second << endl;
    }
    return 0;
}