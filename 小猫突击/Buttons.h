#ifndef BUTTONS_H
#define BUTTONS_H
#include "Button.h"

class Buttons {
public:
	Buttons();
	~Buttons();
	void show();//��ʾͼƬ
	int click();//�����Чʵ��
	vector<Button>buttons;//��Ű�ť������
	bool flag;//�Ƿ���
};

#endif //BUTTONS_H