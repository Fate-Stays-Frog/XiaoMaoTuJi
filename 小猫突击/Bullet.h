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
	float bullet_x, bullet_y, bullet_v;//�ӵ�������ƶ��ٶ�
	float direction, k;//����� -1 +1 б�ʣ�������
	int attack;//�˺�
	bool nok;//б�ʲ�����

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
	void init();//����ͼƬ
	void move();//��ָ�������ƶ�����΢��׷��
	void move1();
	void move2();
	void move3();
	void setDirection(float x, float y);//�趨����
	void setDirection2(float);
	void appear();//�ӵ�����
};
#endif //BULLET_H