#ifndef SPRITE_H
#define SPRITE_H
#include<Windows.h>
#include<graphics.h>
#include<string>
#include<vector>
#include"Node.h"
#include"Map.h"
#include"CatStore.h"
#include"Value.h"
using namespace std;

class Sprite {
public:
	//���캯��
	//�������ٶȣ�������
	Sprite(int length = 0, int width = 0);
	//���
//	virtual void shoot(Cat) = 0;
	//�ƶ�
	virtual void move(Map*) = 0;
	//���ɾ���
	virtual void generate() = 0;
	//�����ж�
	virtual void die(CatStore* catStore) = 0;
	~Sprite();
	int length;//��
	int width;//��
	int speed;//�ٶ�
	int isMove;//�Ƿ��ƶ�
	bool died;//�Ƿ��Ѿ�����
	int isChange;//�Ƿ�ı䷽��
};

#endif //SPRITE_H