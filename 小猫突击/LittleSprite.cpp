#include "LittleSprite.h"

IMAGE xiaoguai, xiaoguais;

void LittleSprite::move(Map* mp) {
	if (died) {
		return;
	}

	isMove++;
	if (isMove >= 5) {
		isMove = 0;
		for (auto& num : nums) {
			num.point.x += num.dx;
			num.point.y += num.dy;

			if (num.point.x + length > num.right) {
				num.point.x = num.right - length;
				num.dx = -num.dx;
			}
			else if (num.point.x < num.left) {
				num.point.x = num.left;
				num.dx = -num.dx;
			}
			if (num.point.y + width > num.buttom) {
				num.point.y = num.buttom - width;
				num.dy = -num.dy;
			}
			else if (num.point.y - num.blood.bloodWidth < num.top) {
				num.point.y = num.top + num.blood.bloodWidth;
				num.dy = -num.dy;
			}
			int x = num.point.x;
			int y = num.point.y;
			int x1 = (int)(x / 50);//左上
			int y1 = (int)(y / 50);
			int x2 = (int)(x + length) / 50;//右上
			int y2 = y1;
			int x3 = x1;//左下
			int y3 = (int)(y + width) / 50;
			int x4 = (int)(x + length) / 50;//右下
			int y4 = (int)(y + width) / 50;
			//上底
			if (mp->map[y1][x1] || mp->map[y1][x1 + 1] || mp->map[y1][x2]) {
				num.dy = -num.dy;
				num.point.y += 2 * num.dy;
			}
			//下底
			else if (mp->map[y3][x3] || mp->map[y3][x3 + 1] || mp->map[y3][x4]) {
				num.dy = -num.dy;
				num.point.y += 2 * num.dy;
			}
			//左边
			if (mp->map[y1][x1] || mp->map[y3][x1]) {
				num.dx = -num.dx;
				num.point.x += 2 * num.dx;
			}
			//右边
			else if (mp->map[y2][x2] || mp->map[y4][x4]) {
				num.dx = -num.dx;
				num.point.x += 2 * num.dx;
			}
		}
	}

	isChange++;
	if (isChange >= 1000) {
		for (auto& num : nums) {
			num.dx = pow(-1, rand() % 2) * speed;
			num.dy = pow(-1, rand() % 2) * speed;
		}

		isChange = 0;
	}

	//进行绘制
	paint();
	//Sleep(15);
}



void LittleSprite::paint() {
	if (died) {
		return;
	}

	for (auto& num : nums) {
		putimage(num.point.x, num.point.y, &xiaoguais, NOTSRCERASE);
		putimage(num.point.x, num.point.y, &xiaoguai, SRCINVERT);
		num.showBlood(num.blood.bloodLength, length);
	}
}

void LittleSprite::init() {
	loadimage(&xiaoguai, _T("pic\\xiaoguai.jpg"), SpriteLength, SpriteWidth, true);
	loadimage(&xiaoguais, _T("pic\\xiaoguais.jpg"), SpriteLength, SpriteWidth, true);
}

void LittleSprite::generate() {
	isGenerate++;
	if (isGenerate >= 300) {
		if (counter < sumNums && nums.size() < maxNums) {

			isGenerate = 0;

			int n = rand() % position.size();

			nums.push_back(position[n]);

			//计数器自增
			counter++;
		}
	}
}

void LittleSprite::loadPositon() {
	Node node(10, 590, 10, 1090);
	node.blood.bloodWidth = 7;
	node.blood.bloodLength = length * 9 / 10;
	//区域1
	int px = rand() % (150 - length);
	int py = rand() % (600 - width);

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.point = Point(px, py);
	position.push_back(node);
	//区域2
	px = rand() % (600 - length) + 200;
	py = rand() % (100 - width);

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.point = Point(px, py);
	position.push_back(node);
	//区域3
	px = rand() % (150 - length) + 950;
	py = rand() % (600 - width);

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.point = Point(px, py);
	position.push_back(node);
	//区域4
	px = rand() % (150 - length) + 350;
	py = rand() % (150 - width) + 200;

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.point = Point(px, py);
	position.push_back(node);
	//区域5
	px = rand() % (150 - length) + 650;
	py = rand() % (200 - width) + 400;

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.point = Point(px, py);
	position.push_back(node);
	//区域6
	px = rand() % (100 - length) + 1000;
	py = rand() % (350 - width) + 200;

	node.dx = pow(-1, rand() % 2) * speed;
	node.dy = pow(-1, rand() % 2) * speed;

	node.point = Point(px, py);
	position.push_back(node);
}

void LittleSprite::die(CatStore* catStore) {
	if (nums.size() == 0) {
		if (counter >= sumNums) {
			died = true;
		}
		return;
	}

	for (auto it = nums.begin(); it != nums.end();) {
		if (it->blood.bloodLength <= 0) {
			if (play) {
				mciSendString("close spriteDieMusic", NULL, 0, NULL);
				mciSendString("open music\\蝙蝠死亡.mp3 alias spriteDieMusic", NULL, 0, NULL);
				mciSendString("play spriteDieMusic", NULL, 0, NULL);
			}
			it = nums.erase(it);
			catStore->money += 5;
		}
		else {
			it++;
		}
	}
}

LittleSprite::~LittleSprite() {}