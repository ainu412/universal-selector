#include "Vector.hpp"
#include <vld.h>

int main() {
	cout << "1.存储类类型数据" << endl;
	Vector<Beauty*> btV(2);//若Vector<Beauty> btV(2);btV[0] = la;拷贝全部耗费空间太大;Vector类内会根据Beauty大小
						   //仅分配了Beauty*的内存,故指针还要另外分配对象内存
	//Beauty la(22, "Larry");
	//Beauty je(20, "Jessica");
	btV[0] = new Beauty(22, "Larry");//可同时初始化,避免创造新la和je浪费内存
	//btV[0] = &la;//*btv[0]=la;×放地址就行
	btV[1] = new Beauty(20, "Jessica");
	//btV[1] = &je;
	for (int i = 0; i < btV.getCnt(); i++) {
		cout << *btV[i];
	}cout << endl;
	delete btV[0];
	delete btV[1];

	cout << "2.存储int类型数据" << endl;
	//对默认构造函数存储元素赋值为1-5
	Vector<int> intV(5);//integar vector
	for (int i = 0; i < intV.getCnt(); i++) {
		intV[i] = i + 1;
	}

	//打印数组元素
	cout << intV;
	
	cout << "3.存储float类型数据" << endl;
	Vector<float> floatV(5);//integar vector
	for (int i = 0; i < floatV.getCnt(); i++) {
		floatV[i] = (i + 1) * 0.1f;
	}
	cout << floatV;

	//拷贝类
	cout << "4.拷贝类" << endl;
	Vector<int> intV1(intV);
	cout << intV1;

	//赋值类
	cout << "5.赋值类" << endl;
	Vector<int> intV2(2);
	intV2 = intV;
	cout << intV2;

	return 0;
}