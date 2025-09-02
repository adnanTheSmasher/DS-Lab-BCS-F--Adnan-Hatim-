#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr; 

public:
    SafePointer() {
        ptr = new int;
    }

    ~SafePointer() {
        delete ptr;
        ptr = nullptr;
    }

    void setValue(int value) {
        if (ptr) {
            *ptr = value;
        }
    }

    int getValue() const {
        if (ptr) 
            return *ptr;
        
    }
};

int main() {
    const int SIZE = 5;
    SafePointer marks[SIZE]; 

    for (int i = 0; i < SIZE; i++) {
        int m;
        cout << "Enter marks for student " << (i + 1) << ": ";
        cin >> m;
        marks[i].setValue(m);
    }

    cout << "\nStudent Marks:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Student " << (i + 1) << ": " << marks[i].getValue() << endl;
    }

    return 0;
}
