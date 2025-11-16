#pragma once

#include "Entity.hpp"
#include "Map.hpp"
class Player : public Entity {
public:
	Player(int mx, int my, Map& world);
	void render(SDL_Renderer* renderer) override;
	void updatePosition(int moveDirection);
	void updateGlobalPosition(int mx, int my);
	void updateMapPosition(int x, int y);
	bool checkCollision(int moveDirection);
	void setMapCoords(int xm, int ym);
protected:
	int m_MapX;
	int m_MapY;
	Map& m_World;
};