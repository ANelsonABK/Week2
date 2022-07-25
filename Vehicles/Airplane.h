#pragma once
#include "Vehicle.h"
#include <iostream>

class Airplane : public Vehicle
{
	float m_maxWeight;
	std::string m_engine;
	std::string m_propulsion;
	int m_crewSize;
	int m_fuelCapacity;
	float m_currentWeight;

public:
	Airplane(int maxCapacity, int topSpeed,
		std::string manufacturer, int year,
		float maxWeight, std::string engine,
		std::string propulsion, int crewSize, int fuelCapacity);
	~Airplane();

	void Drive();
	bool canTakeOff() { return m_currentWeight < m_maxWeight; }
	void Brake();
};