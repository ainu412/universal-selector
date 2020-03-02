#include <iostream>
#include <set>
//#include <functional>
using namespace std;

class Stu 
{
public:
	Stu(int age):age(age){}
	bool operator<(const Stu& student)const//原less为const,故const中调用的也必须是const
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
// 	// 赋值
// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		
// 		myArray.insert(rand() % 100);
// 	}
// 	myArray.insert(0);
// 	myArray.insert(0);
// 
// 	multiset<int> myArray1(myArray.begin(), myArray.end());//拷贝构造
// 	//multiset<int> myArray2(myArray);
// 	multiset<int> myArray3;//赋值构造
// 	myArray3 = myArray1;
// 	
// 	// 打印
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

	// 类函数最好单独创建对象用
// 	FuncStu funStu;
// 	ret = funStu(Stu(22), Stu(20));

	for (set<Stu, FuncStu>::iterator i = student.begin(); i != student.end(); i++)
	{
		cout << i->age << " ";
	}cout << endl;

	// 查看set插入是否成功
	set<int> setInt;
	setInt.insert(10);
	setInt.insert(20);
	pair<set<int>::iterator, bool> iRet = setInt.insert(11);
	cout << "first:" << *iRet.first << endl;//iterator处于插入元素的位置
	cout << "second (bool):" << iRet.second << endl;

	// setInt.find返回迭代器,如果没找到就回到找的最后的end
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