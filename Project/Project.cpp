#include <iostream>
#include "Game.h"

int main()
{
	Game myGame;

	if (myGame.load())
	{
		while (!myGame.isGameOver())
		{
			myGame.run();
		}

		std::cout << "YOU WON!!!!!!!" << std::endl;
		//playWinSound();
	}
	else
	{
		std::cout << "Game did not load. Terminating now!" << std::endl;
	}
}