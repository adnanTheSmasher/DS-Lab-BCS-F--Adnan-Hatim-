#include<iostream>
#include<string>
using namespace std;



struct Node {
	string key;
	string value;
	Node* next;

	Node(string k, string v) {
		key = k;
		value = v;
		next = nullptr;
	}

};

class HashTable {
	private:
		static const int SIZE = 10;
		Node* table[SIZE];
	public:
		HashTable() {
			for (int i = 0; i < SIZE; i++)
				table[i] = nullptr;
		}

		int hashFunc(string key) {
			int sum = 0;
			for(int i=0; i<key.length(); i++)
				sum += int(key[i]);
			return sum % SIZE;
		}

		void insert(string key, string value) {
			int index = hashFunc(key);
			Node* newNode = new Node(key, value);
		
			if (table[index] == nullptr) {
				table[index] = newNode;
			} else {
				Node* temp = table[index];
				while (temp->next != nullptr) {
           			if (temp->key == key) {
                		temp->value = value;      
                		delete newNode;
                		return;
            		}
            		temp = temp->next;
        		}

     
		        if (temp->key == key) {
		            temp->value = value;
		            delete newNode;
		            return;
		        }
				temp->next = newNode;
			}
		}
		
		string search(string key) {
			int index = hashFunc(key);
			Node* temp = table[index];
			
			while (temp != nullptr) {
	            if (temp->key == key)
	                return temp->value;
	            temp = temp->next;
	        }
	        cout << "Not found";
		}
};




int main() {
	HashTable myHash;
	
	myHash.insert("A", "aaaaa");
	myHash.insert("B", "bbbbb");
	
	cout << myHash.search("A")<< endl;
	cout << myHash.search("B");
	
}