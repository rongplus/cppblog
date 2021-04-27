
#include <iostream>


#include "observer1.h"
#include "observer2.h"
#include "observer3.h"
#include "observer4.h"
#include "observer5.h"

#include "incomecenter.h"

using namespace std;
int main()
{
    cout << "Test started---"<< endl;

    IncomeCenter ct;
    Observer1 o1;
    Observer2 o2;
    Observer3 o3;
    Observer4 o4;
    Observer5 o5;
    string mss = "From Main";
    ct.addObserverCallBack( std::bind(&Observer1::notified,o1,std::placeholders::_1) ); //todo pass msg
    ct.addObserverCallBack( std::bind(&Observer2::notified,o2,std::placeholders::_1) ); //todo pass msg
    ct.addObserverCallBack( std::bind(&Observer3::notified,o3,std::placeholders::_1) ); //todo pass msg
    ct.addObserverCallBack( std::bind(&Observer4::notified,o4,std::placeholders::_1) ); //todo pass msg
    ct.addObserverCallBack( std::bind(&Observer5::notified,o5,std::placeholders::_1) ); //todo pass msg
    //ct.addObserverCallBack(o2.notified); //todo add more functions
    //ct.addObserverCallBack(  std::mem_fn(&Observer3::notified) );
    //ct.addObserverCallBack(o4.notified);
    //ct.addObserverCallBack(o5.notified);
    //ct.addObserverCallBack( std::mem_fn(&Observer5::notified)); //todo
    auto calld =  std::mem_fn(&Observer5::notified);
    calld(o5,mss);
    ct.notifyAll();
    ct.notifyAll(mss);

    return 0;
}