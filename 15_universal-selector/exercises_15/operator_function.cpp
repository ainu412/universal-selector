#include <iostream>
using namespace std;

//ʵ��:����
//ģ�庯��,��ͨ����
//�в������ͷ��ϵ���ͨ����ʱ,�ȵ�����ͨ����.
//û��ʱ,�ٵ���
void Swap(int& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
	cout << "������ͨ����int a, char b!" << endl;
}

template <typename T1, typename T2>
void Swap(T1& a, T2& b) {
	T1 tmp = a;
	a = b;
	b = tmp;
	cout << "����ģ�庯��T1,T2" << endl;
}

template <typename T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
	cout << "����ģ�庯��T" << endl;
}

int main() {
	int i = 1, i2 = 2;
	char c = 'a';

	cout << "1.��ʽ" << endl;
	cout << "����ȫƥ�����ͨ����[����]" << endl;
	//swap(i, c);

	cout << "��ģ�庯��" << endl;
	Swap(i, i2);//std�����ռ�����swap����,ע���Լ�����ʱ��Ҫ����swap����

	cout << "2.��ʽ" << endl;
	cout << "--ģ�庯��" << endl;
	Swap<>(i, c);	//=swap<int>(i, c);

	Swap(c, i); //��һ��ģ�庯��������, Tһ��ʵ��Ϊһ������, �Ͳ����ٱ�//��Ҫ��,��Ҫ����T1,T2

	return 0;
}