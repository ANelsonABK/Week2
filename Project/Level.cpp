#include <iostream>
#include <fstream>
#include "Level.h"

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level()
	: m_plevelData(nullptr)
	, m_height(0)
	, m_width(0)
{

}

Level::~Level()
{
	if (m_plevelData != nullptr)
	{
		delete[] m_plevelData;
		m_plevelData = nullptr;
	}
}

bool Level::load(std::string levelName, int* playerX, int* playerY)
{
	levelName.insert(0, "../");
	std::ifstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		std::cout << "Opening file failed!" << std::endl;
		return false;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n');
		m_width = atoi(temp);

		levelFile.getline(temp, tempSize, '\n');
		m_height = atoi(temp);

		m_plevelData = new char[m_width * m_height];
		levelFile.read(m_plevelData, (long long)m_width * (long long)m_height);
		
		bool anyWarnings = convert(playerX, playerY);
		if (anyWarnings)
		{
			std::cout << "There were some warnings in the level data, see above." << std::endl;
			system("pause");
		}

		return true;
	}
}

void Level::draw(int x, int y)
{
	int index = getIndexFromCoordinates(x, y);
	std::cout << m_plevelData[index];
}

bool Level::isSpace(int x, int y)
{
	return m_plevelData[getIndexFromCoordinates(x, y)] == ' ';
}

bool Level::isDoor(int x, int y)
{
	return m_plevelData[getIndexFromCoordinates(x, y)] == DOR;
}

bool Level::isKey(int x, int y)
{
	return m_plevelData[getIndexFromCoordinates(x, y)] == KEY;
}

bool Level::isGoal(int x, int y)
{
	return m_plevelData[getIndexFromCoordinates(x, y)] == GOL;
}

void Level::pickUpKey(int x, int y)
{
	m_plevelData[getIndexFromCoordinates(x, y)] = ' ';
}

void Level::openDoor(int x, int y)
{
	m_plevelData[getIndexFromCoordinates(x, y)] = ' ';
}

bool Level::convert(int* playerX, int* playerY)
{
	bool anyWarnings = false;

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			int index = getIndexFromCoordinates(x, y);

			switch (m_plevelData[index])
			{
			case '+':
			case '-':
			case '|':
				m_plevelData[index] = WAL;
				break;
			case '*':
				m_plevelData[index] = KEY;
				break;
			case 'D':
				m_plevelData[index] = DOR;
				break;
			case 'X':
				m_plevelData[index] = GOL;
				break;
			case '@':
				m_plevelData[index] = ' ';

				if (playerX != nullptr && playerY != nullptr)
				{
					*playerX = x;
					*playerY = y;
				}
				break;
			case ' ':
				break;
			default:
				std::cout << "Invalid character in level file:" << m_plevelData[index];
				anyWarnings = true;
				break;
			}
		}
	}

	return anyWarnings;
}
int Level::getIndexFromCoordinates(int x, int y)
{
	return x + y * m_width;
}