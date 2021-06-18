//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0899_H
#define ACWINGSOLUTION_PROBLEM0899_H

#include <iostream>
#include <cstring>

using namespace std;


class Problem0899 {
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
        for (unsigned int i = 0; i <= l1; ++i) {
            dp[i][0] = i;
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
        unsigned int n, q;
        scanf("%d%d", &n, &q);
        auto strs = new char *[n];
        for (unsigned int i = 0; i < n; ++i) {
            strs[i] = new char[11];
            memset(strs[i], 0, sizeof(char) * 11);
            scanf("%s", strs[i]);
        }
        auto target = new char[11];
        unsigned int maxStep;
        unsigned int count;
        memset(target, 0, sizeof(char) * 11);
        for (unsigned int i = 0; i < q; ++i) {
            count = 0;
            scanf("%s%d", target, &maxStep);
            for (unsigned int j = 0; j < n; ++j) {
                if (editDistance(strs[j], strlen(strs[j]), target, strlen(target)) <= maxStep) {
                    ++count;
                }
            }
            printf("%d\n", count);
        }
        for (unsigned int i = 0; i < n; ++i) {
            delete[] strs[i];
        }
        delete[] strs;
        delete[] target;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0899_H
