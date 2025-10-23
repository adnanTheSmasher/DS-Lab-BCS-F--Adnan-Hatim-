#include<iostream>
using namespace std;
int const MAX_SIZE = 10;
int front = -1, rear = -1;
int arr[MAX_SIZE];

bool is_full() {
	return (front ==(rear + 1) % MAX_SIZE);
}

bool isEmpty() {
	return front == -1;
}

void enquenue(int val)
{
	if (is_full()) {
		cout << "No more space...." << endl;
		return;
	}
	else if (isEmpty()) {
		rear = front = 0;
	}
	else
		rear = (rear + 1) % MAX_SIZE;

	arr[rear] = val;
	cout << val << " enqueued to queue" << endl;

}

int dequeue() {
	int x = 0;
	if (isEmpty()) {
		cout << "Queue is empty, cannot Dequeue" << endl;
		return -1;
	}
	x = arr[front];

	if(front == rear){
		front = -1;
		rear = -1;
	}
	else {
		x = arr[front];
		front = (front + 1) % MAX_SIZE;
	}
	return x;
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