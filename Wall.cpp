#include "Wall.hpp"

Wall::Wall(int x, int y, int width, int height) : Entity() {
	m_Color = { 255,255,255,255 };
	m_X = x;
	m_Y = y;
	m_Width = width;
	m_Height = height;
}
int Wall::wallWidth() {
	return m_Width;
}

int Wall::wallHeight() {
	return m_Height;
}

void Wall::render(SDL_Renderer* renderer) {
	SDL_FRect rect;
	SDL_SetRenderDrawColor(renderer,
		m_Color.r,
		m_Color.b,
		m_Color.g,
		m_Color.a);

	rect = {
		(float)getX(),
		(float)getY(),
		(float)wallWidth(),
		(float)wallHeight()
	};

	SDL_RenderFillRect(renderer, &rect);
}