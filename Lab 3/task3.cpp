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

    Node* reverse_K_Element(int k) {
        head = reverseKUtil(head, k);
        return head;
    }

private:
    Node* reverseKUtil(Node* start, int k) {
        if (!start || k <= 1) return start;

        // Check if there are at least k nodes remaining
        Node* tmp = start;
        int cnt = 0;
        while (tmp && cnt < k) {
            cnt++;
            tmp = tmp->next;
        }
        if (cnt < k) return start; // fewer than k: leave as-is

        Node* prev = nullptr;
        Node* curr = start;
        Node* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != nullptr) {
            start->next = reverseKUtil(next, k);
        }

        return prev;
    }
};

int main() {
    Singly list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);
    list1.insertAtEnd(6);
    list1.insertAtEnd(7);
    list1.insertAtEnd(8);

    cout << "Original List: ";
    list1.display();

    int k = 3;
    list1.reverse_K_Element(k);  

    cout << "\nReversed List: ";
    list1.display();

    return 0;
}
