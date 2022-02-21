//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0321_H
#define ACWINGSOLUTION_PROBLEM0321_H

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Problem0321 {
    // https://www.acwing.com/solution/content/62836/
public:
    static const int N = 8;
    static const int M = 15;
    double dp[N + 1][N + 1][N + 1][N + 1][M];
    double prefix[N + 1][N + 1];
    double xa = 0;

    double subSum(const int x1, const int y1, const int x2, const int y2) {
        auto sum = prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1];
        sum -= xa;
        return sum * sum;
    }

    double dfs(const int x1, const int y1, const int x2, const int y2, const int k) {
        double &cur = dp[x1][y1][x2][y2][k];
        if (cur >= 0) {
            return cur;
        }
        if (k == 1) {
            cur = subSum(x1, y1, x2, y2);
            return cur;
        }
        cur = 0x3f3f3f3f;
        for (int i = x1; i < x2; ++i) {
            cur = min(cur, dfs(x1, y1, i, y2, k - 1) + subSum(i + 1, y1, x2, y2));
            cur = min(cur, subSum(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2, k - 1));
        }
        for (int i = y1; i < y2; ++i) {
            cur = min(cur, dfs(x1, y1, x2, i, k - 1) + subSum(x1, i + 1, x2, y2));
            cur = min(cur, subSum(x1, y1, x2, i) + dfs(x1, i + 1, x2, y2, k - 1));
        }
        return cur;
    }

    int main() {
        int k;
        scanf("%d", &k);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf("%lf", &prefix[i][j]);
                prefix[i][j] += prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
            }
        }
        xa = prefix[N][N] / k;
        memset(dp, -1, sizeof dp);
        printf("%.3lf\n", sqrt(dfs(1, 1, N, N, k) / k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0321_H
