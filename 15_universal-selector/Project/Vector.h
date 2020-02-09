#pragma once
#include <iostream>
#include "Beauty.h"
using namespace std;

/*
*请设计一个数组模板类（ Vector ），完成对int、char、float、double 以及任意的自定义类等类型元素进行管理。
需求
a.默认+带参构造函数
b.拷贝构造函数
//c.cout << myVector[i]打印访问数组元素值,令os << m_base[i]->有下标重载后不必,但若想cout<<myVector就输出内部所有元素
d.[]重载:直接访问存储元素,myVector[i] = m_base[i] = *(m_base+i) = 存储及打印元素值
e.赋值构造函数,是整个对象赋值
f.获取存有对象存储元素个数(对象指针指向存储元素首地址)->初始化时设置

*记得有指针就要分配内存->依据存入元素个数,分配动态内存

什么类型的指针,相应存的元素也就是什么类型的->无需考虑这个元素所占字节长度

cnt>0 i>=0
*/
template <typename T>
class Vector
{
public:
	Vector(int cnt = 128);//构造函数(除赋值构造函数)的函数名后不需加<T>
	~Vector();
	Vector(Vector& src);

	Vector& operator=(Vector& src);

	T& operator[](int i);

	int getCnt();

private:
	int cnt;//member_count存储元素个数
	T* p;//member_pointer存储元素首地址

	friend ostream& operator<< <T>(ostream& os, const Vector<T>& object);
};

