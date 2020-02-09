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
A<T> operator-(const A<T>& a1, const A<T>& a2)//类外友元函数为保证安全,不修改已有成员,最好加上const
{
	//a1.x -= a2.x;
	//return a1;//相加就不传递了,相等时才传递,为了方便连续赋值
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
