

#include<iostream>
#include <assert.h>
#include <memory>
#include <math.h>
#include <bitset>
using namespace std;


int main()
{
    int ssum = 0;
    for (int n=0; n<10; n++)
    {
        ssum ^= n;
        cout<<bitset<8>(ssum)<<endl;
    }
    cout << "----------------------" << endl;

    for (int n=0; n<9; n++)
    {
        ssum ^= n;
        cout<<bitset<8>(ssum)<<endl;
    }
    cout << "----------------------" << endl;
    cout << ssum << endl;

     int i;
  cout << "Check if command processor is available..."<<endl;
 
    return 0;
}