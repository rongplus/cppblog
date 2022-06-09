
#include <iostream>
#include <string>

using namespace std;

class from_string

{

  const string m_str;

public:
  from_string(const char *str) : m_str(str) {}

  template <typename type>

  operator type() {

    if constexpr (is_same_v<type, float>)
      return stof(m_str);

    else if (is_same_v<type, int>)
      return stoi(m_str);
  }
};

int main() {
  int n_int = from_string("123");

  float n_float = from_string("123.111");
}
