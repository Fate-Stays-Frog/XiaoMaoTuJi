#ifndef BUTTON_H
#define BUTTON_H
#include<graphics.h>
#include<iostream>
#include<vector>
using namespace std;

class Button
{
public:
	Button(int x = 0, int y = 0, int length = 0, int width = 0);
	~Button();
	void hide();//���ظð�ť

	int x, y;//���Ͻ�����
	int length;//��
	int width;//��
	IMAGE pre;//ѡ��ǰ��Ƭ
	IMAGE back;//ѡ�����Ƭ
	bool stop;//ֹͣ�ð����Ĺ��ܣ�����������
	string tip;//��ť��ע��
};

#endif //BUTTON_H