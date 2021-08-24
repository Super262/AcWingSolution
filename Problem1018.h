//
// Created by Fengwei Zhang on 2021/7/6.
//

#ifndef ACWINGSOLUTION_PROBLEM1018_H
#define ACWINGSOLUTION_PROBLEM1018_H

class Problem1018 {
private:
    const int N = 101;
    int graph[N][N];

    int minCost(const int n) {
        for (int i = 1; i <= n; ++i) {
            graph[i][1] += graph[i - 1][1];
            graph[1][i] += graph[1][i - 1];
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= n; ++j) {
                graph[i][j] += min(graph[i - 1][j], graph[i][j - 1]);
            }
        }
        return graph[n][n];
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        printf("%d\n", minCost(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1018_H
