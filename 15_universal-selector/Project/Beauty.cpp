#include "Beauty.h"

ostream& operator<<(ostream& os, const Beauty& beauty)
{
	os << "美女的姓名为:" << beauty.name 
	   << ",年龄为:" << beauty.age << endl;
	return os;
}

Beauty::Beauty(int age, const char* name) :age(age)
{//指针的浅拷贝和深拷贝才有差别->浅拷贝指向同一块内存,深拷贝指向不同内存
 //此次数据成员若不含指针,故无需再手动定义深拷贝

	/*int len = name.length() + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name.c_str());*/

	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

Beauty::~Beauty()
{
	if (name) {
		delete[] name;
	}
}

Beauty::Beauty(const Beauty& src)
{
	int len = strlen(src.name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, src.name);

	age = src.age;
}

Beauty& Beauty::operator=(const Beauty& src)
{
	if (name) {
		delete[] name;
	}
	int len = strlen(src.name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, src.name);

	age = src.age;

	return *this;
}