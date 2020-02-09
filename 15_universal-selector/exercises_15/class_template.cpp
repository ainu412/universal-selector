#include <iostream>
using namespace std;
//定义一个类模板A,可获得其参数a,观察什么地方添加类说明,使其转化为类模板
//再定义一个类模板B,作为其父类=
//子模A和父模B不需显式说明继承类型
//子模A和父B  不需显式说明继承类型
//父模A和子B    需显式说明继承类型
class B : public A<int>
{				  //^两处记得对应,不然子类无法使用父类的模板数据成员
public:			
	B(int b = 0, int a = 0) :A(a), b(b) {}//任意一处:从原有数据类型改为T
				//^
	int b;
};
template <typename T>
class A 
{
public:
	A(T a = 0):a(a){}//任意一处:从原有数据类型改为T

	T a;
};

int main() {
	A<int> a1;//未知继承类类初始化时要分配内存空间->必须显式说明数据类型
	B b1(1,'a');
	cout << b1.a << endl;

	return 0;
}