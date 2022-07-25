#pragma once
#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle
{
	std::string m_engine;
	std::string m_driveTrain;
	std::string m_bodyStyle;
	std::string m_make;
	std::string m_model;
	int m_fuelCapacity;

public:
	Car(int maxCapacity, int topSpeed,
		std::string manufacturer, int year, 
		std::string m_engine, std::string m_driveTrain,
		std::string m_bodyStyle, std::string m_make,
		std::string m_model, int m_fuelCapacity);
	~Car();

	void Drive();
	void Brake();
};