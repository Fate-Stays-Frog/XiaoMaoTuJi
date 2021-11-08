#ifndef BULLET_H
#define BULLET_H
#include<graphics.h>
#include"Cat.h"

const int Length = 1100;
const int Width = 600;
const int BulletLength = 25;
const int BulletWidth = 30;

class Bullet {
public:
	float bullet_x, bullet_y, bullet_v;//子弹坐标和移动速度
	float direction, k;//左或右 -1 +1 斜率，即方向
	int attack;//伤害
	bool nok;//斜率不存在

	Bullet(float x, float y, float v = 1, int a = 0, float d = 0, float kk = 0, bool nk = false) {
		bullet_x = x;
		bullet_y = y;
		bullet_v = v;
		attack = a;
		direction = d;
		k = kk;
		nok = nk;
	}
	~Bullet();
	void init();//加载图片
	void move();//向指定坐标移动，轻微的追踪
	void move1();
	void move2();
	void move3();
	void setDirection(float x, float y);//设定方向
	void setDirection2(float);
	void appear();//子弹出现
};
#endif //BULLET_H