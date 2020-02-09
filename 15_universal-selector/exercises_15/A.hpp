#include "A.h"
template<typename T>
inline A<T>::A(T x) :x(x) {}

template<typename T>
inline A<T> A<T>::operator+ (const A<T> & other) {
	A tmp;
	tmp.x = x + other.x;
	return tmp;
}

template<typename T>
inline T A<T>::getX() {
	return x;
}

template<typename T>
A<T> operator-(const A<T>& a1, const A<T>& a2)//������Ԫ����Ϊ��֤��ȫ,���޸����г�Ա,��ü���const
{
	//a1.x -= a2.x;
	//return a1;//��ӾͲ�������,���ʱ�Ŵ���,Ϊ�˷���������ֵ
	A<T> tmp;
	tmp.x = a1.x - a2.x;
	return tmp;
}

template<typename T>
inline A<T> addA(const A<T>& a1, const A<T>& a2)
{
	A<T> tmp;
	tmp.x = a1.x + a2.x;
	return tmp;
}

template <typename T>
ostream& operator<<(ostream& os, const A<T>& object) {
	os << object.x << endl;
	return os;
}
