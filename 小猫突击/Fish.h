#ifndef FISH_H
#define FISH_H
#include<graphics.h>

const int FishWidth = 15;
const int FishLength = 40;

class Fish {
public:
	float fish_x, fish_y, fish_v;//�ӵ�������ƶ��ٶ�
	float direction, k;//����� -1 +1
	int attack;//�˺�

	Fish(float x, float y, float v = 2, int a = 0, float d = 0, float kk = 0) {
		fish_x = x;
		fish_y = y;
		fish_v = v;
		attack = a;
		direction = d;
		k = kk;
	}
	~Fish();
	void init();//����ͼƬ
	void move();
	void move1();//��ָ�������ƶ�����΢��׷��
	void move2();
	void setDirection(MOUSEMSG);//�趨����
	void setDirection2(float, float);//���з���
	void appear();//�ӵ�����
};
#endif // FISH_H
