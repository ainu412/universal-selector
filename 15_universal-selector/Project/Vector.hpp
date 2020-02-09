#include "Vector.h"

template<typename T>
inline Vector<T>::Vector(int cnt) {
	if (cnt > 0) {
		this->cnt = cnt;
	}
	else {
		cnt = 128;
	}
	p = new T[cnt];
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] p;
}

template<typename T>
inline T& Vector<T>::operator[](int i)
{
	if (i >= 0) {
		return p[i];
	}
	else {
		cout << "数组长度有误!" << endl;
		exit(1);
	}
}

template<typename T>
inline int Vector<T>::getCnt()
{
	return cnt;
}

template<typename T>
inline Vector<T>::Vector(Vector& src)
{
	if (p) {
		delete p;
	}
	p = new T[src.cnt];
	cnt = src.cnt;
	for (int i = 0; i < src.cnt; i++) {
		p[i] = src[i];//this[i]好像不行??
	}
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector& src)
{
	if (p) {
		delete p;
	}
	p = new T[src.cnt];
	cnt = src.cnt;
	for (int i = 0; i < src.cnt; i++) {
		(*this)[i] = src[i];
	}
	return *this;
}

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& object)
{
	for (int i = 0; i < object.cnt; i++) {
		os << object.p[i] << "\t";//若存储值,可直接打印;若存储对象,无法直接打印->可直接创建os<<Beauty.name<<" age
	}
	os << endl;

	return os;
}