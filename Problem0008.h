//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0008_H
#define ACWINGSOLUTION_PROBLEM0008_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0008 {
public:
    int main() {
        int N, V, M;
        scanf("%d%d%d", &N, &V, &M);
        auto dp = new int *[V + 1];
        for (int i = 0; i <= V; ++i) {
            dp[i] = new int[M + 1];
            memset(dp[i], 0, sizeof(int) * (M + 1));
        }
        for (int k = 0; k < N; ++k) {
            int v, m, w;
            scanf("%d%d%d", &v, &m, &w);
            for (int i = V; i >= v; --i) {
                for (int j = M; j >= m; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - v][j - m] + w);
                }
            }
        }
        printf("%d\n", dp[V][M]);
        for (int i = 0; i <= V; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0008_H
