#pragma once

#include <SDL3/SDL.h>

class Entity {
public:
	Entity();
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual ~Entity() = default;
	int getX();
	int getY();
	SDL_Color m_Color;
protected:
	int m_X, m_Y;
	
};