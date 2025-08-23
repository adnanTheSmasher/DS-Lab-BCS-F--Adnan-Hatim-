#include <iostream>
using namespace std;

class Box {
private:
    int* data;

public:

    Box(int value = 0) {          
        data = new int(value); 
    }

    // rule #2
    Box(const Box& other) {
        data = new int(*other.data);
    }

    // rule #3
    Box& operator=(const Box& other) {
        if (this != &other) { 
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
    // rule #1
    ~Box() {
        delete data;
    }

    void setValue(int value) {
        *data = value;
    }

    int getValue() const {
        return *data;
    }
};

class ShalloBox {
    public:
        int* data;
        ShalloBox(int value = 0) { data = new int(value); }
        ~ShalloBox() { delete data; }
    };

int main() {
    cout << "=== Rule of Three Test Cases ===\n";
    Box b1(10);
    Box b2 = b1; 
    Box b3;           
    b3 = b1;         

    cout << "b1 value: " << b1.getValue() << endl;
    cout << "b2 value: " << b2.getValue() << endl;
    cout << "b3 value: " << b3.getValue() << endl;

    b1.setValue(99);
    cout << "\nAfter modifying b1:\n";
    cout << "b1 value: " << b1.getValue() << endl;
    cout << "b2 value: " << b2.getValue() << endl;
    cout << "b3 value: " << b3.getValue() << endl;


    cout << "\n=== Shallow Copy Example ===\n";
     ShalloBox s1(42);
    ShalloBox s2 = s1; 

    cout << "s1 value: " << *s1.data << endl;
    cout << "s2 value: " << *s2.data << endl;

    *s1.data = 100;
    cout << "\nAfter modifying s1:\n";
    cout << "s1 value: " << *s1.data << endl;
    cout << "s2 value: " << *s2.data << endl;
    return 0;
}
