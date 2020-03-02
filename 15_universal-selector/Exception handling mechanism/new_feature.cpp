#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

class Beauty {
public:
	Beauty(const char* name = "未知", int age = 0):age(age){
		cout << "调用默认/带参构造函数!" << endl;
		if (strlen(name) < 64) {
			strncpy_s(this->name, 64, name, 64);
		}
	}
	Beauty(const Beauty& src) {
		cout << "调用拷贝构造函数!" << endl;
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
	cout << "拷贝构造函数:";
	Beauty je(la);//只调用了拷贝构造函数,没有再创建新对象
	vector<Beauty> bV(5);
	//若在vector容器中push已有对象,会直接拷贝构造
	bV.push_back(la);//1
	//若在vector容器中push同时创造对象,会默认/带参+拷贝
	bV.push_back(Beauty("Jessica", 20));//2

	//list<int> l;
	//l.push_front(1);
	//deque<int> d;
	//d.push_front(1);
	//vector<int> v;
	//v.push_back(1);//单向队列,不能在push至最前

	//deque list 的emplace功能
	//若在vector容器中emplace直接直接写带参构造的参数	
	cout << line;//第一个emplace会拷贝容量＋已有量
	bV.emplace(bV.end(), "je", 20);//拷贝了之前的俩;默认/带参+拷贝7=5+1+1
	cout << line;
	bV.emplace_back("je", 20);//拷贝了之前的仨(永远比push_back拷贝的要少一个)每次调用都会把先前的所有拷贝到新的大空间;默认/带参
	cout << line;
	bV.push_back(Beauty("Jessica", 20));//默认/带参+拷贝

	return 0;
}