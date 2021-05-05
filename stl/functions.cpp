/* 函数包装器管理内嵌函数 */
/*
  以一个简单的四则运算为例子
*/
//#pragma warning(disable: 2064)
#include<stdio.h>
#include<iostream>
#include<functional>

template <typename T ,typename F>
   T run(T a , T b , F f) {
    
       return f(a , b);
 }

 double ca(double a, double b)
 {
     std::cout << a << "-" << b << std::endl;
     return a;
 }

int main(int argc , char * args []){

    using std::function;
    double db = 12.9; //double *
    //加 减 乘 除
    function<double(double,double)> Add = [](double a , double b) {
        return a+b;
    };
    function<double(double, double)> Sub = [](double a, double b) {
        return a - b;
    };
    function<double(double, double)> Mul = [](double a, double b) {
        return a*b;
    };
    function<double(double, double)>Div = [](double a, double b) {
        return a / b;
    };
    //定义一个函数数组
    function<double(double, double)>p[]= { Add,Sub,Mul,Div,ca };
    char str[] = "+-*/";
    int i = 0;
    for(auto fun : p )
    std::cout <<"12 "<<str[i++]<<" 13 ="<< run<double>(12,13,fun) <<std::endl;
    std::cin.get();
  return 0;
}