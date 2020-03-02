#include <iostream>
using namespace std;
//定义一个Vector,存储cnt指定数量的int类型数字,对于cnt的不同情况报错cnt
//可用于优化项目Vector
class errSizeException {
public:
	errSizeException() {
		cout << "调用默认构造函数!" << endl;
	}
	errSizeException(const errSizeException&) {
		cout << "调用拷贝构造函数!" << endl;
	}
	virtual void errors() {
		cout << __FUNCTION__ << endl;
	}
};
class errTooBigException :public errSizeException {
public:
	void errors() {
		cout << __FUNCTION__ << endl;
	}
};
class errTooSmallException :public errSizeException {
public:
	void errors() {
		cout << __FUNCTION__ << endl;
	}
};
class errNegativeException :public errSizeException {
public:
	void errors() {
		cout << __FUNCTION__ << endl;
	}
};
class errZeroException :public errSizeException {
public:
	void errors() {
		cout << __FUNCTION__ << endl;
	}
};
class Vector {
public:
	Vector(int cnt = 0) {
		if (0 == cnt) {
			throw errZeroException();
		}
		else if (cnt < 0) {
			throw errNegativeException();
		}
		else if (cnt > 1000) {
			throw errTooBigException();
		}
		else if (cnt < 10) {
			throw errTooSmallException();
		}

		p = new int[cnt];
		this->cnt = cnt;
	}

	int getCnt() {
		return cnt;
	}
	int& operator[](int i){//记得返回引用,i=0~999,i+1=1~1000
		int cnt = i + 1;
		if (0 == cnt) {
			throw errZeroException();
		}
		else if (cnt  < 0) {
			throw errNegativeException();
		}
		else if (cnt > 1000) {
			throw errTooBigException();
		}

		return p[i];
	}
	~Vector() {
		if (p) {
			delete[] p;
		}
	}
private:
	int cnt;
	int* p;
};

int main() {

	Vector my(10);
	for (int i = 0; i < my.getCnt(); i++) {
		my[i] = i + 1;
		cout << my[i] << " ";
	}cout << endl;

	try {
		Vector myV(0);
	}
	catch(errSizeException& err){//throw时候直接初始化,只调用默认/带参构造函数,不会调用拷贝
		err.errors();
	}

	return 0;
}