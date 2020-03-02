#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//������ֱ�ӷŶ���,�ᷢ����������
//��Ϊ��ʡ�ռ�,������Ӧ�Ŷ���ָ��
class Beauty {
public:
	Beauty(const char* name = "δ֪", int age = 0):age(age){
		strncpy_s(this->name, 64, name, 64);//ʵ�ʿɴ�ų���Ϊ63�ֽ�
	}
	Beauty(const Beauty& src):age(src.age) {
		strncpy_s(this->name, 64, src.name, 64);//elementByteָ����һ��Ԫ����ռ�ֽ�,sizeInBytesָ��Ҫ�����������ַ�����ռ�ֽ�
		cout << "�������������캯��!" << endl;
	}

public:
	int age;
	char name[64];
};

int main() {
	Beauty b1("Larry", 22);
	Beauty b2("Jessica", 20);

	//vector����
	//vector<Beauty> bV;Ĭ�Ϲ������push,��Ȼû�пռ��!buffer too small/vector subscript out of range
	vector<Beauty> bV(2);//(int n)nΪ�������
	bV[0] = b1;//vectorĬ�Ϲ��첻��������,��Ϊpushǰvector�ռ�Ϊ0
	bV[1] = b2;
	//bV.push_back(b1);
	//bV.push_back(b2);
	vector<Beauty>::iterator it = bV.begin();//������ʵ��Ϊָ��
	for (; it != bV.end(); it++) {
		cout << (*it).name << ":" << (*it).age << " ";
	}

	//vector����ָ��
	vector<Beauty*> bV_p;
	bV_p.push_back(&b1);
	bV_p.push_back(&b2);
	vector<Beauty*>::iterator it_p = bV_p.begin();
	for (; it_p != bV_p.end(); it_p++) {
		cout << (**it_p).name << ":" << (**it_p).age << " ";
	}cout << endl;
		//���±����[i]=.at(i)
	for (unsigned int i = 0; i < bV_p.size(); i++) {
		cout << bV_p[i]->name << ":" << bV_p[i]->age << " ";//ָ�벻Ҫ����,������ʵ���ָ�����ڵ��׵�ַ�Ľ���,������ָ�������׵�ַȻ���ӡָ��ָ��ȫ��
	}cout << endl;

	//�㷨
	vector<int> iV;
	iV.push_back(1);
	iV.push_back(2);
	iV.push_back(1);
	cout <<"vector��1�ĸ���Ϊ:" << count(iV.begin(), iV.end(), 1);

	//�ռ�
	//һ������ռ��С��һ��->����һ�ζ�����Щʡ�ĺ�������Ԫ�ؽ�����������
	vector<int> v;
	cout << "���鸳ֵǰsize:" << v.size();
	cout << "���鸳ֵǰcapacity" << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "��ֵ��size" << v.size();//Ԫ�ظ���
	cout << "��ֵ��capacity" << v.capacity();//�����ɸ���
	cout << "��һ��Ԫ��:" << v.front();//front--back
	v.back() = 666;
	cout << "�޸����һ��Ԫ�غ�:" << v.back();

		//resize+push/pop+insert
	v.resize(2);//ֻ��ǰ2
	v.resize(8);//��Ϊ8��,������=0
	v.resize(8, 888);//��Ϊ8��,������=888

	v.push_back(99);
	//cout << (int)v10.pop_back();��-����ת����Ч
	v.pop_back();

	v.insert(v.begin(), 0);
	v.insert(v.begin(), 3, 0);
	v.insert(v.end(), iV.begin(), iV.end());//end()Ϊ����Ԫ�ص���һ��λ��;��v.end()������û��ֵ,iV.end()������û��ֵ,��Ҳ���ᱻ���ȥ
	vector<int>::iterator itt = v.begin();
	v.insert(itt, itt, itt + 1);//��Ҫ��++,++��ı�itt�����ֵ;���Բ����Լ�


	iV.clear();
	v.erase(v.begin() + 1);
	v.erase(v.begin(), v.end());//v.begin()��const_iterator,��v.rbegin()��reverse_iterator,һ�㺯���ββ�����

								//v.begin() const=v.cbegin()
	vector<int>::const_iterator c_it = v.cbegin();
	for (; c_it < v.cend(); c_it++) {//!=Ҳ��
		//(*c_it)++;iterator is not dereferenceable ���ܳ�����Χ��1����
		cout << *c_it << " ";
	}cout << endl;

	//��ת���
	vector<int>::reverse_iterator r_it = v.rbegin();
	for (; r_it != v.rend(); r_it++) {
		cout << *r_it << " ";
	}cout << endl;

	vector<int> v0;
	if (v0.empty()) {
		cout << "v0����Ϊ0" << endl;
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
		cout << "��v0�������v�ĳ���Ϊ0" << endl;
	}

	v0.insert(v0.insert(v0.end(), 6),7);//�ڲ���6��������ݵ�λ�ò���7,��7��6֮ǰ
	for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++) {
		cout << *it << " ";//1 2 3 4 5 7 6
	}cout << endl;
	//int test[] = { 22,22,22,22,22 };
	//v0.insert(v0.end() - 1, test, test + 3);
	//for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++) {
	//	cout << *it << " ";//1 2 3 4 5 7 22 22 22 6 
	//}cout << endl;

	////ʹ�õ�����ɾ��ָ��ֵ��//deque iterator is not incrementable
	//for (vector<int>::iterator it = v0.begin(); it != v0.end();) {
	//	if (22 == *it) {//vector iterators imcompatible:
	//		it = v0.erase(it);//��������һλ�ú��ر�,��һλ��û�ж�����һλ��,Ҳû������һλ�õĵ�����+1��,ֻ����������
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