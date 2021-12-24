#include <iostream>

using namespace std;

struct Foo {
    void display_greeting() {
        std::cout << "Hello, world.\n";
    }
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data = 7;
};

int main()
{
    const string s = "Inception";
string& p = const_cast <string&> (s);
string* ps = const_cast <string*> (&s);  // &s 的类型是 const string*
cout << "string = " <<p << " - " << *ps << endl;
p = "qu nide ";
*ps = "hekllll";
cout << "string = " <<p << " - " << *ps << endl;

 Foo f;
 
    auto greet = std::mem_fn(&Foo::display_greeting);
    greet(f);
 
    auto print_num = std::function<void()>(&Foo::display_number);
    print_num(f, 42);
 
    auto access_data = std::mem_fn(&Foo::data);
    std::cout << "data: " << access_data(f) << '\n';

    return 0;
}