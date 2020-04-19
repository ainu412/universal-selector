#pragma once
#include <iostream>
using namespace std;
/*
��1���Ż�Student��, ���Ա�� char *pname, ���캯������ �����ڴ�
��2���Ż�Student��,�������� �ͷ�pnameָ����ڴ�ռ�
��3���Ż�Student��,����ǳ��ֵ/ǳ���� ����= �� ��д�������캯��
��4��˼�� Student * ���Ա��β���
*/
class Beauty
{ 
public:
	Beauty(int age = 0, const char* name = "");
	~Beauty();//���ݳ�Ա��ָ��ͱ���д��������
	Beauty(const Beauty& src);//���ݳ�Ա��ָ��ͱ���д�������캯��
	Beauty& operator=(const Beauty& src);//���ݳ�Ա��ָ��ͱ���д��ֵ���캯��

	friend ostream& operator<<(ostream& os, const Beauty& beauty);

private:
	int age;
	char* name;
};

ostream& operator<<(ostream& os, const Beauty& beauty);