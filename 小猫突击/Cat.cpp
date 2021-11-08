#include"Cat.h"

Cat::Cat() {}

void Cat::catLoad() {
	loadimage(&catPic, _T("pic\\cat_r.jpg"), catSize_length, catSize_width);
	loadimage(&catPic_s, _T("pic\\cat_rs.jpg"), catSize_length, catSize_width);
	loadimage(&catHurt, _T("pic\\hurt.jpg"), 15, 40);
	loadimage(&catHurts, _T("pic\\hurts.jpg"), 15, 40);
}

void Cat::catShow() {
	settextstyle(25, 0, _T("微软雅黑"));

	//载入猫猫图片之前先决定载入哪张图片
	if (catHealth > 0 && catHealth <= 50) {
		catState = 1;
		if (catLOR == 0 && prePic != 2) {
			loadimage(&catPic_s, _T("pic\\cat_hit_ls.jpg"), catSize_length, catSize_width);
			loadimage(&catPic, _T("pic\\cat_hit_l.jpg"), catSize_length, catSize_width);
			prePic = 2;
		}
		else if (catLOR == 1 && prePic != 3) {
			loadimage(&catPic_s, _T("pic\\cat_hit_rs.jpg"), catSize_length, catSize_width);
			loadimage(&catPic, _T("pic\\cat_hit_r.jpg"), catSize_length, catSize_width);
			prePic = 3;
		}
	}

	else if (catHealth <= 0) {
		catState = 2;
		if (catLOR == 0 && prePic != 4) {
			loadimage(&catPic_s, _T("pic\\cat_die_ls.jpg"), catSize_length, catSize_width);
			loadimage(&catPic, _T("pic\\cat_die_l.jpg"), catSize_length, catSize_width);
			prePic = 4;
		}
		else if (catLOR == 1 && prePic != 5) {
			loadimage(&catPic_s, _T("pic\\cat_die_rs.jpg"), catSize_length, catSize_width);
			loadimage(&catPic, _T("pic\\cat_die_r.jpg"), catSize_length, catSize_width);
			prePic = 5;
		}
	}
	else {
		catState = 0;
		if (catLOR == 0 && prePic != 0) {
			loadimage(&catPic_s, _T("pic\\cat_ls.jpg"), catSize_length, catSize_width);
			loadimage(&catPic, _T("pic\\cat_l.jpg"), catSize_length, catSize_width);
			prePic = 0;
		}
		else if (catLOR == 1 && prePic != 1) {
			loadimage(&catPic_s, _T("pic\\cat_rs.jpg"), catSize_length, catSize_width);
			loadimage(&catPic, _T("pic\\cat_r.jpg"), catSize_length, catSize_width);
			prePic = 1;
		}
	}
	//载入完毕，放出图片
	putimage(catX, catY, &catPic_s, NOTSRCERASE);
	putimage(catX, catY, &catPic, SRCINVERT);

	//绘制血条
	setlinecolor(BLACK);
	setfillcolor(RGB(221, 59, 57));
	fillrectangle(catRed_x1, catRed_y1, catRed_x2, catRed_y2);

	//绘制蓝条
	setfillcolor(RGB(40, 240, 220));
	fillrectangle(catBlue_x1, catBlue_y1, catBlue_x2, catBlue_y2);

	//绘制能量
	if (catEnergy < 100.0)setfillcolor(RGB(176, 228, 18));
	else setfillcolor(RGB(252, 150, 67));
	fillrectangle(catE_x2, catE_y2, catE_x1, catE_y1);

	//绘制感叹号
	if (hurt > 0 && catHealth > 0) {
		hurt--;
		putimage(catX+110, catY-10, &catHurts, NOTSRCERASE);
		putimage(catX+110, catY-10, &catHurt, SRCINVERT);
	}

	//显示文本
	setbkcolor(RGB(254, 237, 211));
	settextcolor(BLACK);
	outtextxy(RedTextX, RedTexY, _T("体力"));
	outtextxy(BlueTextX, BlueTextY, _T("精力"));
	outtextxy(ETextX, ETextY, _T("充能"));
}

//下面函数参数change是猫猫受到的伤害或者回血或者能量（负数为伤害，正数为回血）
void Cat::catRed(float change) {
	catHealth += change;
	if (catHealth < 0)catHealth = 0;
	else if (catHealth > 100)catHealth = 100;
	if (catRed_x2 + change <= catRed_x1)catRed_x2 = catRed_x1;
	else if (catRed_x2 + change > catRed_x1 + 100)catRed_x2 = catRed_x1 + 100;
	else catRed_x2 += change;
}

void Cat::catBlue(float change) {
	catMagic += change;
	if (catMagic < 0)catMagic = 0;
	else if (catMagic > 100)catMagic = 100;
	if (catBlue_x2 + change <= catBlue_x1)catBlue_x2 = catBlue_x1;
	else if (catBlue_x2 + change > catBlue_x1 + 100)catBlue_x2 = catBlue_x1 + 100;
	else catBlue_x2 += change;
}

void Cat::catSkill(float change) {
	catEnergy += change;
	if (catEnergy >= 100.0)catEnergy = 100.0;
	else if (catEnergy <= 0.0)catEnergy = 0.0;
	catE_x2 = catE_x1 + catEnergy;
}

void Cat::catMove(Map* p) {
	if ((GetAsyncKeyState(0x57) & 0x8000)) {//向上移动
		if (catState != 2) {//只要不死亡，就可以移动（另外判断是否到达边界，以下同理）
			if (catY - catSpeed > 0) {
				float nextX = catX, nextY = catY - catSpeed;
				if (ifMove(p, nextX, nextY, 0)) {
					catY -= catSpeed;
				}
			}
		}
	}
	if ((GetAsyncKeyState(0x53) & 0x8000)) {//向下移动
		if (catState != 2) {
			if (catY + catSpeed < 600 - catSize_width) {
				float nextX = catX, nextY = catY + catSpeed;
				if (ifMove(p, nextX, nextY, 1))catY += catSpeed;
			}

		}
	}
	if ((GetAsyncKeyState(0x41) & 0x8000)) {//向左移动
		if (catState != 2) {
			catLOR = 0;
			if (catX - catSpeed > 0) {
				float nextX = catX - catSpeed, nextY = catY;
				if (ifMove(p, nextX, nextY, 2))
					catX -= catSpeed;
			}
		}
	}
	if ((GetAsyncKeyState(0x44) & 0x8000)) {//向右移动
		if (catState != 2) {
			catLOR = 1;
			if (catX + catSpeed < 1100 - catSize_length) {
				float nextX = catX + catSpeed, nextY = catY;
				if (ifMove(p, nextX, nextY, 3))catX += catSpeed;
			}
		}
	}
}

void Cat::catSize(int x, int y) {
	if (x > 0 && y > 0)
		catSize_length = x, catSize_width = y;
}

void Cat::catSetSpeed(float a) {
	if (a > 0)
		catSpeed = a;
}

bool Cat::ifMove(Map* p, float x, float y, int direct) {//判断有没有撞到map
	//x和y是移动后的猫猫坐标
	int x1 = (int)(x / 50), y1 = (int)(y / 50);//左上
	int x2 = (int)((x + catSize_length) / 50), y2 = (int)(y / 50);//右上
	int x3 = (int)((x + catSize_length) / 50), y3 = (int)((y + catSize_width) / 50);//右下
	int x4 = (int)(x / 50), y4 = (int)((y + catSize_width) / 50);//左下
	int x5 = (int)((x + catSize_length / 2) / 50), y5 = (int)(y / 50);//中上
	int x6 = (int)((x + catSize_length / 2) / 50), y6 = (int)((y + catSize_width) / 50);//中下
	if (direct == 0) {//向上移动
		if (p->map[y1][x1] == 0 && p->map[y2][x2] == 0 && p->map[y5][x5] == 0)return 1;
	}
	if (direct == 1) {//向下移动
		if (p->map[y3][x3] == 0 && p->map[y4][x4] == 0 && p->map[y6][x6] == 0)return 1;
	}
	if (direct == 2) {//向左移动
		if (p->map[y1][x1] == 0 && p->map[y4][x4] == 0)return 1;
	}
	if (direct == 3) {//向右移动
		if (p->map[y2][x2] == 0 && p->map[y3][x3] == 0)return 1;
	}
	return 0;
}

Cat::~Cat() {}