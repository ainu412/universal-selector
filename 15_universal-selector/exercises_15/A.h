#pragma once
using namespace std;
#include <iostream>
//*��ģ��ķ���ʽд��
//*��ʼ�����캯��
//*ʵ��һ�������������,������ʱ����,������
//����+���������
//������Ԫ+��������غ���
//������Ԫ��ͨ����
//*��̬��Ա�����ķ���
//һ�����͵�ʵ������һ����̬��Ա(���۾�̬��Ա��������ɶT/int/char/...)

template <typename T>
class A
{
public:
	A(T x = 0);

	A operator+ (const A& other);

	T getX();

	template <typename T>//��ȫ��������������д��
	friend A<T> operator-(const A<T>& a1, const A<T>& a2);

	template <typename T>//��ȫ��������������д��
	friend A<T> addA(const A<T>& a1, const A<T>& a2);

	friend ostream& operator<< <T>(ostream& os, const A& object);//�ر����!!��дtemplate,ֻ<<���<T>(����ʱҪдtemplate����<T>)
public:
	static string s;
private:
	T x;
};

template <typename T>
string A<T>::s = "";