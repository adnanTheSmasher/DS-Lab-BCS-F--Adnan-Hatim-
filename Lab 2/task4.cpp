/*
Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.
*/


#include <iostream>
using namespace std;

int sizeChecker(int oldSize, int newSize)
{
	while (true) {
		if (newSize <= oldSize)
		{
			cout << "New size must be greater than previous size (" << oldSize << "). Enter again: ";
        	cin >> newSize;
		}
		else {
			return newSize;
		}
	}
}

int* resizeArray(int* oldArr, int oldSize, int newSize)
{
	int* newArr = new int[newSize];
	for (int i = 0; i < oldSize; i++)
	{
		newArr[i] = oldArr[i];
	}

	delete[] oldArr;
	return newArr;
}

int getTotal(int* arr, int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += arr[i];
	}
	return total;
}


int main()
{
	int size, newSize;
	char choice;

	cout << "Enter number of months: ";
	cin >> size;

	int* expenses = new int [size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter expense for month: " << i + 1 << "\n";
		cin >> expenses[i];
	}

	cout << "Want to add more months (N/Y): \n" ;
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		cout << "Enter new number of months: \n";
		cin >> newSize;

		int finalSize = sizeChecker(size, newSize);
		int* newExpenses = resizeArray(expenses, size,finalSize);

		for (int i = size; i < finalSize; i++)
		{
			cout << "Enter expense for month: " << i + 1 <<"\n";
			cin >> newExpenses[i];
		}

		cout << "The total Expense: " << getTotal(newExpenses, finalSize) << "\n";
		cout << "The Average Expense: " << getTotal(newExpenses, finalSize) / size;
	}
    else {
        cout << "\nThe total Expense: " << getTotal(expenses, size) << "\n";
        cout << "The Average Expense: " << getTotal(expenses, size) / size << "\n";
    }

}