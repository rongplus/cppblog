// vector::data
#include <iostream>
#include <vector>
using namespace std;

struct ABC
{
  int a;
  char pp[6];
  int b;
  uint8_t c;
};


int main ()
{
  std::vector<int> myvector (5);
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];

  char* q=(char*)( myvector.data());
  int * p = (int *)q;

  *p = 10;
  ++p;
  *p = 20;
  p[2] = 100;

  int qq[5] = {1,2,3,4,5};
  
  char aaa[] = "abcde";
  q=(char*)( myvector.data());
  memcpy(q,aaa,sizeof(char)*5);


  char* qww=(char*)( myvector.data());
  for (int m=0; m<5; ++m)
    std::cout << qww[m] << " ";
  std::cout << "\n--------------\n";


  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

    ABC *abc = new ABC;
    abc->a = 10;
    abc->b = 20;
    abc->c = 2;
    memcpy(abc->pp,"Hello",sizeof(char)*6);

    std::vector<uint8_t> bb(sizeof(ABC));

    char *pbb = (char*) bb.data();
    memcpy(pbb,abc,sizeof(ABC));

    
    ABC *ddd = (ABC*)bb.data();
    //memcpy(ddd,"Hello",sizeof(char)*6);

    std::cout<< "ABC = " << ddd->a << " " << ddd->b << " c= " << ddd->c << " " <<ddd->pp << std::endl;



    vector<int> v1(sizeof(ABC)/sizeof(int)) ;
    int* pAAA = reinterpret_cast<int*>(abc);
    fill_n(v1.begin(),sizeof(ABC)/sizeof(int), 2 );

    ddd = (ABC*)v1.data();

    std::cout<< "last ABC = " << ddd->a << " " << ddd->b << " c= " << ddd->c << " " <<ddd->pp << std::endl;


    {
      ABC abc;
      abc.a = 19;
      abc.b = 35;
      vector<int> v1(sizeof(ABC)/sizeof(int)) ;
      int *pdata = (int*)v1.data();
      


    }


    {
      ABC abc;
      abc.a = 19;
      abc.b = 35;

  std::vector<uint8_t> myvector (sizeof(ABC)/sizeof(uint8_t));
  uint8_t* pp = (uint8_t*)&abc;

  std::copy ( pp, pp + sizeof(ABC) , myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<uint8_t>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  ABC *out  = (ABC*) myvector.data();
  cout << "\nabc = " << out->a << " " << out->b << " " << out->pp << endl;

  std::cout << '\n';//dasdd
    }





  return 0;
}