#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int maxCapacity, int topSpeed,
	std::string manufacturer, int year)
	: m_maxCapacity(maxCapacity)
	, m_topSpeed(topSpeed)
	, m_manufacturer(manufacturer)
	, m_year(year)
	, m_currentSpeed(0)
	, m_isMoving(false)
{

}

Vehicle::~Vehicle()
{
}

void Vehicle::Drive()
{
	if (!m_isMoving)
	{
		std::cout << "Vroom vroom!" << std::endl;
		m_isMoving = true;
		m_currentSpeed = m_topSpeed;
		std::cout << "Vehicle is now moving..." << std::endl;
	}
}

void Vehicle::Brake()
{
	if (m_isMoving)
	{
		std::cout << "Squeakkkkk!" << std::endl;
		m_isMoving = false;
		m_currentSpeed = 0;
		std::cout << "Vehicle has stopped..." << std::endl;
	}
}