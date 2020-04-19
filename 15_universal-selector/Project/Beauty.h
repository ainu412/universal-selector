#pragma once
#include <iostream>
using namespace std;
/*
附1：优化Student类, 属性变成 char *pname, 构造函数里面 分配内存
附2：优化Student类,析构函数 释放pname指向的内存空间
附3：优化Student类,避免浅赋值/浅拷贝 重载= 和 重写拷贝构造函数
附4：思考 Student * 类成员如何操作
*/
class Beauty
{ 
public:
	Beauty(int age = 0, const char* name = "");
	~Beauty();//数据成员有指针就必须写析构函数
	Beauty(const Beauty& src);//数据成员有指针就必须写拷贝构造函数
	Beauty& operator=(const Beauty& src);//数据成员有指针就必须写赋值构造函数

	friend ostream& operator<<(ostream& os, const Beauty& beauty);

private:
	int age;
	char* name;
};

ostream& operator<<(ostream& os, const Beauty& beauty);