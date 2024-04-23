#include <stdio.h>
#include <stdlib.h>

// Function to print the chess board
void printBoard(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
int isSafe(int n, int board[n][n], int row, int col)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Recursive utility function to solve N Queen problem
int solveNQUtil(int n, int board[n][n], int col)
{
    // Base case: If all queens are placed then return true
    if (col >= n)
        return 1;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < n; i++)
    {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(n, board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(n, board, col + 1))
                return 1;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column col then return false
    return 0;
}

// This function solves the N Queen problem using Backtracking
void solveNQ(int n)
{
    int board[n][n];
    memset(board, 0, sizeof(board));

    if (solveNQUtil(n, board, 0) == 0)
    {
        printf("Solution does not exist");
        return;
    }

    printBoard(n, board);
}

int main()
{
    int choice;
    printf("Enter the board size:\n");
    printf("\t1. For 4 * 4 chess board\n");
    printf("\t2. For 8 * 8 chess board\n");
    printf("Enter your choice:\t");
    scanf("%d", &choice);

    if (choice == 1)
    {
        solveNQ(4);
    }
    else if (choice == 2)
    {
        solveNQ(8);
    }
    else
    {
        printf("Program halted, wrong input");
    }

    return 0;
}