#pragma once
#include <iostream>
#include "Beauty.h"
using namespace std;

/*
*�����һ������ģ���ࣨ Vector ������ɶ�int��char��float��double �Լ�������Զ����������Ԫ�ؽ��й���
����
a.Ĭ��+���ι��캯��
b.�������캯��
//c.cout << myVector[i]��ӡ��������Ԫ��ֵ,��os << m_base[i]->���±����غ󲻱�,������cout<<myVector������ڲ�����Ԫ��
d.[]����:ֱ�ӷ��ʴ洢Ԫ��,myVector[i] = m_base[i] = *(m_base+i) = �洢����ӡԪ��ֵ
e.��ֵ���캯��,����������ֵ
f.��ȡ���ж���洢Ԫ�ظ���(����ָ��ָ��洢Ԫ���׵�ַ)->��ʼ��ʱ����

*�ǵ���ָ���Ҫ�����ڴ�->���ݴ���Ԫ�ظ���,���䶯̬�ڴ�

ʲô���͵�ָ��,��Ӧ���Ԫ��Ҳ����ʲô���͵�->���迼�����Ԫ����ռ�ֽڳ���

cnt>0 i>=0
*/
template <typename T>
class Vector
{
public:
	Vector(int cnt = 128);//���캯��(����ֵ���캯��)�ĺ����������<T>
	~Vector();
	Vector(Vector& src);

	Vector& operator=(Vector& src);

	T& operator[](int i);

	int getCnt();

private:
	int cnt;//member_count�洢Ԫ�ظ���
	T* p;//member_pointer�洢Ԫ���׵�ַ

	friend ostream& operator<< <T>(ostream& os, const Vector<T>& object);
};

