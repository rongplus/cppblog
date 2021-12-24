 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
 //第二种方法：饿汉式　+　atexit函数
class SingletonE
{
public:
	static SingletonE * getInstanceE()
	{
        //pthread_once(&_once, init); init->call destroy

		if(_pInstance == NULL)
		{
			_pInstance = new SingletonE;
			atexit(destroy);
		}
		return _pInstance;
	}
 
	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
 
private:
	SingletonE(){	cout << "SingletonE()" << endl;}
	~SingletonE(){	cout << "~SingletonE()" << endl;}
 
private:
	static SingletonE * _pInstance;
};
 
SingletonE * SingletonE::_pInstance = getInstanceE();

class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}
 
		~AutoRelease()
		{
			if(_pInstance)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
			_pInstance = new Singleton;
		
		return _pInstance;
	}
 
private:
	Singleton(){	cout << "Singleton()" << endl;}
	~Singleton(){	cout << "~Singleton()" << endl;}
 
private:
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;
};
 
Singleton * Singleton::_pInstance = getInstance();
Singleton::AutoRelease Singleton::_autoRelease;
 
 
int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
 
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
 
	return 0;
}