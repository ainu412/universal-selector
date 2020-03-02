#include <iostream>
using namespace std;
//����һ��Vector,�洢cntָ��������int��������,����cnt�Ĳ�ͬ�������cnt
//�������Ż���ĿVector
class errSizeException {
public:
	errSizeException() {
		cout << "����Ĭ�Ϲ��캯��!" << endl;
	}
	errSizeException(const errSizeException&) {
		cout << "���ÿ������캯��!" << endl;
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
	int& operator[](int i){//�ǵ÷�������,i=0~999,i+1=1~1000
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
	catch(errSizeException& err){//throwʱ��ֱ�ӳ�ʼ��,ֻ����Ĭ��/���ι��캯��,������ÿ���
		err.errors();
	}

	return 0;
}