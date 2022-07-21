#include "Game.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

constexpr int kOpenDoorColor = 10;
constexpr int kClosedDoorColor = 12;
constexpr int kRegularColor = 7;

Game::Game()
	: m_isGameOver(false)
{

}

Game::~Game()
{

}

bool Game::load()
{
	return m_level.load("Level8.txt",
		m_player.getXPositionPointer(),
		m_player.getXPositionPointer());
}

void Game::run()
{
	draw();

	m_isGameOver = update();

	if (m_isGameOver)
	{
		draw();
	}
}

bool Game::isGameOver()
{
	return m_isGameOver;
}

bool Game::update()
{
	char input = (char)_getch();
	int newPlayerX = m_player.getXPosition();
	int newPlayerY = m_player.getYPosition();

	switch (input)
	{
	    case 'w':
		case 'W':
		{
			newPlayerY--;
			break;
		}
		case 's':
		case 'S':
		{
			newPlayerY++;
			break;
		}
		case 'a':
		case 'A':
		{
			newPlayerX--;
			break;
		}
		case 'd':
		case 'D':
		{
			newPlayerX++;
			break;
		}
		default:
			break;
	}

	if (m_level.isSpace(newPlayerX, newPlayerY))
	{
		m_player.setPosition(newPlayerX, newPlayerY);
	}
	else if (m_level.isKey(newPlayerX, newPlayerY))
	{
		m_level.pickUpKey(newPlayerX, newPlayerY);
		m_player.pickupKey();
		m_player.setPosition(newPlayerX, newPlayerY);
		//playKeyPickupSound();
	}
	else if (m_level.isDoor(newPlayerX, newPlayerY) && 
		     m_player.hasKey())
	{
		m_level.openDoor(newPlayerX, newPlayerY);
		m_player.useKey();
		m_player.setPosition(newPlayerX, newPlayerY);
		//playDoorOpenSound();
	}
	else if (m_level.isDoor(newPlayerX, newPlayerY) &&
		!m_player.hasKey())
	{
		//playDoorClosedSound();
	}
	else if (m_level.isGoal(newPlayerX, newPlayerY))
	{
		m_player.setPosition(newPlayerX, newPlayerY);
		return true;
	}

	return false;
}

void Game::draw()
{
	for (int y = 0; y < m_level.getHeight(); ++y)
	{
		for (int x = 0; x < m_level.getWidth(); ++x)
		{
			if (m_player.getXPosition() == x && 
				m_player.getYPosition() == y)
			{
				m_player.draw();
			}
			else
			{
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

				if (m_level.isDoor(x, y))
				{
					if (m_player.hasKey())
					{
						SetConsoleTextAttribute(console, kOpenDoorColor);
					}
					else
					{
						SetConsoleTextAttribute(console, kClosedDoorColor);
					}
				}
				else
				{
					SetConsoleTextAttribute(console, kRegularColor);
				}

				m_level.draw(x, y);
			}
		}

		std::cout << std::endl;
	}
}