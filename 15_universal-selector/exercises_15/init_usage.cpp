#include <iostream>
using namespace std;
int max(int a, char b) {
	return a > b ? a : b;
}
/*
��Ŀ����: ʵ��һ�������������������������ֵ��Ҫ����֧��char���͡�int���͡�double���ͱ���,�����е�int������
*/
template <typename T>
T max(int a, int b) {//��ʽ��������
	return a > b ? a : b;
}
template <typename T>//ÿ����һ�ξ�Ҫ��������һ��;����ͬ��??ֻҪ�������Ͳ�ͬ����
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
	//>���������,�ȽϺ�����k��С,����return true,����ģ�庯���ж����
	bool operator>(Demo& other) {
		return k > other.k;
	}
public:
	int k;
};

int main() {
	//int x = 1;
	//int y = 2;
	//cout << max(x, y) << endl;//��ʽ����,����ʽ��������

	//cout << max(1, 2) << endl;//��ʽ����,����ʽ��������(ģ���������)
	//cout << max<int>(1, 2) << endl;//��ʽ����,��������ʽ������������;ֻ��������һ������������

	//cout << max('a', 'b') << endl;//b
	//cout << max<char>('a', 'b') << endl;//��ʽ����,����ʽ���������Ҳ�����,�ٴ���ʽ����
	//cout << max<int>('a', 'b') << endl;//98
	//
	//cout << max<int>(3, 'c') << endl;//99(c��ASCII��ֵ)
	////cout << max(3, 'c') << endl;��-�޷��жϷ���ֵ����
	//
	//cout << max(0.1, 0.2) << endl;//0.2
	//cout << max<double>(0.1, 0.2) << endl;//0.2

	//Demo d1(1), d2(2);
	//cout << max(d1, d2).k << endl;//2

	cout << max(1.0, 2.0, 3.0);

	return 0;
}