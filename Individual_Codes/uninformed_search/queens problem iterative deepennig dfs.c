#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 8

int board[N];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(board[i] == j ? "Q " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool dls(int row, int limit) {
    if (row == N) {
        return true;
    }
    if (row >= limit) {
        return false;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (dls(row + 1, limit)) return true;
        }
    }
    return false;
}

void iddfs() {
    for (int limit = 1; limit <= N; limit++) {
        printf("Searching with Depth Limit: %d\n", limit);
        if (dls(0, limit) && limit == N) {
            printf("Solution found at depth %d!\n", limit);
            printSolution();
            return;
        }
    }
    printf("No solution found.\n");
}

int main() {
    iddfs();
    return 0;
}