#include <list>
#include <iostream>
#include <deque>
using namespace std;

int main() {
	list<int > l(3);//ֻ�г�ʼ��ʱ������,���ܸ�ֵ	l.assign(3);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";//0 0 0
	}cout << endl;
	l.assign(1, 1);
	l.push_back(4);
	l.push_back(3);
	l.push_back(4);//1 4 3 4

	list<int>::iterator it = l.begin();
	++it;//����д����,���Ըı�itλ��
	cout << *it << endl;//4

	l.begin()++;//����дǰ��û��,���ܸı�l.begin()λ��
	cout << *l.begin() << endl;//1

	cout << *l.begin()++ << endl;//1;дһ��,����ָ����һ��λ��,ֻ�ܽ�д��ǰ��
	cout << *++l.begin() << endl;//4;дһ��,����ָ����һ��λ��,ֻ�ܽ�д��ǰ��

	//ֻ��list��remove,��Ϊ��һ��һ�ڵ�,��������ɾ��,deque��vector̫������û��removeֻ��eraseָ��λ�õ�
	//���list��ֵΪ4��Ԫ������������:
	//=l.remove(4);
	for (list<int>::iterator it = l.begin(); it != l.end();) {
		if (4 == *it) {
			it = l.erase(it);
		}
		else {
			it++;
		}
	}
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";//1 3
	}cout << endl;
	//ֻ��list��reverse,��Ϊlist˫�������е�ַ,�����һ����ʼ��ǰһ����ַ����;vector����,vectorֻ��ǰ��֪������һ���ĵ�ַ,dequeҲ��,ֻ��������β�Ͷ���
	l.reverse();
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";//3 1
	}cout << endl;

	return 0;
}