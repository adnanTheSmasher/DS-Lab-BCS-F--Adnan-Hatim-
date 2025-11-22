#include <iostream>
#include<algorithm>
using namespace std;

class MaxHeap {
    int arr[100];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    // -------------------------
    // MAX HEAPIFY UP
    // -------------------------
    void heapifyUp(int index) {
        while (index > 0 && arr[parent(index)] > arr[index]) {
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    }

    // -------------------------
    // MAX HEAPIFY DOWN
    // -------------------------
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {
        size = 0;
    }


    void insert(int value) {
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    int* getarr() {
        return arr;
    }

    bool isCompleteBinaryTree(int arr[], int size) {

        for (int i = 0; i < size; i++) {

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (right < size && left >= size)
                return false;
        }
        return true;
    }


    void update(int index, int newValue) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            return;
        }

        int oldValue = arr[index];
        arr[index] = newValue;


        if (newValue > oldValue) {
            heapifyUp(index);
        }
        else {
            heapifyDown(index);
        }
    }

    void display() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    int size, value, k;

    cout << "Enter the size of the heap: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        h.insert(value);
    }

    cout << "Original Min Heap:\n";
    h.display();
	
    int* arr = h.getarr();
	reverse(arr, arr + size);

    cout << " Max Heap : \n";
    h.display();


    return 0;
}
