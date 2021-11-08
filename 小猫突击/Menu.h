#ifndef MENU_H
#define MENU_H
#include<graphics.h>
#include<string>
#include<conio.h>
#include<fstream>
#include"Value.h"
#include"Buttons.h"
using namespace std;

class Menu {
public:
	Menu();
	~Menu();
	void animation();//文字弹跳+闪屏动画
	void select();//选择按键
	void startMovie();//软件打开时的动画
	void paoMusic();//播放泡泡的声音
	void buttonMusic();//播放点击按钮的声音
	void beginMusic();//播放开始菜单的音乐
	void closeBeginMusic();//关闭开始菜单的音乐
	void showMenu();//展示菜单
	void gameOver();
	void winGame();
	void selectLevel();//选择难度
};

#endif //MENU_H