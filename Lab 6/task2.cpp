#include<iostream>
using namespace std;

class Node {
	public:
		string data;
		Node* link;
		Node(string val) {
			data = val;
			link = NULL;
		}
};

Node* top = NULL;

void push(string val) {
	Node* temp = new Node(val);
	if (!temp) {
		cout << "\nHeap is OverFlowing";
		return;
	}
	temp->link = top;
	top = temp;
	cout << "Visited: " << val << endl;
}

void pop() {
	if (top == NULL) {
		cout << "\nStack is UnderFlowing";
		return;
	}
	cout << "Going back from " << top->data << endl;
	Node* temp = top;
	top = top->link;
	delete temp;
}

void peek() {
	if (top == NULL) {
		cout << "No pages visited yet";
	}
	else {
		cout << "current page : " << top->data << endl;
	}	
}

void display() {
	if(top == NULL) {
		cout << "No pages visited yet";
		return;
	}
	Node* temp = top;
	cout << "\nBrowser History (LAst visited first): ";
	while(temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->link;
	}
	cout << "Nulll";
}

int main() {
	int choice;
	string site;

	cout << "========================== Browser History Navigation Using Stack ==================================\n";

	while (true) {
		cout << "\n1. Visit new page\n2. Go back\n3. Show current page\n4. Show all history\n5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter website name: ";
			cin >> site;
			push(site);
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			cout << "Exiting...\n";
			return 0;
		default:
			cout << "Invalid choice! Try again.\n";
		}
	}


	cout << "========================== Browser History Navigation Using Stack end==================================\n";
}