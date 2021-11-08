#include"CatStore.h"

CatStore::CatStore() {}

void CatStore::storeLoad() {
	loadimage(&s, _T("pic\\store.jpg"), 1100, 600);
	loadimage(&guantou, _T("pic\\guantou.jpg"), 100, 80);
	loadimage(&guantous, _T("pic\\guantous.jpg"), 100, 80);
	loadimage(&leaf, _T("pic\\maobohe.jpg"), 100, 80);
	loadimage(&leafs, _T("pic\\maobohes.jpg"), 100, 80);
	loadimage(&food, _T("pic\\catfood.jpg"), 100, 80);
	loadimage(&foods, _T("pic\\catfoods.jpg"), 100, 80);
	loadimage(&jinbi, _T("pic\\jinbi.jpg"), 100, 105);
	loadimage(&jinbis, _T("pic\\jinbis.jpg"), 100, 105);
	loadimage(&cost, _T("pic\\jinbi.jpg"), 50, 52);
	loadimage(&costs, _T("pic\\jinbis.jpg"), 50, 52);
	loadimage(&tips, _T("pic\\tishis.jpg"), 1071, 566);
	loadimage(&tip, _T("pic\\tishi.jpg"), 1071, 566);
	loadimage(&milks, _T("pic\\milks.jpg"), 170,140 );
	loadimage(&milk, _T("pic\\milk.jpg"), 170, 140);
}

void CatStore::ifShowStore() {
	openstore = 1;
	//进入商店，同时游戏暂停
	while (1) {
		showStore();
		storeChange();
		FlushBatchDraw();
		if (leave == 1) {
			leave = 0; break;
		}
	}
}

void CatStore::showStore() {
	putimage(0, 0, &s);
	putimage(10, 20, &jinbis, NOTSRCERASE);
	putimage(10, 20, &jinbi, SRCINVERT);


	settextstyle(30, 0, _T("微软雅黑"));
	setbkcolor(RGB(211, 171, 150));
	settextcolor(BLACK);
	char num[1024];
	sprintf_s(num, "剩余%d个", money);
	outtextxy(20, 120, num);
	printTip();
	if (item[0] != 0) {
		putimage(535, 130, &guantous, NOTSRCERASE);
		putimage(535, 130, &guantou, SRCINVERT);
	}
	if (item[1] != 0) {
		putimage(700, 122, &foods, NOTSRCERASE);
		putimage(700, 122, &food, SRCINVERT);
	}

	if (item[2] != 0) {
		putimage(820, 115, &leafs, NOTSRCERASE);
		putimage(820, 115, &leaf, SRCINVERT);
	}
	if (item[3] != 0) {
		putimage(540, 310, &milks, NOTSRCERASE);
		putimage(540, 310, &milk, SRCINVERT);
	}
	if ((GetAsyncKeyState(0x54) & 0x8000)) {
		//按住T键查看攻略
		showTip();
	}

}

void CatStore::storeChange() {
	if (MouseHit()) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (m.x >= 535 && m.x <= 535 + 100 && m.y >= 130 && m.y <= 130 + 80 && money >= cost_guantou && item[0] >= 1) {//点击罐头
				money -= cost_guantou;
				if (play) {
					mciSendString("close moneyMusic", NULL, 0, NULL);
					mciSendString("open music\\结账.mp3 alias moneyMusic", NULL, 0, NULL);
					mciSendString("play moneyMusic", NULL, 0, NULL);
				}
				item[0]--;
				bufftime_guantou += 1000;
			}
			else if (m.x >= 700 && m.x <= 700 + 100 && m.y >= 122 && m.y <= 122 + 80 && money >= cost_food && item[1] >= 1) {//点击猫粮
				money -= cost_food;
				if (play) {
					mciSendString("close moneyMusic", NULL, 0, NULL);
					mciSendString("open music\\结账.mp3 alias moneyMusic", NULL, 0, NULL);
					mciSendString("play moneyMusic", NULL, 0, NULL);
				}
				item[1]--;
				foodnum++;

			}
			else if (m.x >= 820 && m.x <= 820 + 100 && m.y >= 115 && m.y <= 115 + 80 && money >= cost_leaf && item[2] >= 1) {//点击薄荷
				money -= cost_leaf;
				if (play) {
					mciSendString("close moneyMusic", NULL, 0, NULL);
					mciSendString("open music\\结账.mp3 alias moneyMusic", NULL, 0, NULL);
					mciSendString("play moneyMusic", NULL, 0, NULL);
				}
				item[2]--;
				bufftime_leaf += 1000;
			}
			else if (m.x >= 540 && m.x <= 540 + 170 && m.y >= 310 && m.y <= 310 + 140 && money >= cost_milk && item[3] >= 1) {//点击牛奶
				money -= cost_milk;
				if (play) {
					mciSendString("close moneyMusic", NULL, 0, NULL);
					mciSendString("open music\\结账.mp3 alias moneyMusic", NULL, 0, NULL);
					mciSendString("play moneyMusic", NULL, 0, NULL);
				}
				item[3]--;
				bufftime_milk += 300;

			}
			else if (m.x >= 362 && m.x <= 490 && m.y >= 53 && m.y <= 119) {
				leave = 1;
			}
		}
	}
}

void CatStore::printTip() {
	settextstyle(30, 0, _T("微软雅黑"));
	setbkcolor(RGB(211, 171, 150));
	settextcolor(BLACK);
	char str[1024];
	int num;

	num = item[0];
	if (num > 0)sprintf_s(str, "有%d个罐头嗷", num);
	else sprintf_s(str, "没罐头了。。");
	outtextxy(270, 140, str);

    num = item[1];
	if (num > 0)sprintf_s(str, "有%d袋猫粮嗷", num);
	else sprintf_s(str, "没猫粮了。。");
	outtextxy(270, 170, str);

	num = item[2];
	if (num > 0)sprintf_s(str, "有%d片薄荷嗷", num);
	else sprintf_s(str, "没薄荷了。。");
	outtextxy(270, 200, str);

	num = item[3];
	if (num > 0)sprintf_s(str, "有%d盒牛奶嗷", num);
	else sprintf_s(str, "没牛奶了。。");
	outtextxy(270, 230, str);
}

void CatStore::storeNew() {
	srand((unsigned int)time(0));
	item[0] = item[1] = item[2] =item[3]= 1;
	for (int i = 1; i <= 5; i++) {
		item[rand() % 4]++;
	}
}

void CatStore::showTip() {
	putimage(0, 0, &tips, NOTSRCERASE);
	putimage(0, 0, &tip, SRCINVERT);
	setbkcolor(RGB(246, 215, 135));
	settextstyle(20, 0, _T("微软雅黑"));
	char info[1024];
	sprintf_s(info, "鼠标左键点击购买东西嗷");
	outtextxy(490, 210, info);
	sprintf_s(info, "罐头减伤，猫粮回复血");
	outtextxy(487, 230, info);
	sprintf_s(info, "量和精力,薄荷加速嗷");
	outtextxy(487, 250, info);
	sprintf_s(info, "牛奶提高射速，很牛嗷");
	outtextxy(490, 270, info);
	sprintf_s(info, "罐头要%d块金币,猫粮要%d块", cost_guantou, cost_food);
	outtextxy(490, 290, info);
	sprintf_s(info, "金币,猫薄荷要%d块金币", cost_leaf);
	outtextxy(490, 310, info);
	sprintf_s(info, "牛奶要%d块金币", cost_milk);
	outtextxy(490, 330, info);
}

CatStore::~CatStore() {}