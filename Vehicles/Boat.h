#pragma once
#include "Vehicle.h"
#include <iostream>

class Boat : public Vehicle
{
	std::string m_boatType;
	std::string m_propulsion;
	bool m_canFloat;

public:
	Boat(int maxCapacity, int topSpeed,
		std::string manufacturer, int year,
		std::string boatType, std::string propulsion,
		bool canFloat);
	~Boat();

	void Drive();
	void Brake();
};