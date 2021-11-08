#ifndef CATSTORE_H
#define CATSTORE_H
#include<graphics.h>
#include<iostream>
#include<ctime>
#include"Value.h"
using namespace std;

class CatStore {
public:
	CatStore();
	~CatStore();
	void storeLoad();
	void ifShowStore();
	void storeChange();
	void showStore();
	void printTip();
	void storeNew();
	void showTip();
	int item[6] = { 2,2,2,2,1,1 };
	int foodnum = 0;
	int money = 20;
	int leave = 0;
	IMAGE s, food, foods, leaf, leafs, guantou, guantous,milk,milks, jinbi, jinbis, cost, costs, tip, tips;
	int cost_food = 6, cost_leaf = 10, cost_guantou = 15,cost_milk=20, choice = 0, mincost = 10;
	int buff_leaf = 0, buff_guantou = 0,buff_milk=0, openstore = 0;
	float bufftime_leaf = 0, bufftime_guantou = 0, bufftime_milk = 0;
	MOUSEMSG m;
};
#endif //CATSTORE_H
