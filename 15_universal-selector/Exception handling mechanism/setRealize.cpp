#include "setComparer.hpp"
#include <Windows.h>//WINAPI或__stdcall必备
#include <process.h>
#if 0
int main()
{
	setComparer<int> setInt;

	for (size_t i = 0; i < 10; i++)
	{
		setInt.insert(100 - 10 * i);
	}
	cout << setInt.size() << endl;
	setInt.erase(10);
	cout << "Max=";
	pair<int, bool> ret = setInt.getMax();
	if (ret.second)
	{
		cout << ret.first;
	}
	cout << "Min=";
	ret = setInt.getMin();
	if (ret.second)
	{
		cout << ret.first;
	}



	return 0;
}
#endif

//多线程
//全局变量从内存中取
long long volatile g = 0;
unsigned WINAPI add1(void* arg)//必须要带参数!!
{
	g++;
	return 0;
}
unsigned WINAPI sub1(void* arg)
{
	g--;
	return 0;
}

// int main()
// {
// 	HANDLE thread[2];
// 	for (int i=0; i < 500; i++)
// 	{
// 		if(i%2)
// 			thread[0] = (HANDLE)_beginthreadex(NULL, 0, add1, NULL, 0, NULL);
// 		else
// 			thread[1] = (HANDLE)_beginthreadex(NULL, 0, sub1, NULL, 0, NULL);
// 	}
// 	WaitForMultipleObjects(2, thread, true, INFINITE);
// 	printf("g=%lld", g);//1
	//CloseHandle(thread);没有create就不用关闭


// 	return 0;
// }
#include <iostream>
void main()
{
	union {
		int test;
		char c;
	};
	test = 5;
	c = 'a';
	std::cout << test << " " << c;
}