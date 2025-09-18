#include<iostream>
using namespace std;

void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


int searchBinary(int* arr, int size, int target) {
	int left = 0;
	int right = size-1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
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

	cout << "Enter target element: ";
	cin >> target;

	insertionSort(arr, size);
	int index = searchBinary(arr, size, target);
	if (index == -1) {
		cout << "Eleemnt not found" << endl;
	}
	else {
	display(arr, size);
	cout << "elemetn found at index: " << index<<endl;
	}

}



