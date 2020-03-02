#include <list>
#include <iostream>
#include <deque>
using namespace std;

int main() {
	list<int > l(3);//只有初始化时可以用,不能赋值	l.assign(3);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";//0 0 0
	}cout << endl;
	l.assign(1, 1);
	l.push_back(4);
	l.push_back(3);
	l.push_back(4);//1 4 3 4

	list<int>::iterator it = l.begin();
	++it;//单独写有用,可以改变it位置
	cout << *it << endl;//4

	l.begin()++;//单独写前后都没用,不能改变l.begin()位置
	cout << *l.begin() << endl;//1

	cout << *l.begin()++ << endl;//1;写一起,就是指后面一个位置,只能紧写在前面
	cout << *++l.begin() << endl;//4;写一起,就是指后面一个位置,只能紧写在前面

	//只有list能remove,因为它一节一节的,可以轻松删除,deque和vector太紧密了没法remove只能erase指定位置的
	//清除list中值为4的元素有两个方法:
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
	//只有list有reverse,因为list双方都存有地址,由最后一个开始报前一个地址即可;vector不行,vector只有前面知道后面一个的地址,deque也是,只是有两个尾巴而已
	l.reverse();
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";//3 1
	}cout << endl;

	return 0;
}