#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* balance(Node* node) {
        int bf = getBalance(node);

        if (bf > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);


        if (bf > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);

        if (bf < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node; 
    }

    Node* insert(Node* node, int val) {
        if (!node)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            return node;

        updateHeight(node);
        return balance(node);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() { root = nullptr; }

    void insert(int val) {
        root = insert(root, val);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL tree;

    cout << "Inserting 10\n";
    tree.insert(10);
    tree.display();

    cout << "Inserting 20\n";
    tree.insert(20);
    tree.display();

    cout << "Inserting 30\n";
    tree.insert(30); 
    tree.display();

    cout << "Inserting 40\n";
    tree.insert(40);
    tree.display();

    cout << "Inserting 50\n";
    tree.insert(50);
    tree.display();

    cout << "Inserting 15\n";
    tree.insert(15); 
    tree.display();

    return 0;
}
