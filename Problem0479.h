//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0479_H
#define ACWINGSOLUTION_PROBLEM0479_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0479 {
public:
    void preOrder(int **roots, const int start, const int end) {
        if (start > end) {
            return;
        }
        printf("%d ", roots[start][end]);
        preOrder(roots, start, roots[start][end] - 1);
        preOrder(roots, roots[start][end] + 1, end);
    }

    int maxScore(const int *scores, const int N, int **roots) {
        auto dp = new int *[N + 1];
        for (int i = 1; i <= N; ++i) {
            dp[i] = new int[N + 1];
            memset(dp[i], -1, sizeof(int) * (N + 1));
        }
        for (int length = 1; length <= N; ++length) {
            for (int left = 1; left + length - 1 <= N; ++left) {
                const int right = left + length - 1;
                for (int rootIdx = left; rootIdx <= right; ++rootIdx) {
                    int leftScore = rootIdx == left ? 1 : dp[left][rootIdx - 1];
                    int rightScore = rootIdx == right ? 1 : dp[rootIdx + 1][right];
                    // 注意这里的判断：不要忽视 left == right 的情况
                    int temp;
                    if (left == right) {
                        temp = scores[rootIdx];
                    } else {
                        temp = leftScore * rightScore + scores[rootIdx];
                    }
                    if (temp > dp[left][right]) {
                        dp[left][right] = temp;
                        roots[left][right] = rootIdx;
                    }
                }
            }
        }
        int result = dp[1][N];
        for (int i = 1; i <= N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto scores = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &scores[i]);
        }
        auto roots = new int *[n + 1];
        for (int i = 1; i <= n; ++i) {
            roots[i] = new int[n + 1];
        }
        printf("%d\n", maxScore(scores, n, roots));
        preOrder(roots, 1, n);
        delete[] scores;
        for (int i = 1; i <= n; ++i) {
            delete[] roots[i];
        }
        delete[] roots;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0479_H
