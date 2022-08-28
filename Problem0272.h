//
// Created by Fengwei Zhang on 2021/7/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0272_H
#define ACWINGSOLUTION_PROBLEM0272_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0272 {
    // dp[i][j]表示所有由序列a的前i个字母和序列b的前j个字母构成的，且以b[j]结尾的公共上升子序列
    // https://www.acwing.com/solution/content/4955/
private:
    static const int N = 3010;
    int dp[N][N];
    int a[N], b[N];

    int longestCommonIS(const int l1, const int l2) {
        // 不要忘记优化过程
        for (int i = 1; i <= l1; ++i) {
            int max_pre_j = 1;
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (a[i] == b[j]) {
                    dp[i][j] = max(max_pre_j, dp[i][j]);
                } else if (b[j] < a[i]) {
                    max_pre_j = max(max_pre_j, dp[i - 1][j] + 1);
                }
            }
        }
        int ans = 0;
        // 注意：不能通过遍历a的索引来获得结果，只能遍历b的索引（参见转移方程）
        for (int i = 1; i <= l2; ++i) {
            ans = max(ans, dp[l1][i]);
        }
        return ans;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        printf("%d\n", longestCommonIS(n, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0272_H
