#include <iostream>
//��׼������쳣�÷�����֮out of range(�ɶ��������Ϣ)��bad malloc(���ö��������ж�)
using namespace std;

class Beauty {
public:
	Beauty(int age = 0){
		if (age > 150) {
			throw out_of_range("��Ů,���������˰�!");
		}
		int* p = new int[1024 * 1024];//4M
	}
private:
	int age;
};
int main() {
	try {
		Beauty(200);
	}
	catch(out_of_range& e){
		cout << "��׽��һֻ�쳣:" << e.what() << endl;
	}

	try {
		for (int i = 0; i < 1024; i++) {//4G
			Beauty(20);
		}
	}
	catch (bad_alloc& e) {
		cout << "̫��ֻ����쳣:" << e.what() << endl;
	}


	return 0;
}