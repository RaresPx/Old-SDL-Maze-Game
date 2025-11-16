#include "Entity.hpp"

Entity::Entity() : m_X(0), m_Y(0) {
	m_Color = { 0,0,0,0 };
}

int Entity::getX() {
	return m_X;
}

int Entity::getY() {
	return m_Y;
}