//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1052_H
#define ACWINGSOLUTION_PROBLEM1052_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1052 {
    // dp[i][j]代表的方案：构造长度为i的密码，后缀与模式串匹配的最大长度为j
    // https://www.acwing.com/solution/content/55449/
private:
    void buildFail(const char s[], const int n, int fail[]) {
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < n) {
            if (s[l] == s[r]) {
                ++l;
                fail[r] = l;
                ++r;
            } else if (l != 0) {
                l = fail[l - 1];
            } else {
                fail[r] = 0;
                ++r;
            }
        }
    }

    int stateMachine(const int n, const char str[]) {
        const int MOD = 1000000007;
        const int m = (int) strlen(str);
        int fail[m];
        int dp[n + 1][m + 1];
        int next_state[m + 1][26];
        memset(dp, 0, sizeof dp);
        memset(next_state, 0, sizeof next_state);
        buildFail(str, m, fail);
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {  // 预计算状态转移路径
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                auto u = i; // u是i的后继状态
                while (u && ch != str[u]) {
                    u = fail[u - 1];
                }
                if (str[u] == ch) {
                    ++u;
                }
                next_state[i][ch - 'a'] = u;
            }
        }
        for (int length = 0; length < n; ++length) {  // 循环当前的密码长度，探索下一位
            for (int i = 0; i < m; ++i) {  // 遍历后缀和模式串可能的匹配长度
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    auto u = next_state[i][ch - 'a'];
                    dp[length + 1][u] = (int) (((long) dp[length + 1][u] + dp[length][i]) % MOD);
                }
            }
        }
        int result = 0;
        for (int j = m - 1; j >= 0; --j) { // 统计所有与str匹配的长度小于m的方案
            result = (int) (((long long) result + dp[n][j]) % MOD);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        char str[51];
        scanf("%s", str);
        printf("%d\n", stateMachine(n, str));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1052_H
