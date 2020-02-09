#pragma once
using namespace std;
#include <iostream>
//*类模板的分离式写法
//*初始化构造函数
//*实现一类内两对象相加,返回临时对象,保存结果
//类内+运算符重载
//类外友元+运算符重载函数
//类外友元普通函数
//*静态成员变量的分配
//一种类型的实例共享一个静态成员(不论静态成员的类型是啥T/int/char/...)

template <typename T>
class A
{
public:
	A(T x = 0);

	A operator+ (const A& other);

	T getX();

	template <typename T>//完全按照类外声明的写法
	friend A<T> operator-(const A<T>& a1, const A<T>& a2);

	template <typename T>//完全按照类外声明的写法
	friend A<T> addA(const A<T>& a1, const A<T>& a2);

	friend ostream& operator<< <T>(ostream& os, const A& object);//特别记忆!!不写template,只<<后加<T>(定义时要写template不加<T>)
public:
	static string s;
private:
	T x;
};

template <typename T>
string A<T>::s = "";