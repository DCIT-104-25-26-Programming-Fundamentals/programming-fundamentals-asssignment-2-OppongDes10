// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void readMatrix(int matrix[10][10], int &rows, int &cols, string name) {
    cout << "\nEnter " << name << " matrix:" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols, string title) {
    cout << "\n" << title << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int original[10][10], int result[10][10], int rows, int cols, int &newRows, int &newCols) {
    newRows = cols;
    newCols = rows;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = original[i][j];
        }
    }
}

void addMatrices(int matA[10][10], int matB[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void multiplyMatrices(int matA[10][10], int matB[10][10], int result[10][10], 
                      int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    int matrix1[10][10], matrix2[10][10], matrix3[10][10];
    int rows1, cols1, rows2, cols2, rows3, cols3;
    
    cout << "=== MATRIX OPERATIONS PROGRAM ===" << endl;
    
    cout << "\nPART A - TRANSPOSE A MATRIX" << endl;
    readMatrix(matrix1, rows1, cols1, "original");
    transpose(matrix1, matrix3, rows1, cols1, rows3, cols3);
    printMatrix(matrix1, rows1, cols1, "Original Matrix:");
    printMatrix(matrix3, rows3, cols3, "Transposed Matrix:");
    
    cout << "\n" << string(50, '=');
    cout << "\nPART B - ADD TWO MATRICES" << endl;
    readMatrix(matrix1, rows1, cols1, "first");
    readMatrix(matrix2, rows2, cols2, "second");
    
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Error: Matrices must be the same size!" << endl;
    } else {
        addMatrices(matrix1, matrix2, matrix3, rows1, cols1);
        printMatrix(matrix1, rows1, cols1, "Matrix A:");
        printMatrix(matrix2, rows2, cols2, "Matrix B:");
        printMatrix(matrix3, rows1, cols1, "Sum (A + B):");
    }
    
    cout << "\n" << string(50, '=');
    cout << "\nPART C - MULTIPLY TWO MATRICES" << endl;
    readMatrix(matrix1, rows1, cols1, "first (A)");
    readMatrix(matrix2, rows2, cols2, "second (B)");
    
    if (cols1 != rows2) {
        cout << "Error: Columns in A must equal rows in B!" << endl;
    } else {
        multiplyMatrices(matrix1, matrix2, matrix3, rows1, cols1, rows2, cols2);
        printMatrix(matrix1, rows1, cols1, "Matrix A:");
        printMatrix(matrix2, rows2, cols2, "Matrix B:");
        printMatrix(matrix3, rows1, cols2, "Product (A x B):");
    }
    
    return 0;
}