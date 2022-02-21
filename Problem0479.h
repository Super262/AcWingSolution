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
        for (int l = 1; l <= n; ++l) {
            for (int st = 1; st + l - 1 <= n; ++st) {
                auto ed = st + l - 1;
                for (auto r_idx = st; r_idx <= ed; ++r_idx) {  // 从前向后选择根结点，保证前序字典序最小
                    int left_s = r_idx == st ? 1 : dp[st][r_idx - 1];
                    int right_s = r_idx == ed ? 1 : dp[r_idx + 1][ed];
                    int temp = 0;
                    if (st != ed) {
                        temp = left_s * right_s;
                    }
                    temp += scores[r_idx];
                    if (temp > dp[st][ed]) {
                        dp[st][ed] = temp;
                        root_value[st][ed] = r_idx;
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
