#include <iostream>
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


class doubleNode {
public:
    int data;
    doubleNode* next;
    doubleNode* prev;
    doubleNode(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};


class circularNode {
public:
    int data;
    circularNode* next;
    circularNode(int val) {
        data = val;
        next = nullptr;
    }
};


class Singly {
public:
    Node* head;
    Singly() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


doubleNode* convertToDoubly(Node* head) {
    if (!head) return nullptr;

    doubleNode* dHead = new doubleNode(head->data);
    doubleNode* dCurr = dHead;
    Node* sCurr = head->next;

    while (sCurr) {
        doubleNode* newNode = new doubleNode(sCurr->data);
        dCurr->next = newNode;
        newNode->prev = dCurr;
        dCurr = newNode;
        sCurr = sCurr->next;
    }
    return dHead;
}

circularNode* convertToCircular(Node* head) {
    if (!head) return nullptr;

    circularNode* cHead = new circularNode(head->data);
    circularNode* cCurr = cHead;
    Node* sCurr = head->next;

    while (sCurr) {
        circularNode* newNode = new circularNode(sCurr->data);
        cCurr->next = newNode;
        cCurr = newNode;
        sCurr = sCurr->next;
    }
    cCurr->next = cHead;  
    return cHead;
}


void displayDoubly(doubleNode* head) {
    doubleNode* temp = head;
    cout << "Doubly: ";
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void displayCircular(circularNode* head, int n) {
    cout << "Circular: ";
    circularNode* temp = head;
    for (int i = 0; i < n; i++) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "(back to head)\n";
}


int main() {
    Singly list;
    for (int i = 1; i <= 5; i++) list.insertAtEnd(i);

    cout << "Original Singly: ";
    list.display();

    
    doubleNode* dHead = convertToDoubly(list.head);
    displayDoubly(dHead);

    circularNode* cHead = convertToCircular(list.head);
    displayCircular(cHead, 10); 

    return 0;
}
