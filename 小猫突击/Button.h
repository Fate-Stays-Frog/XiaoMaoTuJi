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
	void hide();//隐藏该按钮

	int x, y;//左上角坐标
	int length;//长
	int width;//宽
	IMAGE pre;//选择前照片
	IMAGE back;//选择后照片
	bool stop;//停止该按键的功能，起屏蔽作用
	string tip;//按钮的注解
};

#endif //BUTTON_H