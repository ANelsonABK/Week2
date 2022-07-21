#pragma once
#include "Point.h"

class Player
{
	Point m_position;
	bool m_hasKey;

public:
	Player();
	~Player();

	int getXPosition() { return m_position.x; }
	int getYPosition() { return m_position.y; }

	int* getXPositionPointer() { return &(m_position.x); }
	int* getYPositionPointer() { return &(m_position.y); }

	void setPosition(int x, int y);

	bool hasKey() { return m_hasKey; }
	void pickupKey();
	void useKey();

	void draw();
};