#include<iostream>
using namespace std;

void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void selectionSort(int *arr, int size) {
	int temp = 0;
	for (int i = 0; i < size - 1; i++) {
		int min_index = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
	}
}

int main() {
	int size;
	int target;

	cout << "Enter size of Array: ";
	cin >> size;

	int* arr = new int[size];


	for (int i = 0; i < size; i++) {
		cout << "Enter Element " << i << ": ";
		cin >> arr[i];
	}

	display(arr, size);
	selectionSort(arr, size);
	display(arr, size);

}