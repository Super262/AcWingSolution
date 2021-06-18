//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0902_H
#define ACWINGSOLUTION_PROBLEM0902_H

#include <iostream>

using namespace std;

class Problem0902 {
public:
    unsigned int editDistance(const char *a, const unsigned int l1, const char *b, const unsigned int l2) {
        auto dp = new unsigned int *[l1 + 1];
        for (unsigned int i = 0; i <= l1; ++i) {
            dp[i] = new unsigned int[l2 + 1];
            for (unsigned int j = 0; j <= l2; ++j) {
                dp[i][j] = l1 + l2 + 1;
            }
        }
        for (unsigned int i = 0; i <= l2; ++i) {
            dp[0][i] = i;
        }
        for (unsigned int i = 1; i <= l1; ++i) {
            for (unsigned int j = 1; j <= l2; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
        unsigned int result = dp[l1][l2];
        for (unsigned int i = 0; i <= l1; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int l1;
        scanf("%d", &l1);
        auto a = new char[l1 + 1];
        scanf("%s", a);
        unsigned int l2;
        scanf("%d", &l2);
        auto b = new char[l2 + 1];
        scanf("%s", b);
        printf("%d", editDistance(a, l1, b, l2));
        delete[] a;
        delete[] b;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0902_H
