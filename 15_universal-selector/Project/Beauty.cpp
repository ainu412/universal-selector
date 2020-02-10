#include "Beauty.h"

ostream& operator<<(ostream& os, const Beauty& beauty)
{
	os << "��Ů������Ϊ:" << beauty.name 
	   << ",����Ϊ:" << beauty.age << endl;
	return os;
}

Beauty::Beauty(int age, const char* name) :age(age)
{//ָ���ǳ������������в��->ǳ����ָ��ͬһ���ڴ�,���ָ��ͬ�ڴ�
 //�˴����ݳ�Ա������ָ��,���������ֶ��������

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