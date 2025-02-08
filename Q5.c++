// Rotating a square matrix clockwise
#include <iostream>

int** rotateMatrix90Clockwise(int** matrix, int n) {
    int** rotatedMatrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        rotatedMatrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
        }
    }

    return rotatedMatrix;
}

int** createMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;

    int** matrix = createMatrix(n);

    std::cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Original Matrix:\n";
    printMatrix(matrix, n);

    int** rotatedMatrix = rotateMatrix90Clockwise(matrix, n);

    std::cout << "Matrix after 90-degree clockwise rotation:\n";
    printMatrix(rotatedMatrix, n);

    deleteMatrix(matrix, n);
    deleteMatrix(rotatedMatrix, n);

    return 0;
}