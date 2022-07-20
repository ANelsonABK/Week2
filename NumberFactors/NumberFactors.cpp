#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Get a positive number from user
	int64_t num = 1;

	do {
		cout << "Enter a number between 1 and 2,147,483,647:" << endl;
		cin >> num;
	} while (num < 1 || num > 2147483647);

	// Find and print all factors of given number
	int range = (int)sqrt(num);

	cout << "Finding all factors of " << num << "..." << endl;

	for (int factor = 1; factor <= range; factor++)
	{
		if (num % factor == 0)
		{
			cout << factor << " , " << (num / factor) << endl;
		}
	}

	cout << "Found all the factors of " << num << "!" << endl;
}