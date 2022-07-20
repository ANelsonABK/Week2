#include <iostream>

using namespace std;

float cubeNum(float num);

template <typename T>
void displayMessage(string message, T num);

int main()
{
	// Prompt user for number
	cout << "Please enter a number: ";

	// Cube the number
	float num = 0;
	cin >> num;

	// Display to user
	displayMessage("Number cubed: ", cubeNum(num));
}

float cubeNum(float num)
{
	return num * num * num;
}

template <typename T>
void displayMessage(string message, T num)
{
	cout << message << num;
}