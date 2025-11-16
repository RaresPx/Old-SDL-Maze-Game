#include "NPC.hpp"

NPC::NPC(int posx, int posy, Map& world) : Player(posx, posy, world) {
	m_Color = { 255,125,125,255 };
	m_Forward = MOVE_UP;
	m_Backwards = MOVE_DOWN;
	m_Left = MOVE_LEFT;
	m_Right = MOVE_RIGHT;
	m_Clock = 0.0;
}

void NPC::stepSolver(double deltaTime,double speed) {

	if (m_MapX >= m_World.size() ||
		m_MapY >= m_World.size() ||
		m_MapX < 0 ||
		m_MapY < 0)
		return;

	m_Clock += deltaTime;

	if (m_Clock * speed < 1.)
		return;
	m_Clock = 0.0;

	if (!checkCollision(m_Left)) {
		updatePosition(m_Left);
		rotateOrientation(MOVE_LEFT);
	}
	else if (!checkCollision(m_Forward)) {
		updatePosition(m_Forward);
		rotateOrientation(MOVE_UP);
	}
	else if (!checkCollision(m_Right)) {
		updatePosition(m_Right);
		rotateOrientation(MOVE_RIGHT);
	}
	else if (!checkCollision(m_Backwards)) {
		updatePosition(m_Backwards);
		rotateOrientation(MOVE_DOWN);
	}
} 

void NPC::rotateOrientation(int rotMove) {
	int f = m_Forward;
	int r = m_Right;
	int b = m_Backwards;
	int l = m_Left;
	switch (rotMove) {
	case MOVE_UP:
		break;
	case MOVE_RIGHT:
		m_Forward = r;
		m_Right = b;
		m_Left = f;
		m_Backwards = l;
		break;
	case MOVE_DOWN:
		std::swap(m_Forward, m_Backwards);
		std::swap(m_Left, m_Right);
		break;
	case MOVE_LEFT:
		m_Forward = l;
		m_Left = b;
		m_Right = f;
		m_Backwards = r;
		break;
	default:
		break;
	}
}

void NPC::resetClock() {
	m_Clock = 0;
}