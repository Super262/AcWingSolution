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
    void buildNext(const char s[], const int &n, int next[]) {
        next[0] = 0;
        int left = 0;
        int right = 1;
        while (right < n) {
            if (s[left] == s[right]) {
                ++left;
                next[right] = left;
                ++right;
            } else if (left != 0) {
                left = next[left - 1];
            } else {
                next[right] = 0;
                ++right;
            }
        }
    }

    int stateMachine(const int &n, const char str[], const int &m, int nextStart[]) {
        const int MOD = 1000000007;
        buildNext(str, m, nextStart);
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {  // 循环当前的密码长度，探索下一位
            for (int j = 0; j < m; ++j) {
                // 遍历结果（密码字符串）第i位的所有可能取值（a-z）
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    auto u = j; // u是str下一个待匹配的字符的索引
                    while (u && ch != str[u]) {
                        u = nextStart[u - 1];
                    }
                    if (str[u] == ch) {
                        ++u;
                    }
                    // 新的结果字符串（长度为i + 1）的方案数包括原结果字符串（长度为i）的方案数
                    dp[i + 1][u] = (int) (((long) dp[i + 1][u] + dp[i][j]) % MOD);
                }
            }
        }
        long result = 0;
        for (int i = m - 1; i >= 0; --i) { // 统计所有与str匹配的长度小于m的方案
            result += dp[n][i];
            result %= MOD;
        }
        return (int) result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        char str[51];
        scanf("%s", str);
        const int m = (int) strlen(str);
        int nextStart[m];
        printf("%d\n", stateMachine(n, str, m, nextStart));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1052_H
