// test system command

#include<iostream>
#include <assert.h>
#include <memory>
#include <math.h>
#include <bitset>
using namespace std;


int main()
{

  int i;
  cout << "Check if command processor is available..."<<endl;
  if (system(NULL)) cout << "command processor is available!!"<<endl;
    else exit (EXIT_FAILURE);
  cout<< "Executing command DIR..."<<endl;
  i=system ("dir");
  cout << "The value returned was:"<<i<<endl;

    return 0;
}