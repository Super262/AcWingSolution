//
// Created by Fengwei Zhang on 2021/7/6.
//

#ifndef ACWINGSOLUTION_PROBLEM1018_H
#define ACWINGSOLUTION_PROBLEM1018_H

class Problem1018 {
public:
    int minPath(int **graph, const int N) {
        auto dp = new int *[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = new int[N];
        }
        dp[0][0] = graph[0][0];
        for (int i = 1; i < N; ++i) {
            dp[0][i] = dp[0][i - 1] + graph[0][i];
            dp[i][0] = dp[i - 1][0] + graph[i][0];
        }
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];
            }
        }
        int result = dp[N - 1][N - 1];
        for (int i = 0; i < N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto graph = new int *[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        printf("%d\n", minPath(graph, n));
        for (int i = 0; i < n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1018_H
