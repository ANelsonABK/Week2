#pragma once
#include "Player.h"
#include "Level.h"

class Game
{
	Player m_player;
	Level m_level;
	bool m_isGameOver;

public:
	Game();
	~Game();

	bool load();
	void run();

	bool isGameOver();

private:
	bool update();
	void draw();
};