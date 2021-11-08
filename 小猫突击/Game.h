#ifndef GAME_H
#define GAME_H
#include<conio.h>
#include"view.h"
#include"Menu.h"

class Game
{
public:
	Game();
	void playGame1();
	void playGame2();
	void playGame3();
	void playGame4();
	void playGame5();
	void playGame6();

	void playGame3Plus();
	void playGame6Plus();

	void playGame();
	void stopTime();//休闲时间

	void printTip(string str);

	void deleteMemory();//释放内存并把指针设为空指针
	~Game();

	Menu* pMenu;
	LittleSprite* pSprite;
	Boss* pBoss;
	CatStore* pStore;
	Cat* pCat;
	Map* pMap;
	Fish* pFish;
	Bullet* pBullet;

	int isSleep;//记录休息间隔时间
	int counter;
	int isDie;
	int musicCounter;
	bool flag;//是否加载开场动画
	//IMAGE bk1;
};

#endif //GAME_H