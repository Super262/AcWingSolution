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
public:
    void buildNextStart(const char *str, const int N, int *nextStart) {
        nextStart[0] = 0;
        int now = 0;
        int i = 1;
        while (i < N) {
            if (str[i] == str[now]) {
                ++now;
                nextStart[i] = now;
                ++i;
            } else if (now) {
                now = nextStart[now - 1];
            } else {
                nextStart[i] = 0;
                ++i;
            }
        }
    }

    // 不要搞混"索引"和"长度"！
    int countMatched(const char *T, const int M, const int *nextStart, const int N) {
        const int MOD = 1000000007;
        auto dp = new int *[N + 1];
        for (int i = 0; i <= N; ++i) {
            dp[i] = new int[M + 1];
            memset(dp[i], 0, sizeof(int) * (M + 1));
        }
        // dp[i][j]：构造一个长度为i的密码，且后缀与模式串匹配的最大长度为j的方案
        dp[0][0] = 1;

        // i，j分别表示密码和模式串中下一个待匹配字符的索引
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    int u = j;  // u是模版字符串下一个待匹配的字符的索引
                    while (u && T[u] != ch) {
                        u = nextStart[u - 1];
                    }
                    if (T[u] == ch) {
                        ++u;
                    }
                    dp[i + 1][u] = (int) (((long) dp[i + 1][u] + dp[i][j]) % MOD);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < M; ++i) {
            result = (int) (((long) result + dp[N][i]) % MOD);
        }
        for (int i = 0; i <= N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        auto s = new char[56];
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int m = (int) strlen(s);
        auto nextStart = new int[m];
        buildNextStart(s, m, nextStart);
        printf("%d\n", countMatched(s, m, nextStart, n));
        delete[] s;
        delete[] nextStart;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1052_H
