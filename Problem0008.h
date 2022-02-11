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
        int dp[V + 1][M + 1];
        memset(dp, 0, sizeof dp);
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
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0008_H
