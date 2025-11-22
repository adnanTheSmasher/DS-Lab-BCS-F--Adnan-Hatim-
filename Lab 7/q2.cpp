#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int getMax(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > maxVal) maxVal = a[i];
    return maxVal;
}

void countingSort(int a[], int n, int place) {
    vector<int> output(n);  
    int count[10] = { 0 };

    
    for (int i = 0; i < n; ++i)
        count[(a[i] / place) % 10]++;

    
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    
    for (int i = n - 1; i >= 0; --i) {
        int digit = (a[i] / place) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    
    for (int i = 0; i < n; ++i)
        a[i] = output[i];
}

void radixsort(int a[], int n) {
    int maxVal = getMax(a, n);

    
    for (int place = 1; maxVal / place > 0; place *= 10)
        countingSort(a, n, place);
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int a[] = { 181, 289, 390, 121, 145, 736, 514, 888, 122 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting array elements are - \n";
    printArray(a, n);

    
    radixsort(a, n);
    cout << "After applying Radix sort (Ascending Order), the array elements are - \n";
    printArray(a, n);

    
    reverse(a, a + n);
    cout << "After applying Radix sort (Descending Order), the array elements are - \n";
    printArray(a, n);

    return 0;
}
