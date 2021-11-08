#ifndef NODE_H
#define NODE_H
#include<graphics.h>
#include"Point.h"
#include"Blood.h"

class Node {
public:
	Node(int top = 0, int buttom = 0, int left = 0, int right = 0, int isShoot = 0);
	~Node();
	Point point;//小怪坐标
	Blood blood;//小怪血量

	void showBlood(int bloodLength, int length);//显示血条

	//边界范围
	int left;
	int right;
	int top;
	int buttom;
	int isShoot;

	int dx;//x方向增量
	int dy;//y方向增量

	int speed;//速度
};

#endif //NODE_H