#include "Map.h"

IMAGE block;

Map::Map() {
	memset(map, 0, sizeof map);
}

void Map::initPic() {
	loadimage(&block, "pic\\map.jpg", 50, 50, true);
}

void Map::loadMap(int kind) {
	vectorMap.clear();
	ifstream ifs;
	ifs.open("map\\map" + to_string(kind) + ".jpg", ios::out);
	for (int i = 0; i < MapLength; i++) {
		for (int j = 0; j < MapWidth; j++) {
			ifs >> map[i][j];
			if (map[i][j]) {
				vectorMap.push_back(Point(i, j));
			}
		}
	}
	ifs.close();
}

void Map::showMap() {
	for (auto& point : vectorMap) {
		putimage(point.y * 50, point.x * 50, &block);
	}
}

Map::~Map() {}