#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> ret = {};
    auto num0 = std::count(nums.begin(), nums.end(), 0);
    if (num0 > 1) {
      for (int n = 0; n < nums.size(); ++n)
        ret.push_back(0);
      return ret;
    }
    if (num0 == 1) {
      auto it = find(nums.begin(), nums.end(), 0);
      auto index = it - nums.begin();
      long long sum = 1;
      for (int n = 0; n < index; ++n) {
        sum *= nums[n];
        ret.push_back(0);
      }
      ret.push_back(0);
      for (int n = index + 1; n < nums.size(); ++n) {
        sum *= nums[n];
        ret.push_back(0);
      }
      ret[index] = sum;
      return ret;
    }

    long long sum = 1;
    for (int n = 0; n < nums.size(); ++n) {
      sum *= nums[n];
    }
    cout << "sum={" << sum << "}" << endl;
    for (int n = 0; n < nums.size(); ++n) {
      ret.push_back(sum / nums[n]);
    }
    return ret;
  }
};

int main() {
  vector<int> a{5, 9, 2, -9, -9, -7, -8, 7, -9, 10};
  Solution s;
  auto ret = s.productExceptSelf(a);
  for (auto &it : ret) {
    /* code */
    cout << it << " ";
  }
  cout << endl;
}