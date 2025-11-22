#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Pair {
    int a, b;
};

int main() {
    vector<int> arr = { 3, 4, 7, 1, 2, 9, 8 };

    const int SIZE = 50;   
    list<Pair> table[SIZE];

    bool found = false;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];
            int index = sum % SIZE;   

            for (auto& p : table[index]) {
                if (p.a != arr[i] && p.a != arr[j] &&
                    p.b != arr[i] && p.b != arr[j]) {

                    cout << "(" << p.a << ", " << p.b << ") and ("
                        << arr[i] << ", " << arr[j] << ")";

                    found = true;
                    break;
                }
            }

            if (found) break;

            table[index].push_back({ arr[i], arr[j] });
        }
        if (found) break;
    }

    if (!found) {
        cout << "No pairs found";
    }

    return 0;
}
