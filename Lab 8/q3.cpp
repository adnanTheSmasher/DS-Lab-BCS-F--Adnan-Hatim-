#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


struct Student {
	string name;
	int roll;
	int score;
	Student() {};
	Student(string n, int r, int s) : name(n), roll(r), score(s) {}
};

struct Node {
	Student data;
	Node* left;
	Node* right;
	Node(Student val) {
		data = val;
		left = right = NULL;
	}
};

class BST {
	int count = 0;
	Node* root;
	Node* insert(Node* node, Student val) {
		if (node == NULL) {
			return new Node(val);
		}
		if (val.name < node->data.name) {
			node->left = insert(node->left, val);
		}
		else if (val.name > node->data.name) {
			node->right = insert(node->right, val);
		}
		return node;
	}
public:
	BST() {
		root = NULL;
	}
	void insert(Student val) {
		root = insert(root, val);
	}
	void inorder(Node* node) const {
		if (node != NULL) {
			inorder(node->left);
			cout << node->data.name << " " << node->data.roll << " " << node->data.score << endl;
			inorder(node->right);
		}
	}
	Node* delete_node(Node* node, Student val) {
		if (node == NULL) {
			return node;
		} if (val.name < node->data.name) {
			node->left = delete_node(node->left, val);
		}
		else if (val.name > node->data.name) {
			node->right = delete_node(node->right, val);
		}
		else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return NULL;
			}
			else if (node->left == NULL) {
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == NULL) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
			else {
				Node* temp = find_min(node->right);
				node->data = temp->data;
				node->right = delete_node(node->right, temp->data);
			}
		}
		return node;
	}
	Node* find_min(Node* node) {
		while (node && node->left != NULL)
			node = node->left;
		return node;
	}
	void remove(Student val) {
		root = delete_node(root, val);
	}
	void display() {
		inorder(root);
	}

	bool empty() {
		return root == NULL;
	}
};

int main() {
	
	srand(time(0));

	// 10 Student Objects
	Student arr[10] = {
		{"Ali", 1, 12},
		{"Bilal", 2, 9},
		{"Hassan", 3, 15},
		{"Usman", 4, 7},
		{"Zain", 5, 20},
		{"Faraz", 6, 5},
		{"Hamza", 7, 18},
		{"Noman", 8, 3},
		{"Taha", 9, 14},
		{"Saqib", 10, 8}
	};

	BST tree;

	cout << "Inserting 7 random students...\n\n";
	bool used[10] = { false };
	int inserted = 0;

	while (inserted < 7) {
		int idx = rand() % 10;
		if (!used[idx]) {
			used[idx] = true;
			tree.insert(arr[idx]);
			cout << "Inserted: " << arr[idx].name << "\n";
			inserted++;
		}
	}

	cout << "\nBST Inorder Traversal:\n";
	tree.display();
	cout << "\n";

	string key;
	cout << "Enter a name to search: ";
	cin >> key;

	bool found = false;
	for (int i = 0; i < 10; i++) {
		if (arr[i].name == key) {
			cout << "\nStudent Found:\n";
			cout << arr[i].name << " " << arr[i].roll << " " << arr[i].score << "\n";
			found = true;
			break;
		}
	}
	if (!found)
		cout << "\nStudent not found!\n";
	cout << "\nDeleting students with score < 10...\n";

	for (int i = 0; i < 10; i++) {
		if (arr[i].score < 10) {
			tree.remove(arr[i]);
		}
	}

	cout << "\nBST After Deletion:\n";
	tree.display();
	cout << "\n";

	cout << "Finding student with MAX score...\n";

	int maxScore = -1;
	Student maxStu;

	for (int i = 0; i < 10; i++) {
		if (arr[i].score > maxScore) {
			maxScore = arr[i].score;
			maxStu = arr[i];
		}
	}

	cout << "\nStudent With Highest Score:\n";
	cout << maxStu.name << " " << maxStu.roll << " " << maxStu.score << "\n";

	return 0;
}
