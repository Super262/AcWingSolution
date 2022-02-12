//
// Created by Fengwei Zhang on 2021/6/19.
//

#ifndef ACWINGSOLUTION_PROBLEM0291_H
#define ACWINGSOLUTION_PROBLEM0291_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0291 {
private:
    static const int N = 11;
    static const int M = 11;
    bool has_odd_zeroes[1 << N];
    long long dp[2][1 << N]; // dp[c][s]表示当前第c列（c >= 1）"横条"的摆放情况是s并在空白处填充"纵条"后的方案数

    void initialize(const int n) {
        const int LAST_S = (1 << n) - 1;
        for (int s = 0; s <= LAST_S; ++s) {
            int zeroes_count = 0;
            for (int i = 0; i < n; ++i) {
                if ((s >> i) & 1) {
                    if (zeroes_count & 1) {
                        break;
                    }
                    zeroes_count = 0;
                } else {
                    ++zeroes_count;
                }
            }
            if (zeroes_count & 1) {
                has_odd_zeroes[s] = true;
            }
        }
    }

    long long mondrianDream(const int n, const int m) {
        const int LAST_S = (1 << n) - 1;
        initialize(n);
        dp[0][0] = 1;
        for (int c = 1; c <= m; ++c) {
            memset(dp[c % 2], 0, sizeof dp[c % 2]); // 滚动数组，不忘清零
            for (int s1 = 0; s1 <= LAST_S; ++s1) {
                for (int s0 = 0; s0 <= LAST_S; ++s0) {
                    if ((s0 & s1) || has_odd_zeroes[s0 | s1]) {
                        continue;
                    }
                    dp[c % 2][s1] += dp[(c - 1) % 2][s0];
                }
            }
        }
        return dp[m % 2][0];
    }

    int main() {
        int n, m;
        while (true) {
            scanf("%d%d", &n, &m);
            if (n == 0 || m == 0) {
                break;
            }
            // 每次都有不同的输入，每次都需要初始化操作
            memset(has_odd_zeroes, 0, sizeof has_odd_zeroes);
            memset(dp, 0, sizeof dp);
            printf("%lld\n", mondrianDream(n, m));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0291_H
