#include"Game.h"

#pragma comment(lib,"Winmm.lib")
#pragma warning(disable:4717)

void mainLoop() {
	Game* pGame = new Game;
	pGame->playGame();
	delete pGame;
}

int main() {
	srand((unsigned int)time(NULL));
	initgraph(Length, Width);
	setbkcolor(WHITE);
	cleardevice();
	BeginBatchDraw();

	mainLoop();

	EndBatchDraw();
	_getch();
	closegraph();
}