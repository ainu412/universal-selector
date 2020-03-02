#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vld.h>
using namespace std;
#define BUFFER_SIZE 1024//�ֽ���
#define ELEMENT_SIZE 1
class Beauty {
public:
	Beauty(){}
	~Beauty(){}
	Beauty(const Beauty& other){}
};
//c++�����ƿ���
void cppCopyBinary(const char* dest, const char* src) {//�޷�����Ƿ���ִ���..
	std::ifstream input(src, ios::binary);
	std::ofstream output(dest, ios::binary);

	output << input.rdbuf();
}
//C�����ƿ���
string cCopyBinary(const char* dest, const char* src) {
	FILE* destF_p = NULL, * srcF_p = NULL;
	fopen_s(&srcF_p, src, "rb");
	if (!srcF_p) {
		return "Դ�ļ���ʧ��!";
	}

	fopen_s(&destF_p, dest, "wb");
	if (!destF_p) {
		fclose(srcF_p);
		return "Ŀ���ļ���ʧ��!";
	}

	char buffer[BUFFER_SIZE];
	int readLen = fread_s(buffer, BUFFER_SIZE, ELEMENT_SIZE, BUFFER_SIZE, srcF_p);
	if (readLen <= 0) {
		fclose(srcF_p);
		fclose(destF_p);
		return "Դ�ļ���ȡʧ��!";
	}
	int writeLen = fwrite(buffer, ELEMENT_SIZE, readLen, destF_p);
	if (readLen != writeLen) {
		fclose(srcF_p);
		fclose(destF_p);
		return "Ŀ���ļ�����ʧ��!";
	}
	fclose(srcF_p);
	fclose(destF_p);
	return "�ɹ�!";
}
void cCopyBinary1(const char* dest, const char* src) {
	FILE* destF_p = NULL, * srcF_p = NULL;
	fopen_s(&srcF_p, src, "rb");
	if (!srcF_p) {
		throw "Դ�ļ���ʧ��!";
	}

	fopen_s(&destF_p, dest, "wb");
	if (!destF_p) {
		fclose(srcF_p);
		throw "Ŀ���ļ���ʧ��!";
	}

	char buffer[BUFFER_SIZE];
	int readLen = fread_s(buffer, BUFFER_SIZE, ELEMENT_SIZE, BUFFER_SIZE, srcF_p);
	if (readLen <= 0) {
		fclose(srcF_p);
		fclose(destF_p);
		throw "Դ�ļ���ȡʧ��!";
	}
	int writeLen = fwrite(buffer, ELEMENT_SIZE, readLen, destF_p);
	if (readLen != writeLen) {
		fclose(srcF_p);
		fclose(destF_p);
		throw "Ŀ���ļ�����ʧ��!";
	}
	fclose(srcF_p);
	fclose(destF_p);
	throw "�ɹ�!";
}

void cCopyBinary2(const char* dest, const char* src) throw(char, int)//����쳣�ӿ�������,��ȻC11��������ⲻ����!����������ʾ/��֤����
{
	FILE* destF_p = NULL, * srcF_p = NULL;
	fopen_s(&srcF_p, src, "rb");
	if (!srcF_p) {
		//throw Beauty();
		throw new string("Դ�ļ���ʧ��!");
	}

	fopen_s(&destF_p, dest, "wb");
	if (!destF_p) {
		fclose(srcF_p);
		throw new string("Ŀ���ļ���ʧ��!");		
	}

	char buffer[BUFFER_SIZE];
	int readLen = fread_s(buffer, BUFFER_SIZE, ELEMENT_SIZE, BUFFER_SIZE, srcF_p);
	if (readLen <= 0) {
		fclose(srcF_p);
		fclose(destF_p);
		throw new string("Դ�ļ���ȡʧ��!");
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
//���Զ����
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
	cout << cCopyBinary("D:/tmp/dest.txt", "D:/tmp/src.txt") << endl;//ע��ֻ��Ӳ�������ð��
	
	//�쳣��׽���ƣ�
	//һ��ִ��throw����ת��catch�����ٽ���throw�������ݣ�
	//�����ò�ͬ����throwֵ����һ��ֻ��throwһ��ֵ��
	//��һ�������ж��ֵ���追�����ɶ�̬�ڴ�����ָ�봫�ݡ�
	//catch˳�ν��У�ִֻ��һ��ƥ���֧��
	//catch(...)ͨ�䡣
	//���throw float��ƥ�䣬���жϣ�ȱʡ���ܻ����abort��ֹ���򣩣�����ʾMicrosoft C++�쳣���ڴ�λ��xxxxxx����float
	//�����catch�����õ�throw���������catch��throw���Ż�throw���ν���catch
	//��throw;�ϴνӵ�ɶ����ɶ.Ҫ��û�ӵ��ͳ���!
	//һ��ֻthrow�쳣!
	cout << "throw char���β�char*��ʵ��char*�����ڴ棬����ֵ:";
	try {
		twoTimes();
	}
	catch (const char* err) {//err�൱�ڴ��ڻ�����,��Ҫ�ٷ��䶯̬�ڴ���error
		//char* error = new char[strlen(err) + 1];ָ���,���Բ������ڴ�...,���Ǳ���const char*
		//strcpy_s(error, strlen(err) + 1, err);

		cerr << err << endl;

		//delete[] error;
	}

	//"xxxx"����ֵ����Ϊchar���ܴ���string
	//try {
	//	cCopyBinary1("D:/tmp/dest.txt", "D:/tmp/src.txt");
	//}
	//catch (string err) {//err�൱�ڴ��ڻ�����,��Ҫ�ٷ��䶯̬�ڴ���error
	//	cout << "��׽���ַ����쳣:" << err.c_str() << endl;
	//}

	cout << "throw new string/new char(char)���β�string*��ֱ�����:";//����new�쳣Ԫ��
	try {
		cCopyBinary2("D:/tmp/dest.txt", "D:/tmp/src.txt");
		//cCopyBinary12("D:/tmp/dest.txt", "D:/tmp/src.txt");
	}
	catch (Beauty& beauty) {
		cout << "��׽����Beauty�쳣!" << endl;
	}
	catch (string* err) {//err�൱�ڴ��ڻ�����,��Ҫ�ٷ��䶯̬�ڴ���error
		cout << "��׽���ַ����쳣:" << err->c_str() << endl;
		delete err;
	}
	catch (int n) {
		if (!n) {//���ֿ�ֱ�Ӵ�ֵ
			cout << "��׽������0:" << "�ɹ�!" << endl;
		}
	}

	return 0;
}

//��ѷ�ʽ:intֱ����
//			�ַ���ֱ��"xxx"--const char*�� 		(��new string��ʼ��--string+*��,��ǵ���delete err)�������ý�,��Ϊ�¶���û������
//			��ֱ��Beauty()��ʼ��--Beauty&��;	 (new Beauty��ָ���,�ǵ��ͷ�