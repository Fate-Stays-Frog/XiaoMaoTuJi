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
	void stopTime();//����ʱ��

	void printTip(string str);

	void deleteMemory();//�ͷ��ڴ沢��ָ����Ϊ��ָ��
	~Game();

	Menu* pMenu;
	LittleSprite* pSprite;
	Boss* pBoss;
	CatStore* pStore;
	Cat* pCat;
	Map* pMap;
	Fish* pFish;
	Bullet* pBullet;

	int isSleep;//��¼��Ϣ���ʱ��
	int counter;
	int isDie;
	int musicCounter;
	bool flag;//�Ƿ���ؿ�������
	//IMAGE bk1;
};

#endif //GAME_H