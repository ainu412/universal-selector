#pragma once
#include <iostream>
using namespace std;

class Beauty
{
public:
	Beauty(int age = 0, string name = "") {//ָ���ǳ������������в��->ǳ����ָ��ͬһ���ڴ�,���ָ��ͬ�ڴ�
		this->age = age;				   //�˴����ݲ���ָ��,���������ֶ��������
		this->name = name;
	}

	friend ostream& operator<<(ostream& os, const Beauty& beauty);
private:
	int age;
	string name;
};

ostream& operator<<(ostream& os, const Beauty& beauty);