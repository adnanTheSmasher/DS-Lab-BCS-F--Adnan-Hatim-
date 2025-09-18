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

int interpolationsearch(int *arr, int size, int target) {
	int low = 0;
	int high = size - 1;

	while (low <= high && target >= arr[low] && target <= arr[high]) {
		if (low == high) return low;

		int index = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

		if (arr[index] == target) 
			return index;

		if (arr[index] < target)
			low = index + 1;
		else 
			high = index - 1;
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

	cout << "Enter element to target: ";
	cin >> target;

	insertionSort(arr, size);
	int index = interpolationsearch(arr, size, target);
	if (index == -1) {
		cout << "element not found...";
	}
	else {
		display(arr, size);
		cout << "element found at index: " << index<<endl;
	}

}