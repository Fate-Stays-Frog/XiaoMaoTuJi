#include "Menu.h"

Menu::Menu() {}

void Menu::animation() {
	setbkcolor(WHITE);
	cleardevice();

	IMAGE cat;
	loadimage(&cat, _T("pic\\cat_r.jpg"), 250, 150, true);
	IMAGE wenhao;
	loadimage(&wenhao, _T("pic\\wenhao.jpg"), 140, 130, true);

	const int length = 70;
	const int width = 70;
	IMAGE xiao, xiao2, mao, tu, ji;
	loadimage(&xiao, _T("pic\\小.jpg"), length, width, true);
	loadimage(&xiao2, _T("pic\\小2.jpg"), length, width, true);
	loadimage(&mao, _T("pic\\猫.jpg"), length, width, true);
	loadimage(&tu, _T("pic\\突.jpg"), length, width, true);
	loadimage(&ji, _T("pic\\击.jpg"), length, width, true);

	int x = -260;
	while (x <= -155)
	{
		x += 13;
		putimage(x, 200, &cat);
		FlushBatchDraw();
		Sleep(50);
	}
	Sleep(200);
	putimage(60, 135, &wenhao);
	putimage(x, 200, &cat);
	FlushBatchDraw();
	Sleep(1500);
	setlinecolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(60, 135, 220, 355);

	while (x <= 150)
	{
		fillrectangle(x, 200, x + 50, 400);
		x += 18;
		putimage(x, 200, &cat);
		FlushBatchDraw();
		Sleep(50);
	}

	int y = -30;
	while (y <= 350)
	{
		fillrectangle(700, y, 700 + length, y + width);
		y += 20;
		putimage(700, y, &xiao);
		FlushBatchDraw();
		Sleep(20);
	}

	Sleep(200);
	fillrectangle(700, y, 700 + length, y + width);
	x = 700;
	while (x >= 620)
	{
		fillrectangle(x, y, x + length, y + width);
		x -= 10;
		y -= 20;
		putimage(x, y, &xiao2);
		FlushBatchDraw();
		Sleep(20);
	}

	Sleep(200);

	y = -30;
	while (y <= 180)
	{
		fillrectangle(700, y, 700 + length, y + width);
		y += 20;
		putimage(700, y, &mao);
		FlushBatchDraw();
		Sleep(20);
	}

	Sleep(200);
	putimage(790, y - 5, &tu);//y-5 == 185
	FlushBatchDraw();

	Sleep(200);
	putimage(890, y, &ji);
	FlushBatchDraw();

	settextstyle(30, 0, _T("微软雅黑"));
	int i = 0;
	MOUSEMSG msg;

	while (true) {

		if (MouseHit()) {
			msg = GetMouseMsg();

			if (msg.x >= 100 && msg.x <= 1000 && msg.y >= 50 && msg.y <= 550) {
				if (msg.mkLButton) {
					settextcolor(WHITE);
					outtextxy(745, 320, _T("点击开始"));
					FlushBatchDraw();
					break;
				}
			}
		}

		else {
			settextcolor(RGB(i, i, i));
			outtextxy(745, 320, _T("点击开始"));
			FlushBatchDraw();
			Sleep(150);
			i += 25;
			if (i > 255) {
				i %= 255;
			}
		}
	}

}

void clicked() {
	while (true)
	{
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.mkLButton) {
				break;
			}
		}
	}
}

void Menu::select() {
	Button button1(680, 303, 40, 40);
	loadimage(&button1.pre, _T("pic\\设置.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\设置s.jpg"), button1.length, button1.width, true);

	button1.tip = "设置";

	Button button2(680, 371, 40, 41);
	loadimage(&button2.pre, _T("pic\\猫掌.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\猫掌s.jpg"), button2.length, button2.width, true);

	button2.tip = "开始";

	Button button3(730, 373, 38, 38);
	loadimage(&button3.pre, _T("pic\\游戏.jpg"), button3.length, button3.width, true);
	loadimage(&button3.back, _T("pic\\游戏.jpg"), button3.length, button3.width, true);

	button3.tip = "游戏";

	Button button4(780, 372, 38, 38);
	loadimage(&button4.pre, _T("pic\\说明.jpg"), button4.length, button4.width, true);
	loadimage(&button4.back, _T("pic\\说明.jpg"), button4.length, button4.width, true);

	button4.tip = "说明";

	Button button5(730, 303, 40, 40);
	if (play) {
		loadimage(&button5.pre, _T("pic\\声音.jpg"), button5.length, button5.width, true);
		loadimage(&button5.back, _T("pic\\声音.jpg"), button5.length, button5.width, true);
		button5.tip = "声音";
	}
	else {
		loadimage(&button5.pre, _T("pic\\静音.jpg"), button5.length, button5.width, true);
		loadimage(&button5.back, _T("pic\\静音.jpg"), button5.length, button5.width, true);
		button5.tip = "声音";
	}

	Button button6(860, 550, 45, 45);
	loadimage(&button6.pre, _T("pic\\返回.jpg"), button6.length, button6.width, true);
	loadimage(&button6.back, _T("pic\\返回.jpg"), button6.length, button6.width, true);

	Button button7(1010, 550, 80, 40);
	loadimage(&button7.pre, _T("pic\\退出.jpg"), button7.length, button7.width, true);
	loadimage(&button7.back, _T("pic\\退出.jpg"), button7.length, button7.width, true);

	Button button8(960, 550, 45, 45);
	loadimage(&button8.pre, _T("pic\\彩蛋.jpg"), button8.length, button8.width, true);
	loadimage(&button8.back, _T("pic\\彩蛋.jpg"), button8.length, button8.width, true);

	Button button9(910, 550, 45, 45);
	loadimage(&button9.pre, _T("pic\\金币.jpg"), button9.length, button9.width, true);
	loadimage(&button9.back, _T("pic\\金币.jpg"), button9.length, button9.width, true);

	IMAGE pay;
	loadimage(&pay, _T("pic\\微信支付.jpg"), 280, 380, true);
	IMAGE egg1;
	loadimage(&egg1, _T("pic\\彩蛋_1.jpeg"), 280, 360, true);
	IMAGE egg2;
	loadimage(&egg2, _T("pic\\彩蛋_2.jpeg"), 280, 360, true);

	IMAGE girl;
	loadimage(&girl, _T("pic\\girl.jpg"), 150, 200, true);
	IMAGE cat;
	loadimage(&cat, _T("pic\\小猫咪.jpg"), 480, 282, true);
	IMAGE blank;
	loadimage(&blank, _T("pic\\对话框.jpg"), 240, 175, true);

	button3.stop = true;
	button4.stop = true;
	button5.stop = true;
	button6.stop = true;

	bool flag1 = false;//是否已经打开了开关1
	bool flag2 = false;//是否已经打开了开关2

	Buttons buttons;
	buttons.buttons.push_back(button1);
	buttons.buttons.push_back(button2);
	buttons.buttons.push_back(button3);
	buttons.buttons.push_back(button4);
	buttons.buttons.push_back(button5);
	buttons.buttons.push_back(button6);
	buttons.buttons.push_back(button7);
	buttons.buttons.push_back(button8);
	buttons.buttons.push_back(button9);

	buttons.show();
	setlinecolor(WHITE);
	setfillcolor(WHITE);
	settextcolor(BLACK);

	int flag;
	ifstream ifs;
	ifs.open("map\\flag.jpg", ios::out);
	ifs >> flag;
	ifs.close();

	while (true)
	{
		int kind = buttons.click();
		if (kind == 0) {
			if (!flag1) {
				buttons.buttons[4].stop = false;
				buttons.show();
			}
			else {
				buttons.buttons[4].stop = true;
				buttons.buttons[4].hide();
				FlushBatchDraw();
			}
			paoMusic();
			flag1 = !flag1;
		}
		else if (kind == 1) {
			if (!flag2) {
				buttons.buttons[2].stop = false;
				buttons.buttons[3].stop = false;
				buttons.show();
			}
			else {
				buttons.buttons[2].stop = true;
				buttons.buttons[3].stop = true;
				buttons.buttons[2].hide();
				buttons.buttons[3].hide();
				FlushBatchDraw();
			}
			paoMusic();
			flag2 = !flag2;
		}
		else if (kind == 2) {
			//退出主菜单进入游戏
			if (flag) {
				buttonMusic();
				closeBeginMusic();
				break;
			}
			else {
				buttonMusic();
				int color = 0;
				settextstyle(30, 0, "微软雅黑");
				while (color <= 255)
				{
					settextcolor(RGB(color, color, color));
					outtextxy(470, 550, "请先看一下说明哦");
					color += 15;
					FlushBatchDraw();
					Sleep(45);
				}
			}
		}
		else if (kind == 3) {
			if (!flag) {
				flag = 1;
				ofstream ofs;
				ofs.open("map\\flag.jpg", ios::in);
				ofs << flag;
				ofs.close();
			}

			fillrectangle(button1.x, button1.y, button1.x + 300, button1.y + 300);
			for (int i = 0; i < 5; i++) {
				buttons.buttons[i].stop = true;
				buttons.buttons[i].hide();
			}
			buttons.buttons[5].stop = false;

			settextstyle(28, 0, _T("微软雅黑"));
			settextcolor(BLACK);
			outtextxy(button1.x - 100, button1.y, "WSAD键控制移动，点击鼠标确定射击方向。");
			outtextxy(button1.x - 100, button1.y + 32, "按ESC键进入暂停，充能满了以后可以按R键");
			outtextxy(button1.x - 100, button1.y + 64, "使用技能。击败小怪即可获得金币，金币能够");
			outtextxy(button1.x - 100, button1.y + 96, "在商店中购买商品。善用商店是致胜的捷径噢。");
			outtextxy(button1.x - 100, button1.y + 128, "进入游戏之前，请先把自己的输入法调至英文。");
			outtextxy(button1.x - 100, button1.y + 160, "温馨提示，若安装在C盘，请用管理员权限打开。");
			outtextxy(button1.x - 100, button1.y + 192, "至于为什么叫小猫突击嘛，自己找彩蛋吧^-w-^");

			buttons.show();
			buttonMusic();
		}
		else if (kind == 4) {
			buttonMusic();
			if (play) {
				loadimage(&button5.pre, _T("pic\\静音.jpg"), button5.length, button5.width, true);
				loadimage(&button5.back, _T("pic\\静音.jpg"), button5.length, button5.width, true);
				buttons.buttons[4] = button5;
				buttons.buttons[4].stop = false;
			}
			else {
				loadimage(&button5.pre, _T("pic\\声音.jpg"), button5.length, button5.width, true);
				loadimage(&button5.back, _T("pic\\声音.jpg"), button5.length, button5.width, true);
				buttons.buttons[4] = button5;
				buttons.buttons[4].stop = false;
			}
			buttons.show();
			play = !play;
			if (play) {
				beginMusic();
			}
			else {
				closeBeginMusic();
			}
		}
		else if (kind == 5) {
			buttonMusic();
			setbkcolor(WHITE);
			cleardevice();
			showMenu();

			buttons.buttons[0].stop = false;
			buttons.buttons[1].stop = false;
			buttons.buttons[2].stop = true;
			buttons.buttons[3].stop = true;
			buttons.buttons[4].stop = true;
			buttons.buttons[5].stop = true;
			flag1 = false;
			flag2 = false;
			buttons.show();
		}
		else if (kind == 6) {
			buttonMusic();
			closegraph();
			exit(0);
		}
		else if (kind == 7) {
		buttonMusic();
		setbkcolor(WHITE);
		cleardevice();
		//彩蛋内容
		putimage(410, 100, &egg1);
		for (int i = 0; i < 5; i++) {
			buttons.buttons[i].stop = true;
		}
		buttons.buttons[5].stop = false;
		buttons.show();
		clicked();
		putimage(410, 100, &egg2);
		FlushBatchDraw();
		Sleep(300);
		fillrectangle(420, 100, 800, 500);
		FlushBatchDraw();

		putimage(168, 30, &blank);
		putimage(30, 110, &girl);

		putimage(580, 170, &cat);
		FlushBatchDraw();

		settextstyle(25, 0, _T("微软雅黑"));

		outtextxy(210, 65, "XG喵,我出去啦");
		outtextxy(665, 200, "喵喵（嗯！）");
		FlushBatchDraw();

		clicked();

		putimage(168, 30, &blank);
		putimage(30, 110, &girl);
		putimage(580, 170, &cat);
		outtextxy(200, 63, "不好，坏蛋HG来了");
		outtextxy(200, 93, "XG喵快跑！");
		outtextxy(650, 200, "？？？！！！");
		FlushBatchDraw();

		clicked();

		setbkcolor(WHITE);
		cleardevice();
		buttons.show();
		settextstyle(25, 0, _T("微软雅黑"));
		int t = 3;
		IMAGE img;

		while (t--)
		{
			for (int i = 1; i <= 26; i++)
			{
				string str = "pic\\战斗\\战斗_" + to_string(i) + ".jpeg";
				LPCSTR pstr = str.c_str();
				loadimage(&img, pstr, 1000, 500, true);
				putimage(50, 40, &img);
				putimage(30, 110, &girl);
				fillrectangle(50, 460, 320, 540);
				FlushBatchDraw();
				Sleep(45);
			}
		}

		for (int i = 32; i >= -400; i -= 5) {
			fillrectangle(i, 0, i + 300, 400);
			putimage(i, 110, &girl);
			Sleep(10);
			FlushBatchDraw();
		}

		clicked();

		fillrectangle(50, 40, 1050, 540);
		putimage(580, 170, &cat);
		outtextxy(685, 200, "QG！");
		FlushBatchDraw();
		clicked();

		putimage(580, 170, &cat);
		outtextxy(623, 200, "QG被带走了！我要去");
		outtextxy(623, 230, "救QG！不然就没猫粮");
		outtextxy(623, 260, "吃了Σ(っ °Д °;)っ");
		FlushBatchDraw();
		}
		else if (kind == 8) {
			buttonMusic();
			setbkcolor(WHITE);
			cleardevice();
			//显示支付图片
			putimage(410, 100, &pay);
			for (int i = 0; i < 5; i++) {
				buttons.buttons[i].stop = true;
			}
			buttons.buttons[5].stop = false;
			buttons.show();
		}
	}
}

void Menu::selectLevel() {
	Button button1(460, 150, 180, 60);
	loadimage(&button1.pre, _T("pic\\开挂难度.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\开挂难度.jpg"), button1.length, button1.width, true);

	Button button2(460, 250, 180, 60);
	loadimage(&button2.pre, _T("pic\\正常难度.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\正常难度.jpg"), button2.length, button2.width, true);

	Button button3(460, 350, 180, 60);
	loadimage(&button3.pre, _T("pic\\加强难度.jpg"), button3.length, button3.width, true);
	loadimage(&button3.back, _T("pic\\加强难度.jpg"), button3.length, button3.width, true);

	Buttons buttons;
	buttons.buttons.push_back(button1);
	buttons.buttons.push_back(button2);
	buttons.buttons.push_back(button3);

	setbkcolor(WHITE);
	cleardevice();

	buttons.show();
	while (true)
	{
		int kind = buttons.click();
		if (kind == 0) {
			buttonMusic();
			level = 1;
			break;
		}
		else if (kind == 1) {
			buttonMusic();
			level = 2;
			break;
		}
		else if (kind == 2) {
			buttonMusic();
			level = 3;
			break;
		}
	}
}

void Menu::buttonMusic() {
	if (!play) {
		return;
	}
	mciSendString("close button", NULL, 0, NULL);
	mciSendString("open music\\按钮音效.mp3 alias button", NULL, 0, NULL);
	mciSendString("play button", NULL, 0, NULL);
}

void Menu::paoMusic() {
	if (!play) {
		return;
	}
	mciSendString("close paopao", NULL, 0, NULL);
	mciSendString("open music\\泡泡.mp3 alias paopao", NULL, 0, NULL);
	mciSendString("play paopao", NULL, 0, NULL);
}

void Menu::beginMusic() {
	if (!play) {
		return;
	}
	mciSendString("open music\\开始菜单.mp3 alias beginMusic", NULL, 0, NULL);
	mciSendString("play beginMusic repeat", NULL, 0, NULL);
}

void Menu::closeBeginMusic() {
	mciSendString("stop beginMusic", NULL, 0, NULL);
}

void Menu::startMovie() {
	beginMusic();

	IMAGE img;

	Button button(530, 530, 40, 40);
	loadimage(&button.pre, _T("pic\\电源.jpg"), button.length, button.width, true);
	loadimage(&button.back, _T("pic\\电源.jpg"), button.length, button.width, true);

	setlinecolor(RGB(50, 56, 106));
	setfillcolor(RGB(50, 56, 106));

	int i = 1;
	while (true)
	{
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.x >= button.x && msg.x <= button.x + button.length && \
				msg.y >= button.y && msg.y <= button.y + button.width && msg.mkLButton) {
				for (int j = 0; j < 5; j++) {
					putimage(button.x, button.y + j, &button.back);
					FlushBatchDraw();
					fillrectangle(button.x, button.y + j, button.x + button.length, \
						button.y + j + button.width);
					Sleep(25);
				}
				putimage(button.x, button.y + 5, &button.back);
				FlushBatchDraw();
				fillrectangle(button.x, button.y + 5, button.x + button.length, \
					button.y + 5 + button.width);
				Sleep(20);
				putimage(button.x, button.y, &button.pre);
				FlushBatchDraw();
				break;
			}
		}

		else {
			string str = "pic\\开始动画\\开始动画_" + to_string(i) + ".jpeg";
			LPCSTR pstr = str.c_str();
			loadimage(&img, pstr, 1100, 600, true);
			putimage(0, 0, &img);
			putimage(button.x, button.y, &button.pre);
			fillrectangle(800, 550, 1100, 600);
			FlushBatchDraw();
			i++;
			Sleep(30);
			if (i == 16) {
				i = 1;
			}
		}
	}
}

void Menu::showMenu() {
	IMAGE cat, xiao2, mao, tu, ji;
	const int length = 70;
	const int width = 70;
	loadimage(&cat, _T("pic\\cat_r.jpg"), 250, 150, true);
	loadimage(&xiao2, _T("pic\\小2.jpg"), length, width, true);
	loadimage(&mao, _T("pic\\猫.jpg"), length, width, true);
	loadimage(&tu, _T("pic\\突.jpg"), length, width, true);
	loadimage(&ji, _T("pic\\击.jpg"), length, width, true);
	putimage(163, 200, &cat);
	putimage(610, 190, &xiao2);
	putimage(700, 190, &mao);
	putimage(790, 185, &tu);
	putimage(890, 190, &ji);

	FlushBatchDraw();
}

void Menu::gameOver() {
	setbkcolor(WHITE);
	cleardevice();
	int t = 2;

	settextstyle(22, 0, _T("微软雅黑"));
	IMAGE img;
	while (t--)
	{
		for (int i = 1; i <= 60; i++) {
			string str = "pic\\闯关失败\\闯关失败_" + to_string(i) + ".jpeg";
			LPCSTR pstr = str.c_str();
			loadimage(&img, pstr, 500, 500, true);
			putimage(300, 50, &img);

			FlushBatchDraw();
			Sleep(30);
		}
	}
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(WHITE);
	setlinecolor(WHITE);

	IMAGE cat;
	loadimage(&cat, _T("pic\\小猫咪.jpg"), 480, 282, true);

	if (play) {
		mciSendString("open music\\剧情.mp3 alias jokeMusic", NULL, 0, NULL);
		mciSendString("play jokeMusic repeat", NULL, 0, NULL);
	}

	putimage(580, 170, &cat);
	outtextxy(623, 200, "果然还是救不了QG吗...");
	outtextxy(623, 230, "唉，我还是回去华工C10找");
	outtextxy(623, 260, "橘猫玩吧...");

	Buttons buttons;
	Button button1(960, 550, 45, 45);
	loadimage(&button1.pre, _T("pic\\返回.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\返回.jpg"), button1.length, button1.width, true);
	Button button2(1010, 550, 80, 40);
	loadimage(&button2.pre, _T("pic\\退出.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\退出.jpg"), button2.length, button2.width, true);

	buttons.buttons.push_back(button1);
	buttons.buttons.push_back(button2);

	buttons.show();

	while (true)
	{
		int kind = buttons.click();
		if (kind == 0) {
			buttonMusic();
			mciSendString("close jokeMusic", NULL, 0, NULL);
			break;
		}
		else if (kind == 1) {
			buttonMusic();
			closegraph();
			exit(0);
		}
	}
}

void Menu::winGame() {
	IMAGE cat;
	loadimage(&cat, _T("pic\\小猫咪.jpg"), 480, 282, true);

	setfillcolor(RGB(218, 209, 104));
	setlinecolor(RGB(218, 209, 104));

	settextstyle(22, 0, _T("微软雅黑"));
	settextcolor(BLACK);
	int t = 3;

	IMAGE img;
	while (t--)
	{
		for (int i = 1; i <= 14; i++) {
			string str = "pic\\闯关成功\\闯关成功_" + to_string(i) + ".jpeg";
			LPCSTR pstr = str.c_str();
			loadimage(&img, pstr, 1100, 600, true);
			putimage(0, 0, &img);
			fillrectangle(0, 400, 250, 600);
			FlushBatchDraw();
			Sleep(45);
		}
	}
	if (play) {
		mciSendString("open music\\剧情.mp3 alias jokeMusic", NULL, 0, NULL);
		mciSendString("play jokeMusic repeat", NULL, 0, NULL);
	}
	t = 3;
	while (t--)
	{
		for (int i = 1; i <= 33; i++) {
			string str = "pic\\欠蜗\\欠蜗_" + to_string(i) + ".jpeg";
			LPCSTR pstr = str.c_str();
			loadimage(&img, pstr, 1100, 600, true);
			putimage(0, 0, &img);
			fillrectangle(0, 400, 250, 600);
			FlushBatchDraw();
			Sleep(45);
		}
	}

	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(WHITE);
	setlinecolor(WHITE);


	putimage(580, 170, &cat);
	outtextxy(623, 200, "呜呜来得太迟了");
	outtextxy(623, 230, "欠锅已经变成欠蜗了");

	FlushBatchDraw();

	Buttons buttons;
	Button button1(960, 550, 45, 45);
	loadimage(&button1.pre, _T("pic\\返回.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\返回.jpg"), button1.length, button1.width, true);
	Button button2(1010, 550, 80, 40);
	loadimage(&button2.pre, _T("pic\\退出.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\退出.jpg"), button2.length, button2.width, true);

	buttons.buttons.push_back(button1);
	buttons.buttons.push_back(button2);

	buttons.show();

	while (true)
	{
		int kind = buttons.click();
		if (kind == 0) {
			buttonMusic();
			mciSendString("close jokeMusic", NULL, 0, NULL);
			break;
		}
		else if (kind == 1) {
			buttonMusic();
			closegraph();
			exit(0);
		}
	}
}

Menu::~Menu() {}