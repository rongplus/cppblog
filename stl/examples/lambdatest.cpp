
#include <map>
using namespace std;
#include <string>
#include <unordered_map>

class Dict {
public:
  int init() {}
  int load() {}

  unordered_map<string, int> &get() { return _dict; }

private:
  unordered_map<string, int> _dict;
};
Dict base_dict;
Dict exp_dict;
bool hit_exp;

int test() {
  auto &dict = [&]() -> decltype(base_dict.get()) & {
    if (hit_exp) { // hit_exp是请求中的参数，bool值
      return exp_dict.get();
    } else {
      return base_dict.get();
    }
  }();

  int a_weight = 0;
  int b_weight = 0;
  if (dict.find("a") != dict.end()) {
    a_weight = dict["a"];
  }
  if (dict.find("b") != dict.end()) {
    b_weight = dict["b"];
  }

  return 0;
}

int main() {
  test();
  return 0;
}