#pragma once

#include "Entity.hpp"

class Wall : public Entity {
public:
	Wall(int x,int y,int width,int height);
	void render(SDL_Renderer* renderer) override;
	int wallWidth();
	int wallHeight();
private:
	int m_Width;
	int m_Height;

};