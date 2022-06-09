#include <iostream>
#include <vector>
#include <gflags/gflags.h>


DEFINE_int32(a1,100, "a1");
DEFINE_int32(a2,100, "a1");
DEFINE_int32(a3,100, "a1");
DEFINE_int32(a4,100, "a1");
DEFINE_int32(a5,100, "a1");
int main(int argc, char ** argv)
{
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	std::cout << "a1=" << FLAGS_a1 << std::endl;
	std::cout << "a2=" << FLAGS_a2 << std::endl;
	std::cout << "a3=" << FLAGS_a3 << std::endl;
	std::cout << "a4=" << FLAGS_a4 << std::endl;
	std::cout << "a5=" << FLAGS_a5 << std::endl;
	//std::cout << "a1=" << FLAGS_a1 << std::endl;
	std::vector<int*> v;
	int n=0;
	v.push_back( new int(n++));
	v.push_back( new int(n++));
	v.push_back( new int(n++));
	v.push_back( nullptr);
	v.push_back( new int(n++));
	v.push_back( new int(n++));
	v.push_back( new int(n++));
	v.push_back( nullptr);
	v.push_back( new int(n++));
	v.push_back( new int(n++));
	v.push_back( nullptr);

	std::cout << "n= " << n << std::endl;;
	//auto new_end = std::remove_if(      v.begin(), v.end(), [](const auto& ts) { return ts == nullptr; });
	for(auto *it: v)
	{
		if (it)
		std::cout << *it << std::endl;
	else
		std::cout << "null" << std::endl;
	}
	return 0;
}