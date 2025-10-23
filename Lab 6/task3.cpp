#include<iostream>
using namespace std;
int const MAX_SIZE = 10;
int front = 0, rear = -1;
int arr[MAX_SIZE];

bool is_full() {
	return rear == MAX_SIZE - 1;
}

bool isEmpty() {
	return rear == -1;
}

void enquenue(int val)
{
	if (is_full()) {
		cout << "No more space...." << endl;
		return;
	}

	arr[++rear] = val;
}

int dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty, cannot Dequeue" << endl;
		return -1;
	}
	return arr[front++];
}

int main() {
	enquenue(100);
	enquenue(100);
	enquenue(100);

	cout << dequeue() << endl;
	cout << dequeue() << endl;

	enquenue(100);
	enquenue(100);

	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;


}