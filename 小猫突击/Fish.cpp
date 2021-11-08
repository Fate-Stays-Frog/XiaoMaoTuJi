#include"Fish.h"

IMAGE fish_ps, fish_p;//�ӵ�ͼ
IMAGE bigfish, bigfishs;//С��ɺ͵���
void Fish::move() {
	if (k > 1 || k < -1) move2();
	else move1();
}

void Fish::move1() { //�ӵ��ƶ�
	fish_x += direction;
	fish_y += direction * k;
}

void Fish::move2() { //�ӵ��ƶ�
	fish_x += direction * (1 / k);
	fish_y += direction;
}

void Fish::setDirection(MOUSEMSG m) {
	k = (m.y - fish_y) / (m.x - fish_x);//�仯��
	if (k > 1 || k < -1) {
		if (m.y > fish_y) direction = 1;
		else direction = -1;
		direction *= fish_v;
	}
	else {
		if (m.x > fish_x) direction = 1;
		else direction = -1;
		direction *= fish_v;
	}
}

void Fish::setDirection2(float x, float y) {
	k = (y - fish_y) / (x - fish_x);//�仯��
	if (k > 1 || k < -1) {
		if (y > fish_y) direction = 1;
		else direction = -1;
		direction *= fish_v;
	}
	else {
		if (x > fish_x) direction = 1;
		else direction = -1;
		direction *= fish_v;
	}
}


void Fish::init() {
	loadimage(&fish_ps, _T("pic\\fishs.jpg"), FishLength, FishWidth, true);
	loadimage(&fish_p, _T("pic\\fish.jpg"), FishLength, FishWidth, true);
	loadimage(&bigfish, _T("pic\\bigfish.jpg"), FishLength, FishWidth, true);
	loadimage(&bigfishs, _T("pic\\bigfishs.jpg"), FishLength, FishWidth, true);
}

//�ӵ�����
void Fish::appear() {
	if (attack < 10) {//��С���
		putimage(fish_x, fish_y, &fish_ps, NOTSRCERASE);
		putimage(fish_x, fish_y, &fish_p, SRCINVERT);
	}
	else {//�ǵ���
		putimage(fish_x, fish_y, &bigfishs, NOTSRCERASE);
		putimage(fish_x, fish_y, &bigfish, SRCINVERT);
	}
}

Fish::~Fish() {}