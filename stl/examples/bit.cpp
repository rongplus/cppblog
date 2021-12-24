#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

void arrFun(char a[])
{
    cout<<__func__ <<sizeof(a)<<endl;
}

void arrRefFun(auto &a)
{
    cout<<__func__<<sizeof(a)<<endl;
    cout << typeid(a).name() << endl;
    for (int n=0; n< sizeof(a)/sizeof(a[0]); ++n)
    {
        cout << a[n] << endl;
    }
    // for (char *v: a)
    // {
    //     cout << v << endl;
    // }
}

void arrR(char &a)
{
     cout<<__func__<<sizeof(a)<<endl;
}
void arrPoint(char* a)
{
    cout<<__func__<<sizeof(a)<<endl;
}
void arrTT( char(&a)[10])
{
    cout<<__func__<<sizeof(a)<<endl;
}
int main()
{
    // char a[10] = "abcd";
    //  arrRefFun(a);// 10
    //  arrPoint(a);
    //  arrR(a[0]);

    int a[10] = {1,2,3,4,5};
    arrRefFun(a);


    union{
        short s;
        char c[sizeof(short)];
    }un;
    un.s = 0x0102;
    if(sizeof(short) == 2)
    {
        if(un.c[0] == 1 && un.c[1]== 2)   //将高序字节地址存储在起始地址，成为大端字节序 
            printf("big-endian\n");
        else if(un.c[0] == 2 && un.c[1]== 1) //将低序字节存储在起始地址，为小端字节序 
            printf("little-endian\n");
    }
    else
    {
        printf("sizeof(short)= %d\n",sizeof(short)); 
    }
    return 0;
}