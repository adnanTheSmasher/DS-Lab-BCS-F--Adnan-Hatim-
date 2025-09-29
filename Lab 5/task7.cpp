#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void chesssBoardPrint(const vector<int>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}


bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}


void solving(vector<int>& board, int n, int row, int& solutionCount) {
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        chesssBoardPrint(board, n);
        return; 
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solving(board, n, row + 1, solutionCount);
            board[row] = -1;  
        }
    }
}

int main() {
    int n;
    cout << "Enter value of cheesboard row/cols: ";
    cin >> n;

    vector<int> board(n, -1);  
    int solutionCount = 0;

    solving(board, n, 0, solutionCount);

    if (solutionCount == 0)
        cout << "No solution  for: " << n  <<" size" << endl;
    else
        cout << "Total solutions for " << n << "  size: " << solutionCount << endl;
        cout << "Total solutions for " << n << "  sizeddsd: " << solutionCount << endl;

    return 0;
}
