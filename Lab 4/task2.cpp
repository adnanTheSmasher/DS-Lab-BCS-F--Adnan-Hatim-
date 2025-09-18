#include<iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
	bubbleSort(arr, size);
	display(arr, size);
	
}

