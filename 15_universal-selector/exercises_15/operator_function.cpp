#include <iostream>
using namespace std;

//实现:交换
//模板函数,普通函数
//有参数类型符合的普通函数时,先调用普通函数.
//没有时,再调用
void Swap(int& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
	cout << "调用普通函数int a, char b!" << endl;
}

template <typename T1, typename T2>
void Swap(T1& a, T2& b) {
	T1 tmp = a;
	a = b;
	b = tmp;
	cout << "调用模板函数T1,T2" << endl;
}

template <typename T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
	cout << "调用模板函数T" << endl;
}

int main() {
	int i = 1, i2 = 2;
	char c = 'a';

	cout << "1.隐式" << endl;
	cout << "①完全匹配的普通函数[优先]" << endl;
	//swap(i, c);

	cout << "②模板函数" << endl;
	Swap(i, i2);//std命名空间内有swap函数,注意自己声明时不要定义swap函数

	cout << "2.显式" << endl;
	cout << "--模板函数" << endl;
	Swap<>(i, c);	//=swap<int>(i, c);

	Swap(c, i); //在一次模板函数调用中, T一旦实例为一个类型, 就不能再变//若要变,需要定义T1,T2

	return 0;
}