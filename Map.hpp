#pragma once

#include <vector>
#include <string>

#include "Consts.hpp"

class Map {
public:
	Map();
	bool getFromFile(std::string filename);
	unsigned size();
	bool isWall(int coord);
	int coord(int x, int y);
private:
	unsigned m_MapSize;
	std::vector<int> m_Map;
};