#include <iostream>
#include <vector>
using namespace std;

//�ϳɵĿ������캯��:���ڴ�������
//v3(v2)
int main() {
	//��ʼ��
	vector<int> v1;
	v1.push_back(1);
	cout << v1[0] << endl;

	vector<int> v11(11);//int�ͷ���ռ��,Ĭ�ϳ�ʼ��Ϊ0;//һ���Է���Ч�ʸ�
	for (unsigned int i = 0; i < v11.size(); i++) {
		cout << v11[i] << " ";//0
	}cout << endl;

	vector<int> v111(11,111);
	for (unsigned int i = 0; i < v111.size(); i++) {
		cout << v111[i] << " ";//11��111
	}cout << endl;

	//����
	vector<int> v2(v1);//=vector<int> v2 = v1;
	cout << v2[0] << endl;

	int arr[] = { 0, 1, 2, 3, 4 };
	//vector<int> v22(arr);���ܿ�������
	vector<int> v22(arr, arr + 2);//0 1//end()���Ĳ�����
	for (unsigned int i = 0; i < v22.size(); i++) {
		cout << v22[i] << " ";
	}cout << endl;

	vector<int> v222(v22.begin(), v22.end());//0 1
	for (unsigned int i = 0; i < v222.size(); i++) {
		cout << v222[i] << " ";
	}cout << endl;

	vector<int> v2222(v22.begin(), v22.begin() + 1);//end��������
	for (unsigned int i = 0; i < v2222.size(); i++) {
		cout << v2222[i] << " ";//0
	}cout << endl;

	//��ֵ
	vector<int> v3;
	v3 = v222;
	for (unsigned int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";//0
	}cout << endl;

	v3.assign(arr, arr + 4);
	for (unsigned int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";//0
	}cout << endl;

	v3.assign(6, 666);
	for (unsigned int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";//0
	}cout << endl;

	v3.assign(v111.begin(), v111.begin() + 3);
	for (unsigned int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";//0
	}cout << endl;

	return 0;
}