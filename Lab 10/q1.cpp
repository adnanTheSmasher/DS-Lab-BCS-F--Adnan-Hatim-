#include <iostream>
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
        while (index > 0 && arr[parent(index)] < arr[index]) {
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

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Original Max Heap:\n";
    h.display();

    cout << "\nUpdating index 2 to 10:\n";
    h.update(2, 10);

    h.display();

    return 0;
}
