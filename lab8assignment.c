#include <stdio.h>
#include <limits.h>

int minCost = INT_MAX;
int visited[10] = {0};

void solve(int cost[3][3], int n, int row, int currentCost) {
    if (row == n) {
        if (currentCost < minCost)
            minCost = currentCost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            solve(cost, n, row + 1, currentCost + cost[row][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    int cost[3][3] = {
        {9, 2, 7},
        {6, 4, 3},
        {5, 8, 1}
    };
    int n = 3;
    solve(cost, n, 0, 0);
    printf("Minimum assignment cost = %d\n", minCost);
    return 0;
}
