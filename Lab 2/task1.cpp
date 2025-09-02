/*Task #1:
Implement a program that dynamically allocates a 1D array of integers.

=> The courses should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.*/

#include <iostream>
using namespace std;

int main() {
    int n, index, value;
    cout << "Enter courses of 1D array: ";
    cin >> n;

    
    int* arr = new int[n]{0}; 

	while (true){
	    cout << "Enter index to update (enter 0 to print array): ";
	    cin >> index;
	    if (index == 0){
	    	break;
		}
	    cout << "Enter Value to update at index: ";
	    cin >> value;
	    
	    arr[index-1] = value;	
	}

    cout << "Values in array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
