#ifndef BUTTONS_H
#define BUTTONS_H
#include "Button.h"

class Buttons {
public:
	Buttons();
	~Buttons();
	void show();//显示图片
	int click();//点击特效实现
	vector<Button>buttons;//存放按钮的向量
	bool flag;//是否按下
};

#endif //BUTTONS_H