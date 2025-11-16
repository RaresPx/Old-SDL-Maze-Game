#include "Map.hpp"

#include <fstream>
#include <iostream>

Map::Map() : m_MapSize(0), m_Map(0) {};

bool Map::getFromFile(std::string filename){
	std::fstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to load map from"<<filename<<std::endl;
		return false;
	}
	file >> m_MapSize;
	m_Map.resize(m_MapSize * m_MapSize);
	for (unsigned i = 0; i < m_MapSize * m_MapSize; ++i) {
		file >> m_Map[i];
	}
	for (int i = 0; i < m_MapSize; i++)
		for (int j = i+1 ; j < m_MapSize; j++) {
			std::swap(m_Map[coord(i, j)], m_Map[coord(j, i)]);
		}
			

	file.close();
	return true;
}

unsigned Map::size() {
	return m_MapSize;
}

bool Map::isWall(int coord) {
	if(coord > -1 && coord < (int)(m_MapSize * m_MapSize))
		return m_Map[coord];
	return 0;
}

int Map::coord(int x, int y) {
	if (x >= m_MapSize || x <= -1 || y >= m_MapSize || y <= -1)
		return -1;
	return m_MapSize * x + y;
}