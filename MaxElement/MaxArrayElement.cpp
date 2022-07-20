#include <iostream>

using namespace std;

void populateArray(int arr[], int size);
int findMaxElement(int arr[], int size);

int main()
{
	constexpr int size = 5;

	int arr[size];

	populateArray(arr, size);
	int maxNum = findMaxElement(arr, size);

	cout << "The largest number is " << maxNum << "!" << endl;
}

void populateArray(int arr[], int size)
{
	cout << "Welcome! Please enter " << size << " numbers to populate the array with: ";

	for (int i = 0; i < size; i++)
	{
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