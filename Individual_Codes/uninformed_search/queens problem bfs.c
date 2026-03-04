#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8
#define MAX_QUEUE 100000

typedef struct {
    int queens[N];
    int rowCount;
} Node;

bool isSafeBFS(int queens[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || 
            queens[i] - i == col - row || 
            queens[i] + i == col + row)
            return false;
    }
    return true;
}

void solveBFS() {
    Node* queue = malloc(sizeof(Node) * MAX_QUEUE);
    int head = 0, tail = 0;

    Node start;
    start.rowCount = 0;
    queue[tail++] = start;

    while (head < tail) {
        Node curr = queue[head++];

        if (curr.rowCount == N) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf(curr.queens[i] == j ? "Q " : ". ");
                }
                printf("\n");
            }
            free(queue);
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isSafeBFS(curr.queens, curr.rowCount, col)) {
                Node next = curr;
                next.queens[next.rowCount] = col;
                next.rowCount++;
                queue[tail++] = next;
            }
        }
    }
    free(queue);
}

int main() {
    solveBFS();
    return 0;
}