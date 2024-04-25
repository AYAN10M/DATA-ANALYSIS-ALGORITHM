#include <stdio.h>

int chessboard[30]; // Array to store queen positions on the chessboard (1-based indexing)
int numSolutions = 0; // Counter for total solutions found

// Function to check if a queen can be placed at the given position
int isSafe(int col, int row, int n) {
    int i, j;

    // Check for queens in the same row or diagonal
    for (i = 1; i < col; i++) {
        if (chessboard[i] == row || (chessboard[i] - row) == (col - i) || (chessboard[i] - row) == -(col - i)) {
            return 0; // Not safe
        }
    }

    return 1; // Safe position
}

// Function to print a solution (queen placement on the chessboard)
void printSolution(int n) {
    int i, j;

    numSolutions++; // Increment solution counter

    printf("\n\nSolution #%d:\n", numSolutions);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (chessboard[i] == j) {
                printf(" Q "); // Queen symbol
            } else {
                printf(" * "); // Empty space
            }
        }
        printf("\n");
    }
}

// Recursive function to solve the N-Queens problem
void solveNQueens(int col, int n) {
    if (col > n) {
        // All queens placed successfully, print the solution
        printSolution(n);
        return;
    }

    // Try placing the queen in all possible rows of the current column
    for (int row = 1; row <= n; row++) {
        if (isSafe(col, row, n)) {
            chessboard[col] = row; // Place the queen
            solveNQueens(col + 1, n); // Recur for next column
        }
    }
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    solveNQueens(1, n); // Start from column 1

    printf("\nTotal solutions: %d\n", numSolutions);

    return 0;
}
