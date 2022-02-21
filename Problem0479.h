//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0479_H
#define ACWINGSOLUTION_PROBLEM0479_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0479 {
private:
    static const int N = 31;
    int dp[N][N];
    int root_value[N][N];
    int scores[N];

    void preOrder(const int st, const int ed) {
        if (st > ed) {
            return;
        }
        printf("%d ", root_value[st][ed]);
        preOrder(st, root_value[st][ed] - 1);
        preOrder(root_value[st][ed] + 1, ed);
    }

    int rangeModel(const int n) {
        for (int length = 1; length <= n; ++length) {
            for (int left = 1; left + length - 1 <= n; ++left) {
                int right = left + length - 1;
                for (auto r_idx = left; r_idx <= right; ++r_idx) {
                    int left_s = r_idx == left ? 1 : dp[left][r_idx - 1];
                    int right_s = r_idx == right ? 1 : dp[r_idx + 1][right];
                    int temp = 0;
                    if (left != right) {
                        temp = left_s * right_s;
                    }
                    temp += scores[r_idx];
                    if (temp > dp[left][right]) {
                        dp[left][right] = temp;
                        root_value[left][right] = r_idx;
                    }
                }
            }
        }
        return dp[1][n];
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &scores[i]);
        }
        printf("%d\n", rangeModel(n));
        preOrder(1, n);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0479_H
