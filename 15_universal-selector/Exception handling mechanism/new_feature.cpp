#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

class Beauty {
public:
	Beauty(const char* name = "δ֪", int age = 0):age(age){
		cout << "����Ĭ��/���ι��캯��!" << endl;
		if (strlen(name) < 64) {
			strncpy_s(this->name, 64, name, 64);
		}
	}
	Beauty(const Beauty& src) {
		cout << "���ÿ������캯��!" << endl;
		age = src.age;
	}
public:
	int age;
	char name[64];
};

int main() {
	string line(100, '-');
	//vector push
	Beauty la("Larry", 22);
	cout << "�������캯��:";
	Beauty je(la);//ֻ�����˿������캯��,û���ٴ����¶���
	vector<Beauty> bV(5);
	//����vector������push���ж���,��ֱ�ӿ�������
	bV.push_back(la);//1
	//����vector������pushͬʱ�������,��Ĭ��/����+����
	bV.push_back(Beauty("Jessica", 20));//2

	//list<int> l;
	//l.push_front(1);
	//deque<int> d;
	//d.push_front(1);
	//vector<int> v;
	//v.push_back(1);//�������,������push����ǰ

	//deque list ��emplace����
	//����vector������emplaceֱ��ֱ��д���ι���Ĳ���	
	cout << line;//��һ��emplace�´��������������
	bV.emplace(bV.end(), "je", 20);//������֮ǰ����;Ĭ��/����+����7=5+1+1
	cout << line;
	bV.emplace_back("je", 20);//������֮ǰ����(��Զ��push_back������Ҫ��һ��)ÿ�ε��ö������ǰ�����п������µĴ�ռ�;Ĭ��/����
	cout << line;
	bV.push_back(Beauty("Jessica", 20));//Ĭ��/����+����

	return 0;
}