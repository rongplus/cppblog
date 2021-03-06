#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

template <class ForwardIt> void quicksort(ForwardIt first, ForwardIt last) {
  if (first == last)
    return;
  auto pivot = *std::next(first, std::distance(first, last) / 2);
  ForwardIt middle1 = std::partition(
      first, last, [pivot](const auto &em) { return em < pivot; });
  ForwardIt middle2 = std::partition(
      middle1, last, [pivot](const auto &em) { return !(pivot < em); });
  quicksort(first, middle1);
  quicksort(middle2, last);
}

int main() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "Original vector:\n    ";
  for (int elem : v)
    std::cout << elem << ' ';

  auto it =
      std::partition(v.begin(), v.end(), [](int i) { return i % 2 == 0; });

  std::cout << "\nPartitioned vector:\n    ";
  std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
  std::cout << " * "
               " ";
  std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));

  std::cout << std::endl;
  for (auto it : v) {
    std::cout << it << " ";
  }
}