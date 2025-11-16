#pragma once


#include "Player.hpp"

class NPC final : public Player {
public:
	NPC(int posx, int posy, Map& world);
	void stepSolver(double deltaTime, double speed);
	void rotateOrientation(int rotMove);
	void resetClock();
private:
	int m_Forward;
	int m_Right;
	int m_Left;
	int m_Backwards;
	double m_Clock;
};