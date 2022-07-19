#include <iostream>

using namespace std;

//template <typename T>
//void getUserNum();

//template <typename T>
int cubeNum(int num);

template <typename T>
void displayMessage(string message, T num);

int main() 
{
	// Prompt user for number
	cout << "Please enter a number: ";

	// Cube the number
	int num;
	cin >> num;

	// Display to user
	displayMessage("Number cubed: ", cubeNum(num));
}

//template <typename T>
//void getUserNum()
//{
//	T num;
//	cin >> num;
//
//	cubeNum(num);
//}

//template <typename T>
int cubeNum(int num)
{
	return num * num * num;
}

template <typename T>
void displayMessage(string message, T num)
{
	cout << message << num;
}