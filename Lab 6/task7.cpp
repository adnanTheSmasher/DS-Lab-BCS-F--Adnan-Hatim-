#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Process {
	int id;
	int priority;
};

void displayProcess(Process P) {
	cout << "Process ID: " << P.id << ", Priority: " << P.priority << endl;
}

int main() {
	queue<Process> processQueue;
	stack<Process> processStack;

	int n;
	cout << "Enter Number of Processes: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		Process P;
		cout << "Enter Process ID and Priority: ";
		cin >> P.id >> P.priority;
		processQueue.push(P);
	}

	cout << "\n Processes Arrived in this Order: \n";
	queue<Process> tempQueue = processQueue;
	while(!tempQueue.empty()) {
		displayProcess(tempQueue.front());
		cout << " -> ";
		tempQueue.pop();
	}

	cout << "END\n";

	cout << "\n scheduling \n";
	while (!processQueue.empty()) {
		Process c = processQueue.front();
		processQueue.pop();

		cout << "Pushing Process ";
		displayProcess(c);
		cout << "into execution stack \n";
		processStack.push(c);
	}

	cout << "\n ----------------Execution (stack order) -------------------\n";
	while (!processStack.empty()) {
		Process current = processStack.top();
		processStack.pop();

		cout << "Executing ";
		displayProcess(current);
		cout << endl;
	}

	cout << "\n All process executed successfully......\n";


}