#pragma once
#include <iostream>

class Vehicle
{
	int m_maxCapacity;
	int m_topSpeed;
	std::string m_manufacturer;
	int m_year;

public:
	int m_currentSpeed;
	bool m_isMoving;

	Vehicle(int maxCapacity, int topSpeed,
		    std::string manufacturer, int year);
	~Vehicle();

	void Drive();
	void Brake();

	int getTopSpeed() { return m_topSpeed; }
	int getMaxCapacity() { return m_maxCapacity; }
	int getYear() { return m_year; }
};