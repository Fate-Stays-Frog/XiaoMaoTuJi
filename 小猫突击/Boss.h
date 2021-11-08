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

	//�ƶ�
	void move(Map*);
	//�滭
	//Ѫ��+ͼƬ
	void paint();
	//����ͼƬ
	void init();
	//����boss
	void generate();
	//�����ж�
	void die(CatStore* catStore);
	//boss����
	int kind;
	/*
	kind == 1 boss.jpg
	kind == 2 boss2.jpg
	kind == 3 δ�����
	*/
	Node node;
	int bloodLength;//Ѫ����ʼ�ĳ���
};

#endif //Boss