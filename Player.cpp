#include "Player.hpp"
#include "Consts.hpp"

Player::Player(int mx, int my, Map& world)
	:m_MapX(mx), m_MapY(my), m_World(world)
{
	m_Color = { 145,120,167,255 };
	m_X = OFFSET_X + WALL_WIDTH/4 + mx*WALL_WIDTH;
	m_Y = OFFSET_Y + WALL_HEIGHT/4 + my * WALL_HEIGHT;
}

void Player::updatePosition(int moveDirection) {
	switch (moveDirection) {
		case MOVE_UP:
			if(!checkCollision(moveDirection))
				m_MapY--;
			break;
		case MOVE_RIGHT:
			if (!checkCollision(moveDirection))
				m_MapX++;
			break;
		case MOVE_DOWN:
			if (!checkCollision(moveDirection))
				m_MapY++;
			break;
		case MOVE_LEFT:
			if (!checkCollision(moveDirection))
				m_MapX--;
			break;
		default:
			break;

	}
	updateGlobalPosition(m_MapX, m_MapY);
}
void Player::render(SDL_Renderer* renderer)
 {
	SDL_FRect rect;
	SDL_SetRenderDrawColor(renderer,
		m_Color.r,
		m_Color.b,
		m_Color.g,
		m_Color.a);

	rect = {
		(float)getX(),
		(float)getY(),
		(float)PLAYER_SIZE,
		(float)PLAYER_SIZE
	};

	SDL_RenderFillRect(renderer, &rect);
}

void Player::updateGlobalPosition(int mx, int my) {
	int tx = OFFSET_X + WALL_WIDTH / 4 + mx * WALL_WIDTH;
	int ty = OFFSET_Y + WALL_HEIGHT / 4 + my * WALL_HEIGHT;
	if (ty <= WINDOW_DEFAULT_HEIGHT && ty >= 0 && tx <= WINDOW_DEFAULT_WIDTH && tx >= 0) {
		m_X = tx;
		m_Y = ty;
	}
	else {
		updateMapPosition(m_X, m_Y);
	}
}
void Player::updateMapPosition(int x, int y) {
	m_MapX = (x - OFFSET_X - WALL_WIDTH / 4) / WALL_WIDTH;
	m_MapY = (y - OFFSET_Y - WALL_HEIGHT / 4) / WALL_HEIGHT;
}
void Player::setMapCoords(int xm, int ym) {
	if (xm >= 0 && ym >= 0 && xm < m_World.size() && ym < m_World.size()) {
		m_MapX = xm;
		m_MapY = ym;
	}
}
bool Player::checkCollision(int moveDirection) {
	switch (moveDirection) {
	case MOVE_UP:
		if (m_World.isWall(m_World.coord(m_MapX, m_MapY - 1)))
			return 1;
		break;
	case MOVE_RIGHT:
		if (m_World.isWall(m_World.coord(m_MapX + 1, m_MapY)))
			return 1;
		break;
	case MOVE_DOWN:
		if (m_World.isWall(m_World.coord(m_MapX, m_MapY + 1)))
			return 1;
		break;
	case MOVE_LEFT:
		if (m_World.isWall(m_World.coord(m_MapX - 1, m_MapY)))
			return 1;
		break;
	default:
		break;
	}
	return 0;
}