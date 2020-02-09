#include "A.hpp"

int main() {
	A<int> a1(1), a2(2);
	cout << a1;
	cout << (a1 + a2).getX() << endl;//仅调用无需实例化,创建新的对象才要实例化
	cout << addA(a1, a2).getX() << endl;
	
	A<int> a3 = a1 + a2;
	A<int> a4 = addA(a1, a2);//因为a1,a2已实例化,调用模板函数无需再次实例化
	A<int> a5 = addA<int>(a1, a2);

	cout << (a2 - a1).getX() << endl;//运算符重载函数的调用不用实例化
	
	A<float> a10, a11;
	A<long>  a20, a21;
	cout << "set <float>a10.s=\"float\"后:" << endl;
	a10.s = "float";
	cout << "<float>a11.s=" << a11.s << endl;
	cout << "<long>a21.s=" << a21.s << endl;

	cout << "set <long>a20.s=\"long\"后:" << endl;
	a20.s = "long";
	cout << "<float>a11.s=" << a11.s << endl;
	cout << "<long>a21.s=" << a21.s << endl;

	return 0;
}