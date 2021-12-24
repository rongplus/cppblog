#include <iostream>
#include <list>
using namespace std;

class Hashing
{
    int hash_bucket; // No. of buckets

    // Pointer to an array containing buckets
    list<int> *hashtable;

public:
    Hashing(int V); // Constructor

    // inserts a key into hash table
    void insert_key(int val);

    // deletes a key from hash table
    void delete_key(int key);

    // hash function to map values to key
    int hashFunction(int x)
    {
        return (x % hash_bucket);
    }

    void displayHash();
};

Hashing::Hashing(int b)
{
    this->hash_bucket = b;
    hashtable = new list<int>[hash_bucket];
}

//insert to hash table
void Hashing::insert_key(int key)
{
    int index = hashFunction(key);
    hashtable[index].push_back(key);
}

void Hashing::delete_key(int key)
{
    // get the hash index for key
    int index = hashFunction(key);

    // find the key in (inex)th list
    list<int>::iterator i;
    for (i = hashtable[index].begin();
         i != hashtable[index].end(); i++)
    {
        if (*i == key)
            break;
    }
    // if key is found in hash table, remove it
    if (i != hashtable[index].end())
        hashtable[index].erase(i);
}

// display the hash table
void Hashing::displayHash()
{
    for (int i = 0; i < hash_bucket; i++)
    {
        cout << i;
        for (auto x : hashtable[i])
            cout << " --> " << x;
        cout << endl;
    }
}
// main program
void myTerminate(){cout<< "ff";}
class A{};
class B{};


int main()
{

    
	set_terminate(myTerminate);
    // array that contains keys to be mapped
    int hash_array[] = {11, 12, 21, 14, 15};
    int n = sizeof(hash_array) / sizeof(hash_array[0]);

    Hashing h(7); // Number of buckets = 7

    //insert the keys into the hash table
    for (int i = 0; i < n; i++)
        h.insert_key(hash_array[i]);
    // display the Hash table
    cout << "Hash table created:" << endl;
    h.displayHash();

    // delete 12 from hash table
    h.delete_key(12);

    // display the Hash table
    cout << "Hash table after deletion of key 12:" << endl;
    h.displayHash();

    try{
		int 	j = 0;
		double 	d = 2.3;
		char 	str[20] = "Hello";
		cout<<"Please input a exception number: ";
		int a;
		cin>>a;
		switch(a){
		case  1:
			throw d;
		case  2:
			throw j;
		case  3:
			throw str;
		case  4:
			throw A();
		case  5:
			throw B();
		default:
			cout<<"No throws here.\n";
		}
	}
	catch(int){
		cout<<"int exception.\n";
	}
	catch(double){
		cout<<"double exception.\n";
	}
	catch(char*){
		cout<<"char* exception.\n";
	}
	catch(A){
		cout<<"class A exception.\n";
	}
	// catch(B){
	// 	cout<<"class B exception.\n";
	// }



    return 0;
}