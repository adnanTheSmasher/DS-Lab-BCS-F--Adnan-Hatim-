#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


struct combatant {
	string name;
	int power;
	int health;
	combatant() {};
	combatant(string n, int h,int p) : name(n),health(h), power(p) {}
};

struct Node {
	combatant data;
	Node* left;
	Node* right;
	Node(combatant val) {
		data = val;	
		left = right = NULL;
	}
};

class BST {
	int count = 0;
	Node* root;
	Node* insert(Node* node, combatant val) {
		if (node == NULL) {
			return new Node(val);
		}
		if (val.power < node->data.power) {
			node->left = insert(node->left, val);
		}
		else if (val.power > node->data.power) {
			node->right = insert(node->right, val);
		}
		return node;
	}
public:
	BST() {
		root = NULL;
	}
	void insert(combatant val) {
		root = insert(root, val);
	}
	void inorder(Node* node) const {
		if (node != NULL) {
			inorder(node->left);
			cout << node->data.name << " " << node->data.health << " " << node->data.power<<endl;
			inorder(node->right);
		}
	}
	Node* delete_node(Node* node, combatant val) {
		if (node == NULL) {
			return node;
		} if (val.power < node->data.power) {
			node->left = delete_node(node->left, val);
		}
		else if (val.power > node->data.power) {
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
	void remove(combatant val) {
		root = delete_node(root, val);
	}
	void display() {
		inorder(root);
	}
	
	bool empty() {
		return root == NULL;
	}
	
	combatant getFrontLine() {
		return find_min(root)->data;
	}
};

int main() {
	srand(time(0));

	BST player;
	BST enemy;

	cout << "Initializing Player & Enemy Teams...\n\n";

	// Player heroes
	player.insert(combatant("Arthur", 40, 8));
	player.insert(combatant("Baldur", 35, 9));
	player.insert(combatant("Cedric", 32, 7));
	player.insert(combatant("Dorian", 38, 6));
	player.insert(combatant("Elden", 30, 10));

	// Enemy team
	enemy.insert(combatant("Zark", 34, 8));
	enemy.insert(combatant("Yorin", 36, 7));
	enemy.insert(combatant("Xerath", 33, 9));
	enemy.insert(combatant("Warg", 40, 6));
	enemy.insert(combatant("Vorn", 32, 10));

	int round = 1;

	while (!player.empty() && !enemy.empty()) {
		cout << "----- Round " << round++ << " -----\n";
		combatant pHero = player.getFrontLine();
		combatant eHero = enemy.getFrontLine();

		cout << "Frontline Battle: " << pHero.name << " vs " << eHero.name << "\n\n";

		int pdmg = pHero.power + (rand() % 5); 
		cout << pHero.name << " hits " << eHero.name << " for " << pdmg << " damage!\n";
		eHero.health -= pdmg;

		enemy.remove(enemy.getFrontLine());
		
		if (eHero.health > 0)
			enemy.insert(eHero);
		else
			cout << eHero.name << " has been defeated!\n";
		if (enemy.empty()) break;
		
		int edmg = eHero.power + (rand() % 5);
		cout << eHero.name << " hits " << pHero.name << " for " << edmg << " damage!\n";
		pHero.health -= edmg;
		player.remove(player.getFrontLine());

		if (pHero.health > 0)
			player.insert(pHero);
		else
			cout << pHero.name << " has been defeated!\n";
		if (player.empty()) break;

		cout << "\nPlayer Team:\n";
		player.display();
		cout << "\nEnemy Team:\n";
		enemy.display();
		cout << "\n";
	}

}
