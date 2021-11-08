#ifndef NODE_H
#define NODE_H
#include<graphics.h>
#include"Point.h"
#include"Blood.h"

class Node {
public:
	Node(int top = 0, int buttom = 0, int left = 0, int right = 0, int isShoot = 0);
	~Node();
	Point point;//С������
	Blood blood;//С��Ѫ��

	void showBlood(int bloodLength, int length);//��ʾѪ��

	//�߽緶Χ
	int left;
	int right;
	int top;
	int buttom;
	int isShoot;

	int dx;//x��������
	int dy;//y��������

	int speed;//�ٶ�
};

#endif //NODE_H