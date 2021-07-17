
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Foo{
 
  int x; int y;
  

};

struct KeyEqual111 {
 bool operator()(const Foo& lhs, const Foo& rhs) const
 {
    return true;
 }
};

struct KeyHasher
{
  std::size_t operator()(const Foo& f) const
  {
  
    return 1;
  }


};

int main()
{
  cout << "Hello World." << endl;
  unordered_map<Foo,string,KeyHasher,KeyEqual111> contracts ={};

  Foo f;
  f.x = 10;
  f.y = 10;
  
  contracts.insert({f,"fasdff"});
  contracts.insert({Foo(),"ff"});
  
  for (auto value : contracts)
  {
    cout <<"(" << value.first.x << "," << value.first.y << ") - " << value.second << endl;
  }

  auto cm = [](const Foo& lhs, const Foo& rhs)
  {
      return true;
  };

  //unordered_map<Foo,string,KeyHasher,cm> m1 ={};
  return 0;
}
