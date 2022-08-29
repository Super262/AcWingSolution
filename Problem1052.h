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
        int f[n + 1][m + 1];
        int next_matched_length[m + 1][26];
        memset(f, 0, sizeof f);
        memset(next_matched_length, 0, sizeof next_matched_length);
        buildFail(str, m, fail);
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {  // 预计算状态转移路径
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                auto u = i; // u是i的后继状态
                while (u && ch != str[u]) {
                    u = fail[u - 1];
                }
                if (str[u] == ch) {
                    ++u;
                }
                next_matched_length[i][ch - 'a'] = u;
            }
        }
        for (int l = 0; l < n; ++l) {  // 循环当前的密码长度，探索下一位
            for (int i = 0; i < m; ++i) {  // 遍历后缀和模式串可能的匹配长度
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    auto u = next_matched_length[i][ch - 'a'];
                    f[l + 1][u] = (int) (((long) f[l + 1][u] + f[l][i]) % MOD);
                }
            }
        }
        int ans = 0;
        for (int j = m - 1; j >= 0; --j) { // 统计所有与str匹配的长度小于m的方案
            ans = (int) (((long long) ans + f[n][j]) % MOD);
        }
        return ans;
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
