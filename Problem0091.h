//
// Created by Fengwei Zhang on 2021/6/19.
//

#ifndef ACWINGSOLUTION_PROBLEM0091_H
#define ACWINGSOLUTION_PROBLEM0091_H

#include <iostream>

using namespace std;

class Problem0091 {
public:
    unsigned int shortestHamilton(unsigned int **graph, const unsigned int n) {
        const unsigned int lastState = (1 << n) - 1;
        auto dp = new unsigned int *[lastState + 1];
        for (unsigned int s = 0; s <= lastState; ++s) {
            dp[s] = new unsigned int[n];
            for (unsigned int v = 0; v < n; ++v) {
                dp[s][v] = 0x3f3f3f3f;
            }
        }
        dp[1][0] = 0;
        for (unsigned int s = 0; s <= lastState; ++s) {
            for (unsigned int v = 0; v < n; ++v) {
                if (!((s >> v) & 1)) {
                    continue;
                }
                for (unsigned int u = 0; u < n; ++u) {
                    if (!(((s - (1 << v)) >> u) & 1)) {
                        continue;
                    }
                    dp[s][v] = min(dp[s][v], dp[s - (1 << v)][u] + graph[u][v]);
                }
            }
        }
        for (unsigned int s = 0; s <= lastState; ++s) {
            delete[] dp[s];
        }
        unsigned int result = dp[lastState][n - 1];
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        unsigned int w;
        auto **graph = new unsigned int *[n];
        for (unsigned int u = 0; u < n; ++u) {
            graph[u] = new unsigned int[n];
            for (unsigned int v = 0; v < n; ++v) {
                scanf("%d", &w);
                graph[u][v] = w;
            }
        }
        printf("%d\n", shortestHamilton(graph, n));
        for (unsigned int u = 0; u < n; ++u) {
            delete[] graph[u];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0091_H
