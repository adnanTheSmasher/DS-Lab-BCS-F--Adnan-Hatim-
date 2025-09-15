#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = nullptr;
	}
};

class Singly {
public:
	Node* head;

	Singly()
	{
		head = nullptr;
	}

	void insertAtEnd(int val) {
		Node* n = new Node(val);
		if (head == NULL)
		{
			head = n;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		n->next = NULL;
		cout << "INSERTED " << val << endl;
	}

	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
	}
};


Node* mergeList(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;

	Node* head = nullptr;
	if (a->data <= b->data) {
		head = a;
		a = a->next;
	}
	else {
		head = b;
		b = b->next;
	}

	Node* tail = head;

	while (a && b) {
		if (a->data <= b->data) {
			tail->next = a;
			a = a->next;
		}
		else {
			tail->next = b;
			b = b->next;
		}
		tail = tail->next;
	}

	if (a) tail->next = a;
	if (b) tail->next = b;

	return head;
}

int main() {
	Singly list1, list2;

	list1.insertAtEnd(1);
	list1.insertAtEnd(3);
	list1.insertAtEnd(5);

	list2.insertAtEnd(2);
	list2.insertAtEnd(4);
	list2.insertAtEnd(6);

	Node* merging = mergeList(list1.head, list2.head);

	cout << "Merged List: ";
	Node* temp = merging;
	while (temp) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;

}