#include "Boat.h"
#include <iostream>

Boat::Boat(int maxCapacity, int topSpeed,
	std::string manufacturer, int year,
	std::string boatType, std::string propulsion,
	bool canFloat)
	: Vehicle(maxCapacity, topSpeed, manufacturer, year)
	, m_boatType(boatType)
	, m_propulsion(propulsion)
	, m_canFloat(canFloat)
{

}

Boat::~Boat()
{
}

void Boat::Drive()
{
	if (!m_canFloat)
	{
		std::cout << "Boat is too heavy to drive!" << std::endl;
	}
	else
	{
		if (!m_isMoving)
		{
			std::cout << "Honk honk!" << std::endl;
			m_currentSpeed = getTopSpeed() / 2;
			m_isMoving = true;

			std::cout << getYear() << m_boatType << " is going "
				<< m_currentSpeed << " mph." << std::endl;
		}
	}
}

void Boat::Brake()
{
	if (m_isMoving)
	{
		std::cout << "*Idle Sound*" << std::endl;
		m_currentSpeed = 0;
		m_isMoving = false;
		std::cout << getYear() << m_boatType << " is going "
			<< m_currentSpeed << " mph." << std::endl;
	}
}