#include "A.hpp"

int main() {
	A<int> a1(1), a2(2);
	cout << a1;
	cout << (a1 + a2).getX() << endl;//����������ʵ����,�����µĶ����Ҫʵ����
	cout << addA(a1, a2).getX() << endl;
	
	A<int> a3 = a1 + a2;
	A<int> a4 = addA(a1, a2);//��Ϊa1,a2��ʵ����,����ģ�庯�������ٴ�ʵ����
	A<int> a5 = addA<int>(a1, a2);

	cout << (a2 - a1).getX() << endl;//��������غ����ĵ��ò���ʵ����
	
	A<float> a10, a11;
	A<long>  a20, a21;
	cout << "set <float>a10.s=\"float\"��:" << endl;
	a10.s = "float";
	cout << "<float>a11.s=" << a11.s << endl;
	cout << "<long>a21.s=" << a21.s << endl;

	cout << "set <long>a20.s=\"long\"��:" << endl;
	a20.s = "long";
	cout << "<float>a11.s=" << a11.s << endl;
	cout << "<long>a21.s=" << a21.s << endl;

	return 0;
}