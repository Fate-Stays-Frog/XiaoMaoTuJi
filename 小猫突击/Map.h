#ifndef MAP_H
#define MAP_H
#include<iostream>
#include<fstream>
#include<string>
#include<graphics.h>
#include<vector>
#include"Point.h"
using namespace std;

const int MapLength = 12;
const int MapWidth = 22;

class Map
{
public:
	Map();
	~Map();
	void loadMap(int kind);//kind��ʾ�ڼ��ŵ�ͼ
	void initPic();//����ͼƬ
	void showMap();//չʾש��
	int map[MapLength][MapWidth];
	vector<Point>vectorMap;
};

#endif //MAP_H