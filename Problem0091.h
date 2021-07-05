//
// Created by Fengwei Zhang on 2021/6/19.
//

#ifndef ACWINGSOLUTION_PROBLEM0091_H
#define ACWINGSOLUTION_PROBLEM0091_H

#include <iostream>

using namespace std;

class Problem0091 {
public:
    int shortestHamilton(int **graph, const int N) {
        const int LAST_STATE = (1 << N) - 1;
        auto dp = new int*[LAST_STATE + 1];
        for (int s = 0; s <= LAST_STATE; ++s) {
            dp[s] = new int[N];
            memset(dp[s], 0x7f, sizeof(int) * (N));
        }
        dp[1][0] = 0;
        for (int s = 0; s <= LAST_STATE; ++s) {
            for (int v = 0; v < N; ++v) {
                if (!((s >> v) & 1)) {
                    continue;
                }
                for (int u = 0; u < N; ++u) {
                    if (!(((s - (1 << v)) >> u) & 1)) {
                        continue;
                    }
                    if (dp[s - (1 << v)][u] == 0x7f7f7f7f) {
                        continue;
                    }
                    dp[s][v] = min(dp[s][v], dp[s- (1 << v)][u] + graph[u][v]);
                }
            }
        }
        int result = dp[LAST_STATE][N - 1];
        for (int s = 0; s <= LAST_STATE; ++s) {
            delete[] dp[s];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto graph = new int*[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new int [n];
            for (int j = 0; j < n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        printf("%d\n", shortestHamilton(graph, n));
        for (int i = 0; i < n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0091_H
