#ifndef FISH_H
#define FISH_H
#include<graphics.h>

const int FishWidth = 15;
const int FishLength = 40;

class Fish {
public:
	float fish_x, fish_y, fish_v;//子弹坐标和移动速度
	float direction, k;//左或右 -1 +1
	int attack;//伤害

	Fish(float x, float y, float v = 2, int a = 0, float d = 0, float kk = 0) {
		fish_x = x;
		fish_y = y;
		fish_v = v;
		attack = a;
		direction = d;
		k = kk;
	}
	~Fish();
	void init();//加载图片
	void move();
	void move1();//向指定坐标移动，轻微的追踪
	void move2();
	void setDirection(MOUSEMSG);//设定方向
	void setDirection2(float, float);//大招方向
	void appear();//子弹出现
};
#endif // FISH_H
