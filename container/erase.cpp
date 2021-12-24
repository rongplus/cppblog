#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> myList;
	int i;

	for (i = 0;i < 10;++i) {
		myList.push_back(i);
	}

	for (int m : myList) {
		cout << m <<",";
    }
	cout << "\n";

	list<int>::iterator it = myList.begin();
	while(it != myList.end()) {
		if(*it % 2 == 0) 
			it = myList.erase(it);
            //myList.remove(it);
		++it;  // needed for VC
	}

	for(it = myList.begin(); it != myList.end(); ++it) {
		cout << *it <<",";
	}

	return 0;
}