#ifndef BLOOD_H
#define BLOOD_H
#include"Point.h"
#include<graphics.h>

class Blood {
public:
	//构造函数
	//参数：长、宽、左上角的坐标
	Blood(int width = 0, int length = 0);
	~Blood();
	int bloodLength;//血条长度
	int bloodWidth;//血条宽度
};

#endif //BLOOD_H