#include "Car.h"
#include <iostream>

Car::Car(int maxCapacity, int topSpeed,
	std::string manufacturer, int year,
	std::string engine, std::string driveTrain,
	std::string bodyStyle, std::string make,
	std::string model, int fuelCapacity)
	: Vehicle(maxCapacity, topSpeed, manufacturer, year)
	, m_engine(engine)
	, m_driveTrain(driveTrain)
	, m_bodyStyle(bodyStyle)
	, m_make(make)
	, m_model(model)
	, m_fuelCapacity(fuelCapacity)
{

}

Car::~Car()
{
}

/** 
Start movig car if it's not already moving.
*/
void Car::Drive()
{
	if (!m_isMoving)
	{
		std::cout << "Vroom vroom!" << std::endl;
		m_currentSpeed = getTopSpeed() / 2;
		m_isMoving = true;
		std::cout << getYear() << m_make << m_model
			<< " is going " << m_currentSpeed << " mph." << std::endl;
	}
	else {
		std::cout << getYear() << m_make << m_model
			<< " is already moving!" << std::endl;
	}
}

void Car::Brake()
{
	if (m_isMoving)
	{
		std::cout << "Squeakkkkk!" << std::endl;
		m_currentSpeed = 0;
		m_isMoving = false;
		std::cout << getYear() << m_make << m_model
			<< " is going " << m_currentSpeed << " mp/h." << std::endl;
	}
}