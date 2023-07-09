#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10

int board[MAX_N][MAX_N];
int count = 0;

void printBoard(int n) {
    int i, j;
    count++;
    printf("Solution: %d\n",count);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int canPlace(int row, int col, int n) {
    int i, j;
    // Check row and column
    for (i = 0; i < n; i++) {
        if (board[row][i] || board[i][col]) {
            return 0;
        }
    }
    // Check diagonals
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i + j == row + col || i - j == row - col) {
                if (board[i][j]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void solveNQueens(int row, int n) {
    int col;
    if (row == n) {
        printBoard(n);
        return;
    }
    for (col = 0; col < n; col++) {
        if (canPlace(row, col, n)) {
            board[row][col] = 1;
            solveNQueens(row + 1, n);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    solveNQueens(0, n);
    if (count!=0)
        printf("Total number of solutions is %d\n",count);
    else
        printf("Solution does not exist");
}
