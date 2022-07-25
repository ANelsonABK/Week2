#include <iostream>

using namespace std;

void populateArray(int arr[], int size);
int findMaxElement(int arr[], int size);

int main()
{
	int size;

	cout << "Welcome! Please enter a size for the array: ";
	cin >> size;

	int* arrayPtr = new int[size];
	populateArray(arrayPtr, size);

	int maxNum = findMaxElement(arrayPtr, size);
	cout << "The largest number is " << maxNum << "!" << endl;
}

void populateArray(int arr[], int size)
{
	cout << "Please enter " << size << " numbers to populate the array with: ";

	for (int i = 0; i < size; i++)
	{
		// TODO: check for input validation
		cin >> arr[i];
	}
}

int findMaxElement(int arr[], int size)
{
	int maxNum = arr[0];

	for (int i = 0; i < size; i++)
	{
		maxNum = (maxNum < arr[i]) ? arr[i] : maxNum;
	}

	return maxNum;
}