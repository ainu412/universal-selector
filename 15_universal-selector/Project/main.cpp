#include "Vector.hpp"

int main() {

	Vector<Beauty*> btV(2);
	Beauty la(22, "Larry");
	Beauty je(20, "Jessica");
	btV[0] = &la;//*btv[0]=la;���ŵ�ַ����
	btV[1] = &je;
	for (int i = 0; i < btV.getCnt(); i++) {
		cout << *btV[i];
	}

	//��Ĭ�Ϲ��캯���洢Ԫ�ظ�ֵΪ1-5
	Vector<int> intV(5);//integar vector
	for (int i = 0; i < intV.getCnt(); i++) {
		intV[i] = i + 1;
	}

	//��ӡ����Ԫ��
	cout << intV;

	Vector<float> floatV(5);//integar vector
	for (int i = 0; i < floatV.getCnt(); i++) {
		floatV[i] = (i + 1) * 0.1f;
	}
	cout << floatV;

	//������
	Vector<int> intV1(intV);
	cout << intV1;

	//��ֵ��
	Vector<int> intV2(2);
	intV2 = intV;
	cout << intV2;

	return 0;
}