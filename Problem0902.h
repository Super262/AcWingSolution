//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0902_H
#define ACWINGSOLUTION_PROBLEM0902_H

#include <iostream>

using namespace std;

class Problem0902 {
private:
    static const int N = 1010;
    int dp[N][N];
    char s1[N];
    char s2[N];

    int editDistance(const int l1, const int l2) {
        // 不要忘记初始化操作
        for (int i = 0; i <= l2; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i <= l1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = l1 + l2 + 1;
                if (s1[i] == s2[j]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
        }
        return dp[l1][l2];
    }

    int main() {
        int l1, l2;
        scanf("%d", &l1);
        scanf("%s", s1 + 1);
        scanf("%d", &l2);
        scanf("%s", s2 + 1);
        printf("%d\n", editDistance(l1, l2));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0902_H
