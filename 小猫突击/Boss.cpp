#include "Boss.h"
IMAGE boss;
IMAGE bosss;

void Boss::move(Map* mp) {
	if (died) {
		return;
	}

	isMove++;
	if (isMove >= 3 &&
		(((node.isShoot < 350 || node.isShoot > 750) && kind == 1)
			|| ((node.isShoot < 500 || node.isShoot > 980) && kind == 2))) {
		isMove = 0;

		int dx = node.dx;
		int dy = node.dy;
		node.point.x += dx;
		node.point.y += dy;

		//ÌØÅÐ
		if (node.point.x + length > node.right) {
			node.point.x = node.right - length;
			this->node.dx = -dx;
		}
		if (node.point.x < node.left) {
			node.point.x = node.left;
			this->node.dx = -dx;
		}
		if (node.point.y + width > node.buttom) {
			node.point.y = node.buttom - width;
			this->node.dy = -dy;
		}
		if (node.point.y < node.top) {
			node.point.y = node.top;
			this->node.dy = -dy;
		}
		int x = node.point.x;
		int y = node.point.y;
		int x1 = (int)(x / 50);//×óÉÏ
		int y1 = (int)(y / 50);
		int x2 = (int)(x + length) / 50;//ÓÒÉÏ
		int y2 = y1;
		int x3 = x1;//×óÏÂ
		int y3 = (int)(y + width) / 50;
		int x4 = (int)(x + length) / 50;//ÓÒÏÂ
		int y4 = (int)(y + width) / 50;
		if (kind == 1) {
			//ÉÏµ×
			if (mp->map[y1][x1] || mp->map[y1][x1 + 1]
				|| mp->map[y1][x2]) {
				node.dy = -node.dy;
				node.point.y += 2 * node.dy;
			}
			//×ó±ß
			if (mp->map[y1][x1] || mp->map[y1 + 1][x1]
				|| mp->map[y1 + 2][x1] || mp->map[y3][x1]) {
				node.dx = -node.dx;
				node.point.x += 2 * node.dx;
			}

			//ÏÂµ×
			if (mp->map[y3][x3] || mp->map[y3][x3 + 1]
				|| mp->map[y3][x4]) {
				node.dy = -node.dy;
				node.point.y += 2 * node.dy;
			}
			//ÓÒ±ß
			if (mp->map[y2][x2] || mp->map[y2 + 1][x2]
				|| mp->map[y2 + 2][x2] || mp->map[y4][x4]) {
				node.dx = -node.dx;
				node.point.x += 2 * node.dx;
			}
		}
		else {
			//ÉÏµ×
			if (mp->map[y1][x1] || mp->map[y1][x1 + 1]
				|| mp->map[y1][x1 + 2] || mp->map[y1][x2]) {
				node.dy = -node.dy;
				node.point.y += 2 * node.dy;
			}
			//×ó±ß
			if (mp->map[y1][x1] || mp->map[y1 + 1][x1]
				|| mp->map[y1 + 2][x1] || mp->map[y3][x1]) {
				node.dx = -node.dx;
				node.point.x += 2 * node.dx;
			}

			//ÏÂµ×
			if (mp->map[y3][x3] || mp->map[y3][x3 + 1]
				|| mp->map[y3][x3 + 2] || mp->map[y3][x4]) {
				node.dy = -node.dy;
				node.point.y += 2 * node.dy;
			}
			//ÓÒ±ß
			if (mp->map[y2][x2] || mp->map[y2 + 1][x2]
				|| mp->map[y2 + 2][x2] || mp->map[y4][x4]) {
				node.dx = -node.dx;
				node.point.x += 2 * node.dx;

			}
		}
	}

	isChange++;
	if (isChange >= 300) {
		node.dx = pow(-1, rand() % 2) * speed;
		node.dy = pow(-1, rand() % 2) * speed;
		isChange = 0;
	}

	//½øÐÐ»æÖÆ
	paint();
}

void Boss::paint() {
	putimage(node.point.x, node.point.y, &bosss, NOTSRCERASE);
	putimage(node.point.x, node.point.y, &boss, SRCINVERT);

	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(550 - bloodLength, 30, 550 + bloodLength, 30 + node.blood.bloodWidth);

	setfillcolor(RGB(221, 59, 57));
	fillrectangle(550 - bloodLength, 30, 550 + node.blood.bloodLength, 30 + node.blood.bloodWidth);
}

void Boss::init() {
	if (kind == 1) {
		loadimage(&boss, ("pic\\boss.jpg"), BossLength1, BossWidth1, true);
		loadimage(&bosss, ("pic\\bosss.jpg"), BossLength1, BossWidth1, true);
	}
	else if (kind == 2) {
		loadimage(&boss, ("pic\\boss2.jpg"), BossLength2, BossWidth2, true);
		loadimage(&bosss, ("pic\\boss2s.jpg"), BossLength2, BossWidth2, true);
	}
}

void Boss::generate() {
	int x = rand() % (300 - length) + 400;
	int y = rand() % (200 - width) + 200;

	Node node(10, 590, 10, 1090);
	node.blood.bloodLength = this->bloodLength;
	node.blood.bloodWidth = 15;
	node.point = Point(x, y);

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.speed = speed;

	this->node = node;
}

void Boss::die(CatStore* catStore) {
	if (died) {
		return;
	}
	if (node.blood.bloodLength <= -bloodLength) {
		this->died = true;
		if (!play) {
			return;
		}
		if (kind == 1) {
			if (play) {
				mciSendString("close boss1DieMusic", NULL, 0, NULL);
				mciSendString("open music\\ÄÏ¹ÏÍ·ËÀÍö.mp3 alias boss1DieMusic", NULL, 0, NULL);
				mciSendString("play boss1DieMusic", NULL, 0, NULL);
			}
		}
		else if (kind == 2) {
			if (play) {
				mciSendString("close boss2DieMusic", NULL, 0, NULL);
				mciSendString("open music\\ËÀÉñËÀÍö.mp3 alias boss2DieMusic", NULL, 0, NULL);
				mciSendString("play boss2DieMusic", NULL, 0, NULL);
			}
		}
		catStore->money += 15;
	}
}

Boss::~Boss() {}