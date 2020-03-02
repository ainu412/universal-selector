#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//容器中直接放对象,会发生拷贝构造
//故为节省空间,容器中应放对象指针
class Beauty {
public:
	Beauty(const char* name = "未知", int age = 0):age(age){
		strncpy_s(this->name, 64, name, 64);//实际可存放长度为63字节
	}
	Beauty(const Beauty& src):age(src.age) {
		strncpy_s(this->name, 64, src.name, 64);//elementByte指的是一个元素所占字节,sizeInBytes指的要拷贝的整个字符串所占字节
		cout << "调用啦拷贝构造函数!" << endl;
	}

public:
	int age;
	char name[64];
};

int main() {
	Beauty b1("Larry", 22);
	Beauty b2("Jessica", 20);

	//vector对象
	//vector<Beauty> bV;默认构造必须push,不然没有空间的!buffer too small/vector subscript out of range
	vector<Beauty> bV(2);//(int n)n为存入个数
	bV[0] = b1;//vector默认构造不能这样存,因为push前vector空间为0
	bV[1] = b2;
	//bV.push_back(b1);
	//bV.push_back(b2);
	vector<Beauty>::iterator it = bV.begin();//迭代器实际为指针
	for (; it != bV.end(); it++) {
		cout << (*it).name << ":" << (*it).age << " ";
	}

	//vector对象指针
	vector<Beauty*> bV_p;
	bV_p.push_back(&b1);
	bV_p.push_back(&b2);
	vector<Beauty*>::iterator it_p = bV_p.begin();
	for (; it_p != bV_p.end(); it_p++) {
		cout << (**it_p).name << ":" << (**it_p).age << " ";
	}cout << endl;
		//或下标访问[i]=.at(i)
	for (unsigned int i = 0; i < bV_p.size(); i++) {
		cout << bV_p[i]->name << ":" << bV_p[i]->age << " ";//指针不要解引,否则访问的是指针所在的首地址的解引,而不是指针所在首地址然后打印指针指向全体
	}cout << endl;

	//算法
	vector<int> iV;
	iV.push_back(1);
	iV.push_back(2);
	iV.push_back(1);
	cout <<"vector中1的个数为:" << count(iV.begin(), iV.end(), 1);

	//空间
	//一次扩充空间大小不一定->可能一次多扩容些省的后面再有元素进来了又扩；
	vector<int> v;
	cout << "数组赋值前size:" << v.size();
	cout << "数组赋值前capacity" << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "赋值后size" << v.size();//元素个数
	cout << "赋值后capacity" << v.capacity();//可容纳个数
	cout << "第一个元素:" << v.front();//front--back
	v.back() = 666;
	cout << "修改最后一个元素后:" << v.back();

		//resize+push/pop+insert
	v.resize(2);//只留前2
	v.resize(8);//扩为8个,新扩的=0
	v.resize(8, 888);//扩为8个,新扩的=888

	v.push_back(99);
	//cout << (int)v10.pop_back();×-类型转换无效
	v.pop_back();

	v.insert(v.begin(), 0);
	v.insert(v.begin(), 3, 0);
	v.insert(v.end(), iV.begin(), iV.end());//end()为结束元素的下一个位置;故v.end()本来就没有值,iV.end()本来就没有值,它也不会被插进去
	vector<int>::iterator itt = v.begin();
	v.insert(itt, itt, itt + 1);//不要用++,++会改变itt本身的值;可以插入自己


	iV.clear();
	v.erase(v.begin() + 1);
	v.erase(v.begin(), v.end());//v.begin()是const_iterator,而v.rbegin()是reverse_iterator,一般函数形参不能用

								//v.begin() const=v.cbegin()
	vector<int>::const_iterator c_it = v.cbegin();
	for (; c_it < v.cend(); c_it++) {//!=也行
		//(*c_it)++;iterator is not dereferenceable 不能超过范围加1解引
		cout << *c_it << " ";
	}cout << endl;

	//逆转输出
	vector<int>::reverse_iterator r_it = v.rbegin();
	for (; r_it != v.rend(); r_it++) {
		cout << *r_it << " ";
	}cout << endl;

	vector<int> v0;
	if (v0.empty()) {
		cout << "v0长度为0" << endl;
	}

	vector<int> vv;
	vv.push_back(1);
	vv.push_back(2);
	vv.push_back(3);
	vv.push_back(4);
	vv.push_back(5);
	vv.swap(v0);
	for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++) {
		cout << *it << " ";
	}cout << endl;
	
	if (vv.empty()) {
		cout << "和v0交换后的v的长度为0" << endl;
	}

	v0.insert(v0.insert(v0.end(), 6),7);//在插入6这个新数据的位置插入7,故7在6之前
	for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++) {
		cout << *it << " ";//1 2 3 4 5 7 6
	}cout << endl;
	//int test[] = { 22,22,22,22,22 };
	//v0.insert(v0.end() - 1, test, test + 3);
	//for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++) {
	//	cout << *it << " ";//1 2 3 4 5 7 22 22 22 6 
	//}cout << endl;

	////使用迭代器删除指定值项//deque iterator is not incrementable
	//for (vector<int>::iterator it = v0.begin(); it != v0.end();) {
	//	if (22 == *it) {//vector iterators imcompatible:
	//		it = v0.erase(it);//擦除后下一位置很特别,下一位置没有顶替这一位置,也没有在这一位置的迭代器+1处,只能这样返回
	//	}
	//	else {
	//		it++;
	//	}
	//}cout << endl;
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	
	return 0;
}