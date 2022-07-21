#pragma once
#include <string>

class Level
{
	char* m_plevelData;
	int m_height;
	int m_width;

public:
	Level();
	~Level();

	bool load(std::string levelName, int* playerX, int* playerY);
	void draw(int x, int y);

	bool isSpace(int x, int y);
	bool isDoor(int x, int y);
	bool isKey(int x, int y);
	bool isGoal(int x, int y);

	void pickUpKey(int x, int y);
	void openDoor(int x, int y);

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }

private:
	bool convert(int* playerX, int* playerY);
	int getIndexFromCoordinates(int x, int y);
};