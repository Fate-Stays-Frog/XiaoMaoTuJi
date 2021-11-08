#include"Bullet.h"

IMAGE bullet_ps, bullet_p;//子弹图

void Bullet::move() {         //子弹移动
	if (nok == true) move3();
	else if (k > 1 || k < -1) move2();
	else move1();
}
void Bullet::move1() { //子弹移动
	bullet_x += direction / sqrt(1 + k * k);
	bullet_y += direction * k / sqrt(1 + k * k);
}
void Bullet::move2() { //子弹移动
	bullet_x += direction * (1 / k) / sqrt(1 + (1 / k) * (1 / k));
	bullet_y += direction / sqrt(1 + (1 / k) * (1 / k));
}
void Bullet::move3() { //子弹移动
	bullet_y += direction;
}

void Bullet::setDirection(float x, float y) {
	if (x == bullet_x) {
		nok = 1;
		if (y > bullet_y) direction = 1;
		else direction = -1;
		direction *= bullet_v;
	}
	else {
		nok = 0;
		k = (y - bullet_y) / (x - bullet_x);//变化率
		if (k > 1 || k < -1) {
			if (y > bullet_y) direction = 1;
			else direction = -1;
			direction *= bullet_v;
		}
		else {
			if (x > bullet_x) direction = 1;
			else direction = -1;
			direction *= bullet_v;
		}
	}
}

void Bullet::setDirection2(float a) {
	k = tan(a * 3.1415926 / 180);
	if (a < 135 && a > 0 || a > 315 && a < 360) direction = 1;
	else direction = -1;
	direction *= bullet_v;
}

void Bullet::init() {
	loadimage(&bullet_ps, _T("pic\\bullets.jpg"), BulletLength, BulletWidth, true);
	loadimage(&bullet_p, _T("pic\\bullet.jpg"), BulletLength, BulletWidth, true);
}

//子弹动画
void Bullet::appear() {
	putimage(bullet_x, bullet_y, &bullet_ps, NOTSRCERASE);
	putimage(bullet_x, bullet_y, &bullet_p, SRCINVERT);
}

Bullet::~Bullet() {}