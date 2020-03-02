#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vld.h>
using namespace std;
#define BUFFER_SIZE 1024//字节数
#define ELEMENT_SIZE 1
class Beauty {
public:
	Beauty(){}
	~Beauty(){}
	Beauty(const Beauty& other){}
};
//c++二进制拷贝
void cppCopyBinary(const char* dest, const char* src) {//无法检测是否出现错误..
	std::ifstream input(src, ios::binary);
	std::ofstream output(dest, ios::binary);

	output << input.rdbuf();
}
//C二进制拷贝
string cCopyBinary(const char* dest, const char* src) {
	FILE* destF_p = NULL, * srcF_p = NULL;
	fopen_s(&srcF_p, src, "rb");
	if (!srcF_p) {
		return "源文件打开失败!";
	}

	fopen_s(&destF_p, dest, "wb");
	if (!destF_p) {
		fclose(srcF_p);
		return "目标文件打开失败!";
	}

	char buffer[BUFFER_SIZE];
	int readLen = fread_s(buffer, BUFFER_SIZE, ELEMENT_SIZE, BUFFER_SIZE, srcF_p);
	if (readLen <= 0) {
		fclose(srcF_p);
		fclose(destF_p);
		return "源文件读取失败!";
	}
	int writeLen = fwrite(buffer, ELEMENT_SIZE, readLen, destF_p);
	if (readLen != writeLen) {
		fclose(srcF_p);
		fclose(destF_p);
		return "目标文件拷贝失败!";
	}
	fclose(srcF_p);
	fclose(destF_p);
	return "成功!";
}
void cCopyBinary1(const char* dest, const char* src) {
	FILE* destF_p = NULL, * srcF_p = NULL;
	fopen_s(&srcF_p, src, "rb");
	if (!srcF_p) {
		throw "源文件打开失败!";
	}

	fopen_s(&destF_p, dest, "wb");
	if (!destF_p) {
		fclose(srcF_p);
		throw "目标文件打开失败!";
	}

	char buffer[BUFFER_SIZE];
	int readLen = fread_s(buffer, BUFFER_SIZE, ELEMENT_SIZE, BUFFER_SIZE, srcF_p);
	if (readLen <= 0) {
		fclose(srcF_p);
		fclose(destF_p);
		throw "源文件读取失败!";
	}
	int writeLen = fwrite(buffer, ELEMENT_SIZE, readLen, destF_p);
	if (readLen != writeLen) {
		fclose(srcF_p);
		fclose(destF_p);
		throw "目标文件拷贝失败!";
	}
	fclose(srcF_p);
	fclose(destF_p);
	throw "成功!";
}

void cCopyBinary2(const char* dest, const char* src) throw(char, int)//最好异常接口声明下,虽然C11编译器检测不出来!但可以起到提示/保证作用
{
	FILE* destF_p = NULL, * srcF_p = NULL;
	fopen_s(&srcF_p, src, "rb");
	if (!srcF_p) {
		//throw Beauty();
		throw new string("源文件打开失败!");
	}

	fopen_s(&destF_p, dest, "wb");
	if (!destF_p) {
		fclose(srcF_p);
		throw new string("目标文件打开失败!");		
	}

	char buffer[BUFFER_SIZE];
	int readLen = fread_s(buffer, BUFFER_SIZE, ELEMENT_SIZE, BUFFER_SIZE, srcF_p);
	if (readLen <= 0) {
		fclose(srcF_p);
		fclose(destF_p);
		throw new string("源文件读取失败!");
	}
	int writeLen = fwrite(buffer, ELEMENT_SIZE, readLen, destF_p);
	if (readLen != writeLen) {
		fclose(srcF_p);
		fclose(destF_p);
		throw -1;
	}
	fclose(srcF_p);
	fclose(destF_p);
	throw 0;
}
//可以多次扔
void twoTimes() {
	try {
		cCopyBinary1("D:/tmp/dest.txt", "D:/tmp/src.txt");
	}
	catch (...) {
		throw;
	}
}
int main() {

	cppCopyBinary("dest.txt", "src.txt");
	cout << cCopyBinary("D:/tmp/dest.txt", "D:/tmp/src.txt") << endl;//注意只有硬盘名后加冒号
	
	//异常捕捉机制：
	//一旦执行throw立刻转到catch，不再进行throw下面内容；
	//可设置不同类型throw值，但一次只能throw一个值。
	//若一个类型有多个值，需拷贝，可动态内存分配后指针传递。
	//catch顺次进行，只执行一个匹配分支；
	//catch(...)通配。
	//如果throw float无匹配，会中断（缺省功能会调用abort终止程序），并显示Microsoft C++异常：内存位置xxxxxx处的float
	//最近的catch才能拿到throw，若最近的catch再throw，才会throw给次近的catch
	//若throw;上次接到啥就扔啥.要是没接到就出错!
	//一般只throw异常!
	cout << "throw char，形参char*，实参char*申请内存，被赋值:";
	try {
		twoTimes();
	}
	catch (const char* err) {//err相当于处于缓冲区,需要再分配动态内存至error
		//char* error = new char[strlen(err) + 1];指针接,可以不分配内存...,就是必须const char*
		//strcpy_s(error, strlen(err) + 1, err);

		cerr << err << endl;

		//delete[] error;
	}

	//"xxxx"传递值类型为char不能传给string
	//try {
	//	cCopyBinary1("D:/tmp/dest.txt", "D:/tmp/src.txt");
	//}
	//catch (string err) {//err相当于处于缓冲区,需要再分配动态内存至error
	//	cout << "捕捉到字符串异常:" << err.c_str() << endl;
	//}

	cout << "throw new string/new char(char)，形参string*，直接输出:";//创建new异常元素
	try {
		cCopyBinary2("D:/tmp/dest.txt", "D:/tmp/src.txt");
		//cCopyBinary12("D:/tmp/dest.txt", "D:/tmp/src.txt");
	}
	catch (Beauty& beauty) {
		cout << "捕捉到类Beauty异常!" << endl;
	}
	catch (string* err) {//err相当于处于缓冲区,需要再分配动态内存至error
		cout << "捕捉到字符串异常:" << err->c_str() << endl;
		delete err;
	}
	catch (int n) {
		if (!n) {//数字可直接传值
			cout << "捕捉到数字0:" << "成功!" << endl;
		}
	}

	return 0;
}

//最佳方式:int直接扔
//			字符串直接"xxx"--const char*接 		(若new string初始化--string+*接,需记得再delete err)不能引用接,因为新对象还没创建哩
//			类直接Beauty()初始化--Beauty&接;	 (new Beauty则指针接,记得释放