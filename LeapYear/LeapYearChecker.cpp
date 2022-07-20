#include <iostream>

using namespace std;

bool checkLeapYear(int year);

int main()
{
	cout << "Please enter a year: ";

	int year = 1582;
	cin >> year;

	// Check if year is at least 1582 
	// (when the current leap year rules started)
	if (year < 1582)
	{
		cout << "Please enter a year between 1582 and 2022: " << endl;
		cin >> year;
	}

	bool isLeapYear = checkLeapYear(year);

	if (isLeapYear)
	{
		cout << year << " is a leap year!" << endl;
	}
	else
	{
		cout << year << " is not a leap year." << endl;
	}
}

/** 
 
 Checks if a year is a leap year by checking if it is divisible by
 4. If it is, it checks it checks if it's divisible by 100 and 400,
 or not.

*/
bool checkLeapYear(int year)
{
	if(year % 4 == 0) 
	{
		// Check if year is divisible by 100 and 400
		if (year % 100 == 0)
		{
			return (year % 400 == 0);
		}
		else
		{
			return true;
		}
	}

	// Year is not a leap year
	return false;
}