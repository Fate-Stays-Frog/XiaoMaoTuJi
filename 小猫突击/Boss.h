#ifndef BOSS_H
#define BOSS_H
#include"Sprite.h"

const int BossLength1 = 80;
const int BossWidth1 = 120;
const int BossLength2 = 150;
const int BossWidth2 = 130;

class Boss
	:public Sprite {
public:
	Boss(int speed, int length, int width, int kind, int bloodLength)
		:Sprite(length, width) {
		this->kind = kind;
		this->bloodLength = bloodLength;
		this->died = false;
		this->speed = speed;
		this->died = 0;
	}
	~Boss();

	//移动
	void move(Map*);
	//绘画
	//血条+图片
	void paint();
	//加载图片
	void init();
	//生成boss
	void generate();
	//死亡判断
	void die(CatStore* catStore);
	//boss种类
	int kind;
	/*
	kind == 1 boss.jpg
	kind == 2 boss2.jpg
	kind == 3 未完待续
	*/
	Node node;
	int bloodLength;//血条初始的长度
};

#endif //Boss