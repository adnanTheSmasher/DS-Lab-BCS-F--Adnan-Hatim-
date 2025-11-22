#include <iostream>
#include <list>
#include <string>
using namespace std;

class Hash {
private:
    static const int SIZE = 10;
    list<pair<string, string>> table[SIZE];  

public:
    
    int hashFunc(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
            sum += int(key[i]);
        return sum % SIZE;
    }


    void insert(string key, string value) {
        int index = hashFunc(key);

        
        for(auto& p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
		}

        
        table[index].push_back({ key, value });
    }

    string search(string key) {
        int index = hashFunc(key);

        for (auto& p : table[index]) {
            if (p.first == key)
                return p.second;
        }
        return "Not Found";
    }

    void removeKey(string key) {
        int index = hashFunc(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Deleted: " << key << endl;
                return;
            }
        }
        cout << "Key not found!" << endl;
    }

    
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";

            for (auto& p : table[i]) {
                cout << "[" << p.first << ":" << p.second << "] -> ";
            }

            cout << "NULL" << endl;
        }
    }
};


int main() {
    Hash h;

    h.insert("A", "aaaa");
    h.insert("B", "bbbb");
    h.insert("AA", "doubleA"); 

    cout << "Search A: " << h.search("A") << endl;
    cout << "Search B: " << h.search("B") << endl;

    h.display();
    cout << endl;

    h.removeKey("A");
    h.display();

    return 0;
}
