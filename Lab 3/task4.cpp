#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Circular {
public:
    Node* head;
    Node* tail;

    Circular() {
        head = nullptr;
        tail = nullptr;
    }

    void insertend(int val)
    {
        Node* n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
            tail->next = head;
        }
        else {
            tail->next = n;
            tail = n;
            tail->next = head;
        }
    }
    
    int josephus(int k) {
        if (!head) return -1;             
       if (k <= 0) return -1;
        if (!head || head->next == head) return head->data;

        Node* curr = head;
        Node* prev = tail;

        while (curr->next != curr) {
            for (int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next;
            }

            cout << curr->data << "Eliminatered" << endl;

            prev->next = curr->next;
            if (curr == head) head = curr->next;
            if (curr == tail) tail = prev;

            delete curr;
            curr = prev->next;
        }
        head = curr;
        return curr->data;
    }

    void display(int n) {
        if (!head) return;
        Node* temp = head;
        for (int i = 0; i < n; i++) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "(back to head)" << endl;
    }
};

int main() {
    int n = 7, k = 3;
    Circular circle;

    
    for (int i = 1; i <= n; i++) {
        circle.insertend(i);
    }

    cout << "Initial Circle: ";
    circle.display(n);

    int survivor = circle.josephus(k);

    cout << "Survivor is at position: " << survivor << endl;

    return 0;
}
