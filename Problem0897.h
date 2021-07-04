//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0897_H
#define ACWINGSOLUTION_PROBLEM0897_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0897 {
public:
    int longestCommonSequence(const char *a, const int l1, const char *b, const int l2) {
        auto dp = new int*[l1 + 1];
        for (int i = 0; i <= l1; ++i) {
            dp[i] = new int[l2 + 1];
            memset(dp[i], 0, sizeof(int) * (l2 + 1));
        }
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        int result = dp[l1][l2];
        for (int i = 0; i <= l1; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int l1, l2;
        scanf("%d%d", &l1, &l2);
        auto a = new char[l1 + 1];
        auto b = new char[l2 + 1];
        scanf("%s%s", a, b);
        printf("%d\n", longestCommonSequence(a, l1, b, l2));
        delete[] a;
        delete[] b;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0897_H
