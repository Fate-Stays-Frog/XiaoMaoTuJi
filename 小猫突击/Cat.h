#ifndef CAT_H
#define CAT_H
#include<graphics.h>
#include<cmath>
#include"Map.h"

const int RedTextX = 15;
const int RedTexY = 545;
const int BlueTextX = 15;
const int BlueTextY = 575;//�����ı�����xy����
const int ETextX = 15;
const int ETextY = 515;

const int CatLength = 100;
const int CatWidth = 50;

class Cat {
public:
	Cat();
	~Cat();
	bool ifMove(Map*, float, float, int);
	void catLoad();//����èè��ʼͼƬ�ĺ���
	void catSize(int, int);//����èè��С
	void catSetSpeed(float);//����èè�ٶȴ�С
	void catRed(float = 0);//�ı�èè������ֵ
	void catBlue(float = 0);//�ı�èè�ľ���ֵ
	void catSkill(float = 0);//�ı�������
	void catMove(Map*);//��ȡ�û��ļ���״̬���ı�èè����
	void catShow();//����èèѪ��������èè�Լ�
	float catSpeed = 1.5, catHealth = 100.0, catMagic = 100.0, catEnergy = 0.0,
		catRed_x1 = 60, catRed_y1 = 550, catRed_x2 = 160, catRed_y2 = 566,//����Ѫ������Ҫ������

		catBlue_x1 = 60, catBlue_y1 = 580, catBlue_x2 = 160, catBlue_y2 = 596,//������������Ҫ������

		catE_x1 = 60, catE_y1 = 520, catE_x2 = 60, catE_y2 = 536,//������������Ҫ������

		catX = 550, catY = 500;//èè����x��y����

	int catSize_length = 100;
	int catSize_width = 50; //èèͼƬ��С

	int	catLOR = 1;//�жϵ�ǰèè����0Ϊ��1Ϊ��

	int hurt = 0;

	//����èè��ǰ״̬��0-1����������2-3��������ֵ�ڣ�0��50],4-5��������ֵ������0��������
	//0����������1���������ң�2����������3���������ң�4����������5����������
	int	catState = 0;

	int	prePic = 1;//��¼֮ǰ�����ͼƬ����ֹ�ظ����뽵��Ч��

	IMAGE catPic, catPic_s,catHurt,catHurts;//����ͼƬ�����Ա�����ͼ�������ʾ
};
#endif //CAT_H
