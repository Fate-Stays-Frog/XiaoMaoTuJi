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
	void animation();//���ֵ���+��������
	void select();//ѡ�񰴼�
	void startMovie();//�����ʱ�Ķ���
	void paoMusic();//�������ݵ�����
	void buttonMusic();//���ŵ����ť������
	void beginMusic();//���ſ�ʼ�˵�������
	void closeBeginMusic();//�رտ�ʼ�˵�������
	void showMenu();//չʾ�˵�
	void gameOver();
	void winGame();
	void selectLevel();//ѡ���Ѷ�
};

#endif //MENU_H