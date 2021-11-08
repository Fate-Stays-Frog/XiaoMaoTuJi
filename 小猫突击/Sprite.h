#ifndef SPRITE_H
#define SPRITE_H
#include<Windows.h>
#include<graphics.h>
#include<string>
#include<vector>
#include"Node.h"
#include"Map.h"
#include"CatStore.h"
#include"Value.h"
using namespace std;

class Sprite {
public:
	//构造函数
	//参数：速度，长，宽
	Sprite(int length = 0, int width = 0);
	//射击
//	virtual void shoot(Cat) = 0;
	//移动
	virtual void move(Map*) = 0;
	//生成精灵
	virtual void generate() = 0;
	//死亡判断
	virtual void die(CatStore* catStore) = 0;
	~Sprite();
	int length;//长
	int width;//宽
	int speed;//速度
	int isMove;//是否移动
	bool died;//是否已经死亡
	int isChange;//是否改变方向
};

#endif //SPRITE_H