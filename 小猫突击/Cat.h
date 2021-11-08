#ifndef CAT_H
#define CAT_H
#include<graphics.h>
#include<cmath>
#include"Map.h"

const int RedTextX = 15;
const int RedTexY = 545;
const int BlueTextX = 15;
const int BlueTextY = 575;//设置文本所需xy坐标
const int ETextX = 15;
const int ETextY = 515;

const int CatLength = 100;
const int CatWidth = 50;

class Cat {
public:
	Cat();
	~Cat();
	bool ifMove(Map*, float, float, int);
	void catLoad();//载入猫猫初始图片的函数
	void catSize(int, int);//设置猫猫大小
	void catSetSpeed(float);//设置猫猫速度大小
	void catRed(float = 0);//改变猫猫的体力值
	void catBlue(float = 0);//改变猫猫的精力值
	void catSkill(float = 0);//改变能量条
	void catMove(Map*);//获取用户的键盘状态，改变猫猫坐标
	void catShow();//绘制猫猫血条蓝条和猫猫自己
	float catSpeed = 1.5, catHealth = 100.0, catMagic = 100.0, catEnergy = 0.0,
		catRed_x1 = 60, catRed_y1 = 550, catRed_x2 = 160, catRed_y2 = 566,//绘制血条所需要的两点

		catBlue_x1 = 60, catBlue_y1 = 580, catBlue_x2 = 160, catBlue_y2 = 596,//绘制蓝条所需要的两点

		catE_x1 = 60, catE_y1 = 520, catE_x2 = 60, catE_y2 = 536,//绘制能量条需要的两点

		catX = 550, catY = 500;//猫猫所在x，y坐标

	int catSize_length = 100;
	int catSize_width = 50; //猫猫图片大小

	int	catLOR = 1;//判断当前猫猫朝向，0为左，1为右

	int hurt = 0;

	//定义猫猫当前状态，0-1代表正常，2-3代表生命值在（0，50],4-5代表生命值不大于0，即死亡
	//0代表正常左，1代表正常右，2代表受伤左，3代表受伤右，4代表死亡左，5代表死亡右
	int	catState = 0;

	int	prePic = 1;//记录之前载入的图片，防止重复载入降低效率

	IMAGE catPic, catPic_s,catHurt,catHurts;//创建图片对象，以便载入图像进行显示
};
#endif //CAT_H
