#include <iostream>
#include <bitset>
using namespace std;
 
int main()
{
   unsigned int a = 60;      // 60 = 0011 1100  
   unsigned int b = 13;      // 13 = 0000 1101
   float f = a/b;
   cout << "f=" << f << endl;
   int c = 0;           
    cout <<"a= "<<  bitset<32>(a) << " \nb= " << bitset<32>(b) << endl;
   c = a & b;             // 12 = 0000 1100
   cout << "Line a&b =" << c << endl ;
 
   c = a | b;             // 61 = 0011 1101
   cout << "Line a|b =" << c << endl ;
 
   c = a ^ b;             // 49 = 0011 0001
   cout << "Line a^b =" << c << endl ;
 
   c = ~a;                // -61 = 1100 0011
   cout << "Line ~a =" << c << endl ;
 
   c = a << 2;            // 240 = 1111 0000
   cout << "Line a<<2 =" << c << endl ;
 
   c = a >> 2;            // 15 = 0000 1111
   cout << "Line a>>2 =" << c << endl ;
 
   return 0;
}