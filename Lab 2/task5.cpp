#include <iostream>
using namespace std;


int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}


void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter elements (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of cols: ";
    cin >> cols;

    int** A = createMatrix(rows, cols);
    int** B = createMatrix(rows, cols);

    cout << "\nMatrix A:\n";
    inputMatrix(A, rows, cols);

    cout << "\nMatrix B:\n";
    inputMatrix(B, rows, cols);

    cout << "\nMatrix A:\n";
    printMatrix(A, rows, cols);

    cout << "\nMatrix B:\n";
    printMatrix(B, rows, cols);

    int** sum = addMatrices(A, B, rows, cols);
    cout << "\nA + B:\n";
    printMatrix(sum, rows, cols);

    int** diff = subtractMatrices(A, B, rows, cols);
    cout << "\nA - B:\n";
    printMatrix(diff, rows, cols);

    deleteMatrix(A, rows);
    deleteMatrix(B, rows);
    deleteMatrix(sum, rows);
    deleteMatrix(diff, rows);

    return 0;
}
