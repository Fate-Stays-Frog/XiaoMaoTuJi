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
	loadimage(&xiao, _T("pic\\С.jpg"), length, width, true);
	loadimage(&xiao2, _T("pic\\С2.jpg"), length, width, true);
	loadimage(&mao, _T("pic\\è.jpg"), length, width, true);
	loadimage(&tu, _T("pic\\ͻ.jpg"), length, width, true);
	loadimage(&ji, _T("pic\\��.jpg"), length, width, true);

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

	settextstyle(30, 0, _T("΢���ź�"));
	int i = 0;
	MOUSEMSG msg;

	while (true) {

		if (MouseHit()) {
			msg = GetMouseMsg();

			if (msg.x >= 100 && msg.x <= 1000 && msg.y >= 50 && msg.y <= 550) {
				if (msg.mkLButton) {
					settextcolor(WHITE);
					outtextxy(745, 320, _T("�����ʼ"));
					FlushBatchDraw();
					break;
				}
			}
		}

		else {
			settextcolor(RGB(i, i, i));
			outtextxy(745, 320, _T("�����ʼ"));
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
	loadimage(&button1.pre, _T("pic\\����.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\����s.jpg"), button1.length, button1.width, true);

	button1.tip = "����";

	Button button2(680, 371, 40, 41);
	loadimage(&button2.pre, _T("pic\\è��.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\è��s.jpg"), button2.length, button2.width, true);

	button2.tip = "��ʼ";

	Button button3(730, 373, 38, 38);
	loadimage(&button3.pre, _T("pic\\��Ϸ.jpg"), button3.length, button3.width, true);
	loadimage(&button3.back, _T("pic\\��Ϸ.jpg"), button3.length, button3.width, true);

	button3.tip = "��Ϸ";

	Button button4(780, 372, 38, 38);
	loadimage(&button4.pre, _T("pic\\˵��.jpg"), button4.length, button4.width, true);
	loadimage(&button4.back, _T("pic\\˵��.jpg"), button4.length, button4.width, true);

	button4.tip = "˵��";

	Button button5(730, 303, 40, 40);
	if (play) {
		loadimage(&button5.pre, _T("pic\\����.jpg"), button5.length, button5.width, true);
		loadimage(&button5.back, _T("pic\\����.jpg"), button5.length, button5.width, true);
		button5.tip = "����";
	}
	else {
		loadimage(&button5.pre, _T("pic\\����.jpg"), button5.length, button5.width, true);
		loadimage(&button5.back, _T("pic\\����.jpg"), button5.length, button5.width, true);
		button5.tip = "����";
	}

	Button button6(860, 550, 45, 45);
	loadimage(&button6.pre, _T("pic\\����.jpg"), button6.length, button6.width, true);
	loadimage(&button6.back, _T("pic\\����.jpg"), button6.length, button6.width, true);

	Button button7(1010, 550, 80, 40);
	loadimage(&button7.pre, _T("pic\\�˳�.jpg"), button7.length, button7.width, true);
	loadimage(&button7.back, _T("pic\\�˳�.jpg"), button7.length, button7.width, true);

	Button button8(960, 550, 45, 45);
	loadimage(&button8.pre, _T("pic\\�ʵ�.jpg"), button8.length, button8.width, true);
	loadimage(&button8.back, _T("pic\\�ʵ�.jpg"), button8.length, button8.width, true);

	Button button9(910, 550, 45, 45);
	loadimage(&button9.pre, _T("pic\\���.jpg"), button9.length, button9.width, true);
	loadimage(&button9.back, _T("pic\\���.jpg"), button9.length, button9.width, true);

	IMAGE pay;
	loadimage(&pay, _T("pic\\΢��֧��.jpg"), 280, 380, true);
	IMAGE egg1;
	loadimage(&egg1, _T("pic\\�ʵ�_1.jpeg"), 280, 360, true);
	IMAGE egg2;
	loadimage(&egg2, _T("pic\\�ʵ�_2.jpeg"), 280, 360, true);

	IMAGE girl;
	loadimage(&girl, _T("pic\\girl.jpg"), 150, 200, true);
	IMAGE cat;
	loadimage(&cat, _T("pic\\Сè��.jpg"), 480, 282, true);
	IMAGE blank;
	loadimage(&blank, _T("pic\\�Ի���.jpg"), 240, 175, true);

	button3.stop = true;
	button4.stop = true;
	button5.stop = true;
	button6.stop = true;

	bool flag1 = false;//�Ƿ��Ѿ����˿���1
	bool flag2 = false;//�Ƿ��Ѿ����˿���2

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
			//�˳����˵�������Ϸ
			if (flag) {
				buttonMusic();
				closeBeginMusic();
				break;
			}
			else {
				buttonMusic();
				int color = 0;
				settextstyle(30, 0, "΢���ź�");
				while (color <= 255)
				{
					settextcolor(RGB(color, color, color));
					outtextxy(470, 550, "���ȿ�һ��˵��Ŷ");
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

			settextstyle(28, 0, _T("΢���ź�"));
			settextcolor(BLACK);
			outtextxy(button1.x - 100, button1.y, "WSAD�������ƶ���������ȷ���������");
			outtextxy(button1.x - 100, button1.y + 32, "��ESC��������ͣ�����������Ժ���԰�R��");
			outtextxy(button1.x - 100, button1.y + 64, "ʹ�ü��ܡ�����С�ּ��ɻ�ý�ң�����ܹ�");
			outtextxy(button1.x - 100, button1.y + 96, "���̵��й�����Ʒ�������̵�����ʤ�Ľݾ��ޡ�");
			outtextxy(button1.x - 100, button1.y + 128, "������Ϸ֮ǰ�����Ȱ��Լ������뷨����Ӣ�ġ�");
			outtextxy(button1.x - 100, button1.y + 160, "��ܰ��ʾ������װ��C�̣����ù���ԱȨ�޴򿪡�");
			outtextxy(button1.x - 100, button1.y + 192, "����Ϊʲô��Сèͻ����Լ��Ҳʵ���^-w-^");

			buttons.show();
			buttonMusic();
		}
		else if (kind == 4) {
			buttonMusic();
			if (play) {
				loadimage(&button5.pre, _T("pic\\����.jpg"), button5.length, button5.width, true);
				loadimage(&button5.back, _T("pic\\����.jpg"), button5.length, button5.width, true);
				buttons.buttons[4] = button5;
				buttons.buttons[4].stop = false;
			}
			else {
				loadimage(&button5.pre, _T("pic\\����.jpg"), button5.length, button5.width, true);
				loadimage(&button5.back, _T("pic\\����.jpg"), button5.length, button5.width, true);
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
		//�ʵ�����
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

		settextstyle(25, 0, _T("΢���ź�"));

		outtextxy(210, 65, "XG��,�ҳ�ȥ��");
		outtextxy(665, 200, "�������ţ���");
		FlushBatchDraw();

		clicked();

		putimage(168, 30, &blank);
		putimage(30, 110, &girl);
		putimage(580, 170, &cat);
		outtextxy(200, 63, "���ã�����HG����");
		outtextxy(200, 93, "XG�����ܣ�");
		outtextxy(650, 200, "������������");
		FlushBatchDraw();

		clicked();

		setbkcolor(WHITE);
		cleardevice();
		buttons.show();
		settextstyle(25, 0, _T("΢���ź�"));
		int t = 3;
		IMAGE img;

		while (t--)
		{
			for (int i = 1; i <= 26; i++)
			{
				string str = "pic\\ս��\\ս��_" + to_string(i) + ".jpeg";
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
		outtextxy(685, 200, "QG��");
		FlushBatchDraw();
		clicked();

		putimage(580, 170, &cat);
		outtextxy(623, 200, "QG�������ˣ���Ҫȥ");
		outtextxy(623, 230, "��QG����Ȼ��ûè��");
		outtextxy(623, 260, "���˦�(�� �㧥 ��;)��");
		FlushBatchDraw();
		}
		else if (kind == 8) {
			buttonMusic();
			setbkcolor(WHITE);
			cleardevice();
			//��ʾ֧��ͼƬ
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
	loadimage(&button1.pre, _T("pic\\�����Ѷ�.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\�����Ѷ�.jpg"), button1.length, button1.width, true);

	Button button2(460, 250, 180, 60);
	loadimage(&button2.pre, _T("pic\\�����Ѷ�.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\�����Ѷ�.jpg"), button2.length, button2.width, true);

	Button button3(460, 350, 180, 60);
	loadimage(&button3.pre, _T("pic\\��ǿ�Ѷ�.jpg"), button3.length, button3.width, true);
	loadimage(&button3.back, _T("pic\\��ǿ�Ѷ�.jpg"), button3.length, button3.width, true);

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
	mciSendString("open music\\��ť��Ч.mp3 alias button", NULL, 0, NULL);
	mciSendString("play button", NULL, 0, NULL);
}

void Menu::paoMusic() {
	if (!play) {
		return;
	}
	mciSendString("close paopao", NULL, 0, NULL);
	mciSendString("open music\\����.mp3 alias paopao", NULL, 0, NULL);
	mciSendString("play paopao", NULL, 0, NULL);
}

void Menu::beginMusic() {
	if (!play) {
		return;
	}
	mciSendString("open music\\��ʼ�˵�.mp3 alias beginMusic", NULL, 0, NULL);
	mciSendString("play beginMusic repeat", NULL, 0, NULL);
}

void Menu::closeBeginMusic() {
	mciSendString("stop beginMusic", NULL, 0, NULL);
}

void Menu::startMovie() {
	beginMusic();

	IMAGE img;

	Button button(530, 530, 40, 40);
	loadimage(&button.pre, _T("pic\\��Դ.jpg"), button.length, button.width, true);
	loadimage(&button.back, _T("pic\\��Դ.jpg"), button.length, button.width, true);

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
			string str = "pic\\��ʼ����\\��ʼ����_" + to_string(i) + ".jpeg";
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
	loadimage(&xiao2, _T("pic\\С2.jpg"), length, width, true);
	loadimage(&mao, _T("pic\\è.jpg"), length, width, true);
	loadimage(&tu, _T("pic\\ͻ.jpg"), length, width, true);
	loadimage(&ji, _T("pic\\��.jpg"), length, width, true);
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

	settextstyle(22, 0, _T("΢���ź�"));
	IMAGE img;
	while (t--)
	{
		for (int i = 1; i <= 60; i++) {
			string str = "pic\\����ʧ��\\����ʧ��_" + to_string(i) + ".jpeg";
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
	loadimage(&cat, _T("pic\\Сè��.jpg"), 480, 282, true);

	if (play) {
		mciSendString("open music\\����.mp3 alias jokeMusic", NULL, 0, NULL);
		mciSendString("play jokeMusic repeat", NULL, 0, NULL);
	}

	putimage(580, 170, &cat);
	outtextxy(623, 200, "��Ȼ���ǾȲ���QG��...");
	outtextxy(623, 230, "�����һ��ǻ�ȥ����C10��");
	outtextxy(623, 260, "��è���...");

	Buttons buttons;
	Button button1(960, 550, 45, 45);
	loadimage(&button1.pre, _T("pic\\����.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\����.jpg"), button1.length, button1.width, true);
	Button button2(1010, 550, 80, 40);
	loadimage(&button2.pre, _T("pic\\�˳�.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\�˳�.jpg"), button2.length, button2.width, true);

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
	loadimage(&cat, _T("pic\\Сè��.jpg"), 480, 282, true);

	setfillcolor(RGB(218, 209, 104));
	setlinecolor(RGB(218, 209, 104));

	settextstyle(22, 0, _T("΢���ź�"));
	settextcolor(BLACK);
	int t = 3;

	IMAGE img;
	while (t--)
	{
		for (int i = 1; i <= 14; i++) {
			string str = "pic\\���سɹ�\\���سɹ�_" + to_string(i) + ".jpeg";
			LPCSTR pstr = str.c_str();
			loadimage(&img, pstr, 1100, 600, true);
			putimage(0, 0, &img);
			fillrectangle(0, 400, 250, 600);
			FlushBatchDraw();
			Sleep(45);
		}
	}
	if (play) {
		mciSendString("open music\\����.mp3 alias jokeMusic", NULL, 0, NULL);
		mciSendString("play jokeMusic repeat", NULL, 0, NULL);
	}
	t = 3;
	while (t--)
	{
		for (int i = 1; i <= 33; i++) {
			string str = "pic\\Ƿ��\\Ƿ��_" + to_string(i) + ".jpeg";
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
	outtextxy(623, 200, "��������̫����");
	outtextxy(623, 230, "Ƿ���Ѿ����Ƿ����");

	FlushBatchDraw();

	Buttons buttons;
	Button button1(960, 550, 45, 45);
	loadimage(&button1.pre, _T("pic\\����.jpg"), button1.length, button1.width, true);
	loadimage(&button1.back, _T("pic\\����.jpg"), button1.length, button1.width, true);
	Button button2(1010, 550, 80, 40);
	loadimage(&button2.pre, _T("pic\\�˳�.jpg"), button2.length, button2.width, true);
	loadimage(&button2.back, _T("pic\\�˳�.jpg"), button2.length, button2.width, true);

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