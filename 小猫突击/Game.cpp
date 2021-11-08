#include "Game.h"

Game::Game() {
	pMenu = NULL;
	pSprite = NULL;
	pBoss = NULL;
	pStore = NULL;
	pCat = NULL;
	pMap = NULL;
	pBullet = NULL;
	pFish = NULL;
	this->isSleep = 0;
	this->counter = 0;
	this->isDie = 0;
	this->musicCounter = 0;
	this->flag = true;
}

void Game::deleteMemory() {
	delete pMenu;
	delete pSprite;
	delete pBoss;
	delete pStore;
	delete pCat;
	delete pMap;
	delete pFish;
	delete pBullet;
	pMenu = NULL;
	pSprite = NULL;
	pBoss = NULL;
	pStore = NULL;
	pCat = NULL;
	pMap = NULL;
	pFish = NULL;
	pBullet = NULL;
}

void Game::printTip(string str) {
	int i = 0;
	while (i<=240)
	{
		settextstyle(40, 0, "微软雅黑");
		settextcolor(RGB(i, i, i));
		outtextxy(500, 50, str.c_str());
		i += 15;
		FlushBatchDraw();
		Sleep(40);
	}
}

void Game::playGame1() {
	clearBullet();
	pSprite = new LittleSprite(2, 80, 45, 2, 2);
	pSprite->init();
	pBullet->init();
	pFish->init();
	pSprite->loadPositon();
	pMap->loadMap(1);

	pCat->catX = 550;
	pCat->catY = 500;

	isDie = 0;

	bool flag = false;

	while (true)
	{
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}
		catAoligeiLs(*pCat, 12, *pSprite);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		pMap->showMap();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pSprite->generate();
		pSprite->move(pMap);

		littleSpriteShoot(*pCat, *pSprite);
		showBullet();
		showFishLs(*pSprite);

		catBullet(*pCat);
		littleSpriteFish(*pSprite, *pCat, true);
		pSprite->die(pStore);

		//暂停相关
		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pSprite->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close gameMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close gameMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第一关");
			flag = true;
		}
	}
}

void Game::playGame2() {
	bool flag = false;

	clearBullet();
	pSprite = new LittleSprite(2, 80, 45, 2, 5);
	pSprite->init();
	pBullet->init();
	pFish->init();
	pSprite->loadPositon();
	pMap->loadMap(1);

	isDie = 0;

	pCat->catX = 550;
	pCat->catY = 500;

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		catAoligeiLs(*pCat, 12, *pSprite);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		pMap->showMap();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pSprite->generate();
		pSprite->move(pMap);

		littleSpriteShoot(*pCat, *pSprite);
		showBullet();
		showFishLs(*pSprite);

		catBullet(*pCat);
		littleSpriteFish(*pSprite, *pCat, true);
		pSprite->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pSprite->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close gameMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close gameMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第二关");
			flag = true;
		}
	}
}

void Game::playGame6Plus() {
	bool flag = false;

	clearBullet();
	pBoss = new Boss(3, BossLength1, BossWidth1, 1, 200);
	pBoss->init();
	pBullet->init();
	pFish->init();
	pMap->loadMap(2);

	pSprite = new LittleSprite(2, 80, 45, 3, 6);
	pSprite->init();
	pSprite->loadPositon();

	pCat->catX = 550;
	pCat->catY = 500;

	isDie = 0;

	pBoss->generate();

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		if (pBoss->died) {
			catAoligeiLs(*pCat, 12, *pSprite);
		}
		else {
			catAoligeiB(*pCat, 10, *pBoss);
		}

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		pMap->showMap();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pBoss->move(pMap);

		boss_shoot1(*pCat, *pBoss);
		pSprite->generate();
		pSprite->move(pMap);

		littleSpriteShoot(*pCat, *pSprite);
		showBullet();
		showFishB(*pBoss);
		if (pBoss->died) {
			showFishLs(*pSprite);
		}
		else {
			showFishLs2(*pSprite);
		}

		littleSpriteFish(*pSprite, *pCat, false);
		pSprite->die(pStore);

		catBullet(*pCat);
		bossFish(*pBoss, *pCat);
		pBoss->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pSprite->died&&pBoss->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close bossMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close bossMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第三关");
			flag = true;
		}
	}
}

void Game::playGame3() {
	bool flag = false;

	clearBullet();
	pBoss = new Boss(3, BossLength1, BossWidth1, 1, 150);
	pBoss->init();
	pBullet->init();
	pFish->init();
	pMap->loadMap(2);

	pCat->catX = 550;
	pCat->catY = 500;

	isDie = 0;

	pBoss->generate();

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		catAoligeiB(*pCat, 10, *pBoss);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		pMap->showMap();
		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pBoss->move(pMap);

		boss_shoot1(*pCat, *pBoss);

		showBullet();
		showFishB(*pBoss);

		catBullet(*pCat);
		bossFish(*pBoss, *pCat);
		pBoss->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pBoss->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close bossMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close bossMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第三关");
			flag = true;
		}
	}
}

void Game::playGame6() {
	bool flag = false;

	clearBullet();
	pBoss = new Boss(3, BossLength2, BossWidth2, 2, 200);
	pBoss->init();
	pBullet->init();
	pFish->init();
	pMap->loadMap(4);

	pCat->catX = 550;
	pCat->catY = 500;

	isDie = 0;

	pBoss->generate();

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		if (pBoss->died) {
			catAoligeiLs(*pCat, 10, *pSprite);
		}
		catAoligeiB(*pCat, 12, *pBoss);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		pMap->showMap();
		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pBoss->move(pMap);

		boss_shoot2(*pCat, *pBoss);

		showBullet();
		showFishB(*pBoss);

		catBullet(*pCat);
		bossFish(*pBoss, *pCat);
		pBoss->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pBoss->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close bossMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close bossMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第六关");
			flag = true;
		}
	}
}

void Game::playGame4() {
	bool flag = false;

	clearBullet();
	pSprite = new LittleSprite(2, 80, 45, 3, 7);
	pSprite->init();
	pBullet->init();
	pFish->init();
	pSprite->loadPositon();
	pMap->loadMap(3);

	pCat->catX = 550;
	pCat->catY = 500;

	isDie = 0;

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		catAoligeiLs(*pCat, 12, *pSprite);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();
		pMap->showMap();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pSprite->generate();
		pSprite->move(pMap);

		littleSpriteShoot(*pCat, *pSprite);
		showBullet();
		showFishLs(*pSprite);

		catBullet(*pCat);
		littleSpriteFish(*pSprite, *pCat, true);
		pSprite->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pSprite->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close gameMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close gameMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第四关");
			flag = true;
		}
	}
}

void Game::playGame5() {
	bool flag = false;

	clearBullet();
	pSprite = new LittleSprite(2, 80, 45, 4, 8);
	pSprite->init();
	pBullet->init();
	pFish->init();
	pSprite->loadPositon();
	pMap->loadMap(3);

	isDie = 0;

	pCat->catX = 550;
	pCat->catY = 500;

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		catAoligeiLs(*pCat, 12, *pSprite);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();
		pMap->showMap();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pSprite->generate();
		pSprite->move(pMap);

		littleSpriteShoot(*pCat, *pSprite);
		showBullet();
		showFishLs(*pSprite);

		catBullet(*pCat);
		littleSpriteFish(*pSprite, *pCat, true);
		pSprite->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pSprite->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close gameMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close gameMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第五关");
			flag = true;
		}
	}
}

void Game::playGame3Plus() {
	bool flag = false;

	clearBullet();
	pBoss = new Boss(3, BossLength2, BossWidth2, 2, 300);
	pBoss->init();
	pBullet->init();
	pFish->init();
	memset(pMap->map, 0, sizeof(pMap->map));

	pCat->catX = 550;
	pCat->catY = 500;

	isDie = 0;

	pBoss->generate();

	while (true) {
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}
	
		catAoligeiB(*pCat, 10, *pBoss);

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		pBoss->move(pMap);

		boss_shoot2(*pCat, *pBoss);

		showBullet();
		showFishB(*pBoss);

		catBullet2(*pCat);
		bossFish(*pBoss, *pCat);
		pBoss->die(pStore);

		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		if (pBoss->died) {
			clearBullet();
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}
		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close bossMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close bossMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}

		if (!flag) {
			printTip("第六关");
			flag = true;
		}
	}
}

void Game::playGame() {
	pStore = new CatStore;
	pCat = new Cat;
	pMap = new Map;
	pMenu = new Menu;

	pCat->catSetSpeed(2);
	pCat->catLoad();
	pStore->storeLoad();
	pMap->initPic();
	setv(2);
	loadBuff();

	if (flag) {
		pMenu->startMovie();
		flag = false;
	}
	else {
		if (play) {
			mciSendString("open music\\开始菜单.mp3 alias beginMusic", NULL, 0, NULL);
			mciSendString("play beginMusic repeat", NULL, 0, NULL);
		}
	}
	pMenu->animation();
	pMenu->select();
	pMenu->selectLevel();

	if (level == 1) {
		pStore->money = 1000;
	}
	else if (level == 2) {
		pStore->money = 20;
	}
	else if (level == 3) {
		pStore->money = -25;
	}

	if (play) {
		mciSendString("close gameMusic", NULL, 0, NULL);
		mciSendString("open music\\战斗音乐.mp3 alias gameMusic", NULL, 0, NULL);
		mciSendString("play gameMusic repeat", NULL, 0, NULL);
	}
	playGame1();

	stopTime();

	playGame2();

	if (play) {
		mciSendString("close gameMusic", NULL, 0, NULL);
		mciSendString("open music\\死神来了.mp3 alias bossMusic", NULL, 0, NULL);
		mciSendString("play bossMusic repeat", NULL, 0, NULL);
	}

	stopTime();

	if (level == 3) {
		playGame3Plus();
	}
	else {
		playGame3();
	}

	if (play) {
		mciSendString("close bossMusic", NULL, 0, NULL);
		mciSendString("open music\\战斗音乐.mp3 alias gameMusic", NULL, 0, NULL);
		mciSendString("play gameMusic repeat", NULL, 0, NULL);
	}

	stopTime();

	playGame4();

	stopTime();

	playGame5();

	if (play) {
		mciSendString("close gameMusic", NULL, 0, NULL);
		mciSendString("open music\\死神来了.mp3 alias bossMusic", NULL, 0, NULL);
		mciSendString("play bossMusic repeat", NULL, 0, NULL);
	}

	stopTime();

	if (level == 3) {
		playGame6Plus();
	}
	else {
		playGame6();
	}

	if (play) {
		mciSendString("close bossMusic", NULL, 0, NULL);
		mciSendString("close winMusic", NULL, 0, NULL);
		mciSendString("open music\\胜利.mp3 alias winMusic", NULL, 0, NULL);
		mciSendString("play winMusic", NULL, 0, NULL);
	}
	pMenu->winGame();
	deleteMemory();
	playGame();
}

void Game::stopTime() {
	clearBullet();
	memset(pMap->map, 0, sizeof(pMap->map));
	isSleep = 0;
	while (true)
	{
		counter++;
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				addFish(*pCat, m);
				musicCounter++;
				if (musicCounter >= 3) {
					musicCounter = 0;
					if (play) {
						mciSendString("close shootMusic", NULL, 0, NULL);
						mciSendString("open music\\射击.mp3 alias shootMusic", NULL, 0, NULL);
						mciSendString("play shootMusic", NULL, 0, NULL);
					}
				}
				break;
			}
		}

		setbkcolor(RGB(254, 237, 211));
		cleardevice();

		storeInfo1(*pStore);

		pCat->catMove(pMap);
		pCat->catShow();

		showFishLs(*pSprite);
		int returnstar = 0;
		if (!isDie) {
			if ((GetAsyncKeyState(0x1B) & 0x8000)) {//esc键盘进入暂停
				while (1) {
					stopPage();//弹出暂停页面
					if (MouseHit()) {
						MOUSEMSG m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							if (m.x >= 260 && m.x <= 385 && m.y >= 226 && m.y <= 348) {//继续
								break;
							}
							else if (m.x >= 505 && m.x <= 633 && m.y >= 237 && m.y <= 353) {//猫猫商店
								pStore->ifShowStore();
							}
							else if (m.x >= 763 && m.x <= 872 && m.y >= 241 && m.y <= 352) {//回到主菜单
								returnstar = 1; break;
							}
						}
					}
					FlushBatchDraw();
				}
			}

			buff(*pStore, *pCat);
			if (counter % 20000 == 0) {
				counter = 1;
				pStore->openstore = 0;
				pStore->storeNew();
			}
		}

		FlushBatchDraw();
		deleteBullet(pMap);
		Sleep(3);

		isSleep++;
		if (isSleep >= 666) {
			break;
		}

		if (pCat->catHealth <= 0) {
			isDie++;
			if (isDie == 1 && play) {
				mciSendString("close laughMusic", NULL, 0, NULL);
				mciSendString("open music\\奸笑.mp3 alias laughMusic", NULL, 0, NULL);
				mciSendString("play laughMusic", NULL, 0, NULL);
			}
		}

		if (isDie >= 333) {
			isDie = 0;
			if (play) {
				mciSendString("close bossMusic", NULL, 0, NULL);
				mciSendString("close loseMusic", NULL, 0, NULL);
				mciSendString("open music\\失败.mp3 alias loseMusic", NULL, 0, NULL);
				mciSendString("play loseMusic", NULL, 0, NULL);
			}
			clearBullet();
			pMenu->gameOver();
			deleteMemory();
			playGame();
		}

		if (returnstar) {
			mciSendString("close gameMusic", NULL, 0, NULL);
			isDie = 0;
			clearBullet();
			deleteMemory();
			playGame();
		}
	}
}

Game::~Game() {
	delete pMenu;
	delete pSprite;
	delete pBoss;
	delete pStore;
	delete pCat;
	delete pMap;
}