#include "Airplane.h"
#include <iostream>
#include <chrono>
#include <thread>

Airplane::Airplane(int maxCapacity, int topSpeed,
	std::string manufacturer, int year,
	float maxWeight, std::string engine,
	std::string propulsion, int crewSize, int fuelCapacity)
	: Vehicle(maxCapacity, topSpeed, manufacturer, year)
	, m_maxWeight(maxWeight)
	, m_engine(engine)
	, m_propulsion(propulsion)
	, m_crewSize(crewSize)
	, m_fuelCapacity(fuelCapacity)
{

}

Airplane::~Airplane()
{
}

void Airplane::Drive()
{
	if (!canTakeOff())
	{
		std::cout << "Plane is too heavy and can't take off!" 
			<< std::endl;
	}
	else
	{
		std::cout << "Prepare for takeoff..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));

		std::cout << "V1..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));

		std::cout << "Rotate..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));

		std::cout << "V2..." << std::endl;
	}
}

void Airplane::Brake()
{
	std::cout << "Prepare for landing..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	std::cout << "Touchdown..." << std::endl;
	std::cout << "Reverse thrust..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	std::cout << "Thank you for flying Air Level Up!" << std::endl;
}