//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0897_H
#define ACWINGSOLUTION_PROBLEM0897_H

#include <iostream>

using namespace std;

class Problem0897 {
private:
    static const int N = 1010;
    char s1[N];
    char s2[N];
    int dp[N][N];

    int longestCommonSequence(const int l1, const int l2) {
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i] != s2[j]) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        return dp[l1][l2];
    }

    int main() {
        int l1, l2;
        scanf("%d%d", &l1, &l2);
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);
        printf("%d\n", longestCommonSequence(l1, l2));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0897_H
