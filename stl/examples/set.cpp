#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	set<int> a = {0,1,2,5,9};
	auto it2 = a.lower_bound(3);//返回指向第一个大于等于x的元素的迭代器
	auto it = a.upper_bound(3);//返回指向第一个大于x的元素的迭代器
	cout << *it2 << endl;//输出为2
	cout << *it << endl;//输出为5
	return 0;
} 