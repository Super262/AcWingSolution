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
    const int N = 11;
    const int M = 11;

    bool hasOddZeroes[1 << N];
    long long dp[M + 1][1 << N]; // dp[c][s]表示当前第c列（c >= 1）"横条"的摆放情况是s并在空白处填充"纵条"后的方案数

    void initialize(const int n) {
        const int LAST_S = (1 << n) - 1;
        for (int s = 0; s <= LAST_S; ++s) {
            int zeroesCount = 0;
            for (int i = 0; i < n; ++i) {
                if ((s >> i) & 1) {
                    if (zeroesCount & 1) {
                        break;
                    }
                    zeroesCount = 0;
                } else {
                    ++zeroesCount;
                }
            }
            if (zeroesCount & 1) {
                hasOddZeroes[s] = true;
            }
        }
    }

    long long mondrianDream(const int n, const int m) {
        const int LAST_S = (1 << n) - 1;
        initialize(n);
        dp[0][0] = 1;
        for (int c = 1; c <= m; ++c) {
            for (int s1 = 0; s1 <= LAST_S; ++s1) {
                for (int s0 = 0; s0 <= LAST_S; ++s0) {
                    if ((s0 & s1) || hasOddZeroes[s0 | s1]) {
                        continue;
                    }
                    dp[c][s1] += dp[c - 1][s0];
                }
            }
        }
        return dp[m][0];
    }

    int main() {
        int n, m;
        while (true) {
            scanf("%d%d", &n, &m);
            if (n == 0 || m == 0) {
                break;
            }
            // 每次都有不同的输入，每次都需要初始化操作
            memset(hasOddZeroes, 0, sizeof hasOddZeroes);
            memset(dp, 0, sizeof dp);
            printf("%lld\n", mondrianDream(n, m));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0291_H
