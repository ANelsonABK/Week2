#include <iostream>

using namespace std;

int main()
{
	// Prompt user for three numbers
	cout << "Please enter three numbers: ";

	// Get three numbers from user
	float num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	// Add the numbers
	float totalSum = num1 + num2 + num3;

	// Average the numbers
	float avg = totalSum / 3.0f;

	// Display the sum and average
	cout << "Sum = " << totalSum << endl;
	cout << "Average = " << avg << endl;
}