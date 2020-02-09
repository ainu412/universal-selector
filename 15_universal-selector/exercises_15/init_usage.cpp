#include <iostream>
using namespace std;
int max(int a, char b) {
	return a > b ? a : b;
}
/*
项目需求: 实现一个函数用来返回两个数的最大值，要求能支持char类型、int类型、double类型变量,及类中的int型数据
*/
template <typename T>
T max(int a, int b) {//显式参数类型
	return a > b ? a : b;
}
template <typename T>//每定义一次就要连着声明一次;可以同名??只要参数类型不同即可
T max(T a, T b) {
	return a > b ? a : b;
}
template <typename T>
T max(int a, char b) {
	return a > b ? a : b;
}
template <typename T>
T max(T a, T b, T c) {
	return max(max(a,b),c);
}

class Demo {
public:
	Demo(int k):k(k){}
	//>运算符重载,比较含数据k大小,大则return true,方便模板函数判断真假
	bool operator>(Demo& other) {
		return k > other.k;
	}
public:
	int k;
};

int main() {
	//int x = 1;
	//int y = 2;
	//cout << max(x, y) << endl;//隐式声明,代隐式参数类型

	//cout << max(1, 2) << endl;//隐式声明,代隐式参数类型(模板参数类型)
	//cout << max<int>(1, 2) << endl;//显式声明,则先在显式参数类型里找;只能声明第一个参数的类型

	//cout << max('a', 'b') << endl;//b
	//cout << max<char>('a', 'b') << endl;//显式声明,在显式参数类型找不到了,再代隐式类型
	//cout << max<int>('a', 'b') << endl;//98
	//
	//cout << max<int>(3, 'c') << endl;//99(c的ASCII码值)
	////cout << max(3, 'c') << endl;×-无法判断返回值类型
	//
	//cout << max(0.1, 0.2) << endl;//0.2
	//cout << max<double>(0.1, 0.2) << endl;//0.2

	//Demo d1(1), d2(2);
	//cout << max(d1, d2).k << endl;//2

	cout << max(1.0, 2.0, 3.0);

	return 0;
}