#include "Vector.hpp"
#include <vld.h>

int main() {
	cout << "1.�洢����������" << endl;
	Vector<Beauty*> btV(2);//��Vector<Beauty> btV(2);btV[0] = la;����ȫ���ķѿռ�̫��;Vector���ڻ����Beauty��С
						   //��������Beauty*���ڴ�,��ָ�뻹Ҫ�����������ڴ�
	//Beauty la(22, "Larry");
	//Beauty je(20, "Jessica");
	btV[0] = new Beauty(22, "Larry");//��ͬʱ��ʼ��,���ⴴ����la��je�˷��ڴ�
	//btV[0] = &la;//*btv[0]=la;���ŵ�ַ����
	btV[1] = new Beauty(20, "Jessica");
	//btV[1] = &je;
	for (int i = 0; i < btV.getCnt(); i++) {
		cout << *btV[i];
	}cout << endl;
	delete btV[0];
	delete btV[1];

	cout << "2.�洢int��������" << endl;
	//��Ĭ�Ϲ��캯���洢Ԫ�ظ�ֵΪ1-5
	Vector<int> intV(5);//integar vector
	for (int i = 0; i < intV.getCnt(); i++) {
		intV[i] = i + 1;
	}

	//��ӡ����Ԫ��
	cout << intV;
	
	cout << "3.�洢float��������" << endl;
	Vector<float> floatV(5);//integar vector
	for (int i = 0; i < floatV.getCnt(); i++) {
		floatV[i] = (i + 1) * 0.1f;
	}
	cout << floatV;

	//������
	cout << "4.������" << endl;
	Vector<int> intV1(intV);
	cout << intV1;

	//��ֵ��
	cout << "5.��ֵ��" << endl;
	Vector<int> intV2(2);
	intV2 = intV;
	cout << intV2;

	return 0;
}