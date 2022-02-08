//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0899_H
#define ACWINGSOLUTION_PROBLEM0899_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0899 {
private:
    static const int N = 1010;
    static const int M = 20;
    int dp[M][M];
    char strs[N][M];
    char temp[M];

    int editDistance(const char s1[], const int l1, const char s2[], const int l2) {
        for (int i = 0; i <= l1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= l2; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = l1 + l2 + 1;
                if (s1[i] == s2[j]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[l1][l2];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", strs[i] + 1);
        }
        for (int i = 0; i < m; ++i) {
            int result = 0;
            int maxStep;
            scanf("%s%d", temp + 1, &maxStep);
            for (int j = 0; j < n; ++j) {
                if (editDistance(strs[j], (int) strlen(strs[j] + 1), temp, (int) strlen(temp + 1)) <= maxStep) {
                    ++result;
                }
            }
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0899_H
