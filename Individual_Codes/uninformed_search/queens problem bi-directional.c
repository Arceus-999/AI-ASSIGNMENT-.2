#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8
#define MID 4

typedef struct {
    int queens[N];
} State;

State forward_states[1000];
int f_count = 0;

bool isSafe(int queens[], int row, int col, int step) {
    int start = (step > 0) ? 0 : N - 1;
    int end = (step > 0) ? row : row;

    for (int i = (step > 0 ? 0 : N - 1); (step > 0 ? i < row : i > row); i += step) {
        if (queens[i] == col || 
            abs(queens[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveForward(int row, int current_board[]) {
    if (row == MID) {
        for (int i = 0; i < MID; i++) forward_states[f_count].queens[i] = current_board[i];
        f_count++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(current_board, row, col, 1)) {
            current_board[row] = col;
            solveForward(row + 1, current_board);
        }
    }
}

bool canMerge(int f[], int b[]) {
    for (int i = 0; i < MID; i++) {
        for (int j = MID; j < N; j++) {
            if (f[i] == b[j] || abs(f[i] - b[j]) == abs(i - j))
                return false;
        }
    }
    return true;
}

void solveBackward(int row, int current_board[]) {
    if (row == MID - 1) {
        for (int i = 0; i < f_count; i++) {
            if (canMerge(forward_states[i].queens, current_board)) {
                printf("Bidirectional Match Found:\n");
                for (int r = 0; r < N; r++) {
                    int q_col = (r < MID) ? forward_states[i].queens[r] : current_board[r];
                    for (int c = 0; c < N; c++) printf(c == q_col ? "Q " : ". ");
                    printf("\n");
                }
                exit(0); 
            }
        }
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(current_board, row, col, -1)) {
            current_board[row] = col;
            solveBackward(row - 1, current_board);
        }
    }
}

int main() {
    int board[N];
    solveForward(0, board);
    solveBackward(N - 1, board);
    return 0;
}