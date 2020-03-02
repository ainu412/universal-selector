#include <iostream>
#include <set>
//#include <functional>
using namespace std;

class Stu 
{
public:
	Stu(int age):age(age){}
	bool operator<(const Stu& student)const//ԭlessΪconst,��const�е��õ�Ҳ������const
	{
		return this->age < student.age;
	}

	int age;
	string name;
};

class FuncStu
{
public:
	bool operator()(const Stu& stuL, const Stu& stuR)
	{
		return stuL.age > stuR.age;
	}
};
int main()
{
// 	multiset<int,greater <int>> myArray;
// 	// ��ֵ
// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		
// 		myArray.insert(rand() % 100);
// 	}
// 	myArray.insert(0);
// 	myArray.insert(0);
// 
// 	multiset<int> myArray1(myArray.begin(), myArray.end());//��������
// 	//multiset<int> myArray2(myArray);
// 	multiset<int> myArray3;//��ֵ����
// 	myArray3 = myArray1;
// 	
// 	// ��ӡ
// 	for (multiset<int>::iterator i = myArray.begin(); i != myArray.end(); i++)
// 	{
// 		cout << *i << " ";
// 	}cout << endl;
// 
// 	for (multiset<int>::iterator i = myArray1.begin(); i != myArray1.end(); i++)
// 	{
// 		cout << *i << " ";
// 	}cout << endl;
// 
// // 	for (multiset<int>::iterator i = myArray2.begin(); i != myArray2.end(); i++)
// // 	{
// // 		cout << *i << " ";
// // 	}cout << endl;
// 
// 	for (multiset<int>::iterator i = myArray3.begin(); i != myArray3.end(); i++)
// 	{
// 		cout << *i << " ";
// 	}cout << endl;

	set<Stu> student;
	student.insert(Stu(22));
	student.insert(Stu(20));

	// �ຯ����õ�������������
// 	FuncStu funStu;
// 	ret = funStu(Stu(22), Stu(20));

	for (set<Stu, FuncStu>::iterator i = student.begin(); i != student.end(); i++)
	{
		cout << i->age << " ";
	}cout << endl;

	// �鿴set�����Ƿ�ɹ�
	set<int> setInt;
	setInt.insert(10);
	setInt.insert(20);
	pair<set<int>::iterator, bool> iRet = setInt.insert(11);
	cout << "first:" << *iRet.first << endl;//iterator���ڲ���Ԫ�ص�λ��
	cout << "second (bool):" << iRet.second << endl;

	// setInt.find���ص�����,���û�ҵ��ͻص��ҵ�����end
	set<int>::iterator it = setInt.find(20);
	if (it==setInt.end())
	{
		cout << "Not found!" << endl;
	} 
	else
	{
		cout << "Found" << *it << endl;
	}

	//
	return 0;
}