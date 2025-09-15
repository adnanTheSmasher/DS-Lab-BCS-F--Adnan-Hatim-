#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class Singly {
public:
    Node* head;

    Singly() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        cout << "INSERTED " << val << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);

                curr->next = childHead;
                curr->child = nullptr;

                Node* temp = childHead;
                while (temp->next) temp = temp->next;

                temp->next = nextNode;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    Singly list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    list.head->next->child = new Node(4);
    list.head->next->child->next = new Node(5);

    list.head = list.flatten(list.head);

    cout << "New Flattened List: ";
    list.display();
}
