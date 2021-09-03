//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1052_H
#define ACWINGSOLUTION_PROBLEM1052_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1052 {
    // https://www.acwing.com/solution/content/55449/
private:
    const int N = 52;
    int dp[N][N]; // dp[i][j]：构造一个长度为i的密码，且后缀与模式串匹配的最大长度为j的方案数
    char temp[N];
    int nextStart[N];

    void buildNextStart(const int m) {
        int left = 0;
        int right = 1;
        while (right < m) {
            if (temp[right] == temp[left]) {
                ++left;
                nextStart[right] = left;
                ++right;
            } else if (left) {
                left = nextStart[left - 1];
            } else {
                nextStart[right] = 0;
                ++right;
            }
        }
    }

    int stateMachine(const int n, const int m) {
        buildNextStart(m);
        const int MOD = 1000000007;
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 遍历结果（密码字符串）第i位的所有可能取值（a-z）
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    auto u = j; // u是模版字符串下一个待匹配的字符的索引
                    while (u && temp[u] != ch) {
                        u = nextStart[u - 1];
                    }
                    if (temp[u] == ch) {
                        ++u;
                    }
                    // 新的结果字符串（长度为i + 1）的方案数包括原结果字符串（长度为i）的方案数
                    dp[i + 1][u] = (int) (((long) dp[i + 1][u] + dp[i][j]) % MOD);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            result = (int) (((long) result + dp[n][i]) % MOD);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        scanf("%s", temp);
        printf("%d\n", stateMachine(n, strlen(temp)));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1052_H
