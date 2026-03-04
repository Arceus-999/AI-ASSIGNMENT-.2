#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) printf("Q ");
            else printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool solveDFS(int row) {
    if (row == N) {
        printSolution();
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solveDFS(row + 1)) return true;
        }
    }
    return false;
}

int main() {
    solveDFS(0);
    return 0;
}