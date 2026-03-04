#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

bool dls(int row, int limit) {
    if (row == N) {
        printSolution();
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

int main() {
    int limit;
    printf("Enter depth limit (e.g., 8): ");
    scanf("%d", &limit);

    printf("Starting DLS with limit %d...\n", limit);
    if (!dls(0, limit)) {
        printf("No solution found within depth limit %d.\n", limit);
    }

    return 0;
}