#ifndef BLOOD_H
#define BLOOD_H
#include"Point.h"
#include<graphics.h>

class Blood {
public:
	//���캯��
	//���������������Ͻǵ�����
	Blood(int width = 0, int length = 0);
	~Blood();
	int bloodLength;//Ѫ������
	int bloodWidth;//Ѫ�����
};

#endif //BLOOD_H