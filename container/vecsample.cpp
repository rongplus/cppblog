#include <vector>
#include <iostream>
using namespace std;

int main()
{

	//构造函数,复制构造函数(元素类型要一致),
	vector<int> vecA;  //创建一个空的的容器
	vector<int> vecB(10,20); //创建一个10个元素,每个元素值为20
	vector<int> vecC(vecB.begin(),vecB.end()); //使用迭代器,可以取部分元素创建一个新的容器
	vector<int> vecD(vecC); //复制构造函数,创建一个完全一样的容器

	//重载=
	vector<int> vecE;
	vecE = vecB;

	//vector::begin()，返回的是迭代器

	vector<int> vecF(10); //创建一个有10个元素的容器
	cout << "vecF:";
	for (int i = 0; i < 10; i++)
	{
		vecF[i] = i;
		cout << vecF[i]<< " ";
	}
	cout << endl;

	//vector::begin() 返回迭代器
	vector<int>::iterator Beginit = vecF.begin();
	cout<< "vecF.begin():" << *Beginit << endl; 

	//vector::end() 返回迭代器
	vector<int>::iterator EndIter = vecF.end();
	EndIter--; //向后移一个位置
	cout <<"vecF.end():"<< *EndIter << endl; 

	//vector::rbegin() 返回倒序的第一个元素，相当于最后一个元素
	vector<int>::reverse_iterator ReverBeIter = vecF.rbegin();
	cout << "vecF.rbegin(): "<< *ReverBeIter << endl; 

	//vector::rend() 反序的最后一个元素下一个位置，也相当于正序的第一个元素前一个位置
	vector<int>::reverse_iterator ReverEnIter = vecF.rend();
	ReverEnIter--;
	cout << "vecF.rend():"<< *ReverEnIter << endl; 

	//vector::size() 返回元素的个数
	cout << "vecF.size():"<< vecF.size() << endl; 

	//vector::max_size()
	cout << "vecF.max_size():"<< vecF.max_size() << endl; 

	//vector::resize()
	cout<< "vecF.size():" << vecF.size() << endl; 
	vecF.resize(5);

	cout<< "resize vecF" << endl; 
	for(int k = 0; k < vecF.size(); k++)
		cout << vecF[k] << "  "; 
	cout << endl;

	//vector::capacity()
	cout<< "after vecF.size():"<< vecF.size() << endl; 
	cout<< "after vecF.capacity():" << vecF.capacity() << endl; 

	//vector::empty()
	vecB.resize(0);
	cout<< "after vecB.resize(0):"<< endl; 

	cout  << "vecB.size():" << vecB.size() << endl; 
	cout  << "vecB.capacity():" << vecB.capacity() << endl; 
	if(vecB.empty())
	    cout << "vecB is empty"<< endl; 
	else
		cout << "vecB not empty"<< endl; 

	//vector::reserve() //重新分配存储空间大小
	cout<< "vecC.capacity():" << vecC.capacity() << endl; //

	vecC.reserve(4);
	cout << "vecC.reserve(4)后vecC.capacity()： "<< vecC.capacity() << endl; //10
	vecC.reserve(14);
	cout << "vecC.reserve(14)后vecC.capacity()： "<< vecC.capacity() << endl; //14

	//vector::operator []
	cout << "vecF[0]:"<< vecF[0] << endl; //第一个元素是0

	//vector::at()
	try
	{
		cout << "vecF.size = " << vecF.size() << endl; //5
		cout << vecF.at(6) << endl; //抛出异常
	}
	catch(out_of_range)
	{	
		cout << "at()访问越界" << endl;
	}

	//vector::front() 返回第一个元素的值
	cout << "vecF.front():"<< vecF.front() << endl; //0

	//vector::back()
	cout << "vecF.back():"<< vecF.back() << endl; //4

	//vector::assign()
	cout <<"vecA.size():"<< vecA.size() << endl; //0
	vector<int>::iterator First = vecC.begin();
	vector<int>::iterator End = vecC.end()-2;
	vecA.assign(First,End);
	cout << vecA.size() << endl; //8
	cout << vecA.capacity() << endl; //8

	vecA.assign(5,3); //将丢弃原来的所有元素然后重新赋值
	cout << vecA.size() << endl; //5
	cout << vecA.capacity() << endl; //8

	//vector::push_back()
	cout << *(vecF.end()-1) << endl; //4
	vecF.push_back(20);
	cout << *(vecF.end()-1) << endl; //20

	//vector::pop_back()
	cout << *(vecF.end()-1) << endl; //20
	vecF.pop_back();
	cout << *(vecF.end()-1) << endl; //4

	//vector::swap()
	cout << "vecF:";
	for (int i = 0; i < vecF.size(); i++)
	{
		vecF[i] = i;
		cout << vecF[i]<< " ";
	}
	cout << endl;
	cout << "vecD:";
	for (int d = 0; d < vecD.size(); d++)
	{
		vecD[d] = d;
		cout << vecD[d]<< " ";
	}
	cout << endl;

	vecF.swap(vecD); //交换这两个容器的内容
	cout <<"vecD与vecF交换后：" <<endl;
	cout << "vecF:";
	for(int f = 0; f < vecF.size(); f++)
		cout << vecF[f] << " ";
	cout << endl;

	cout << "vecD:";
	for (int d = 0; d <vecD.size(); d++)
		cout << vecD[d] << " ";
	cout << endl;
	//vector::clear()
	vecF.clear();
	cout << "vecF.clear()后vecF.size()："<< vecF.size() << endl;     //0
	cout << "vecF.clear()后vecF.capacity()："<< vecF.capacity() << endl; //10

	return 0;
}