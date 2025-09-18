#include<iostream>
using namespace std;

int searchLinear(int *arr, int target, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
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

	int result = searchLinear(arr, target, size);
	if (result == -1)
		cout << "Element not found";
	else
		cout << "Element found at " << result << " index" << endl;

}