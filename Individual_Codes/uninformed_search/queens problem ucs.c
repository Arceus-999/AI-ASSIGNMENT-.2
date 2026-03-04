#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8
#define MAX_NODES 100000

typedef struct {
    int queens[N];
    int rowCount;
    int cost;
} Node;

Node heap[MAX_NODES];
int heapSize = 0;

void push(Node n) {
    int i = heapSize++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].cost <= n.cost) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = n;
}

Node pop() {
    Node res = heap[0];
    Node last = heap[--heapSize];
    int i = 0;
    while (i * 2 + 1 < heapSize) {
        int child = i * 2 + 1;
        if (child + 1 < heapSize && heap[child + 1].cost < heap[child].cost) child++;
        if (last.cost <= heap[child].cost) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return res;
}

bool isSafe(int queens[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || 
            queens[i] - i == col - row || 
            queens[i] + i == col + row)
            return false;
    }
    return true;
}

void solveUCS() {
    Node start;
    start.rowCount = 0;
    start.cost = 0;
    push(start);

    while (heapSize > 0) {
        Node curr = pop();

        if (curr.rowCount == N) {
            printf("UCS Solution Found (Cost: %d):\n", curr.cost);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf(curr.queens[i] == j ? "Q " : ". ");
                }
                printf("\n");
            }
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isSafe(curr.queens, curr.rowCount, col)) {
                Node next = curr;
                next.queens[next.rowCount] = col;
                next.rowCount++;
                next.cost = curr.cost + 1; 
                push(next);
            }
        }
    }
}

int main() {
    solveUCS();
    return 0;
}