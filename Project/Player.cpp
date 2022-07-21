#include "Player.h"
#include <iostream>

constexpr char kPlayerSymbol = '@';

Player::Player()
	:m_hasKey(false)
{

}

Player::~Player()
{

}

void Player::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void Player::pickupKey()
{
	m_hasKey = true;
}

void Player::useKey()
{
	m_hasKey = false;
}

void Player::draw()
{
	std::cout << kPlayerSymbol;
}
