#include <iostream>
//标准程序库异常用法测试之out of range(可定义输出信息)与bad malloc(不用定义自行判断)
using namespace std;

class Beauty {
public:
	Beauty(int age = 0){
		if (age > 150) {
			throw out_of_range("美女,你是外星人吧!");
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
		cout << "捕捉到一只异常:" << e.what() << endl;
	}

	try {
		for (int i = 0; i < 1024; i++) {//4G
			Beauty(20);
		}
	}
	catch (bad_alloc& e) {
		cout << "太多只造成异常:" << e.what() << endl;
	}


	return 0;
}