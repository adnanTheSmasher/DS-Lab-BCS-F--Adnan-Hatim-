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
		static const int SIZE = 100;
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

		void Add_Record(string key, string value) {
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
		
		string Wrod_Search(string key) {
			int index = hashFunc(key);
			Node* temp = table[index];
			
			while (temp != nullptr) {
	            if (temp->key == key)
	                return temp->value;
	            temp = temp->next;
	        }
	        cout << "Not found";
		}
		
		string Print_Dictionary(){
			for (int i=0; i<SIZE; i++){	
				Node* temp = table[i];
				
				while (temp != nullptr) {
		            cout << temp->value;
		            temp = temp->next;
		        }
			}
	        
		}
};




int main() {
	HashTable myHash;
	string key, value;
	int size;
	
	cout << "How many Word do you ant to Enter: ";
	cin >> size;

	for (int i=0; i<size; i++){
		cout << "Enter your Key: ";
		cin >> key;
		 
		cout << "Enter your Dictionary Word: ";
		cin >> value;
		
		myHash.Add_Record(key, value);
	}	
	  
	myHash.Print_Dictionary();
	
}