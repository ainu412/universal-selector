#pragma once
#include <iostream>
using namespace std;

class Beauty
{
public:
	Beauty(int age = 0, string name = "") {//指针的浅拷贝和深拷贝才有差别->浅拷贝指向同一块内存,深拷贝指向不同内存
		this->age = age;				   //此次数据不含指针,故无需再手动定义深拷贝
		this->name = name;
	}

	friend ostream& operator<<(ostream& os, const Beauty& beauty);
private:
	int age;
	string name;
};

ostream& operator<<(ostream& os, const Beauty& beauty);