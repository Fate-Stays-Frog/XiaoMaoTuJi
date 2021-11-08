#ifndef LITTLE_SPRITE_H
#define LITTLE_SPRITE_H
#include"Sprite.h"
const int SpriteLength = 80;
const int SpriteWidth = 45;

class LittleSprite :
	public Sprite {
public:
	LittleSprite(int speed, int length, int width, int maxNums, int sumNums)
		:Sprite(length, width) {
		//memset(isExsited, 0, sizeof isExsited);
		this->maxNums = maxNums;
		this->sumNums = sumNums;
		this->counter = 0;
		this->isShoot = 0;
		this->isMove = 0;
		this->isGenerate = 0;
		this->speed = speed;
		this->died = false;
	}
	~LittleSprite();
	//移动
	void move(Map*);
	//绘画
	//血条+图片
	void paint();
	//加载图片
	void init();
	//生成精灵
	void generate();
	//死亡判断
	void die(CatStore* catStore);
	//加载位置
	void loadPositon();

	//在地图上生成的位置
	vector<Node>position;
	//存储小怪属性的vector
	vector<Node>nums;

	////判断各个位置是否已经存在精灵
	//bool isExsited[5][4];

	//最多同时存在几只小怪
	int maxNums;
	//总共生成几只小怪
	int sumNums;
	//是否生成
	int isGenerate;

	//注意 maxNums<=sumNums

	//记数当前总共已经生成了多少的小怪
	int counter;

	//控制攻速
	int isShoot;

	//全部死亡标记
	bool died;
};
#endif //LITTLE_SPRITE_H