//
// Created by Fengwei Zhang on 2021/6/19.
//

#ifndef ACWINGSOLUTION_PROBLEM0291_H
#define ACWINGSOLUTION_PROBLEM0291_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0291 {
public:
    void initialize(bool *hasOddZeroes, const int N) {
        const long long LAST_STATE = (1 << N) - 1;
        memset(hasOddZeroes, 0, sizeof(bool) * (LAST_STATE + 1));
        for (long long s = 0; s <= LAST_STATE; ++s) {
            int zeroesLen = 0;
            for (int i = 0; i < N; ++i) {
                if ((s >> i) & 1) {
                    if (zeroesLen & 1) {
                        break;
                    }
                    zeroesLen = 0;
                } else {
                    ++zeroesLen;
                }
            }
            if (zeroesLen & 1) {
                hasOddZeroes[s] = true;
            }
        }
    }

    long long mondrianDream(long long **dp, const int N, const int M, bool *hasOddZeroes) {
        initialize(hasOddZeroes, N);  // 每次要根据输入的不同的N重新初始化hasOddZeroes，因为N的变化会改变初始化操作中的移位次数
        const long long LAST_STATE = (1 << N) - 1;
        dp[0][0] = 1;
        for (int i = 1; i <= M; ++i) {
            for (long long s1 = 0; s1 <= LAST_STATE; ++s1) {
                dp[i][s1] = 0;
                for (long long s0 = 0; s0 <= LAST_STATE; ++s0) {
                    if ((s0 & s1) || hasOddZeroes[s0 | s1]) {
                        continue;
                    }
                    dp[i][s1] += dp[i - 1][s0];
                }
            }
        }
        return dp[M][0];
    }

    int main() {
        int maxN = 11;
        int maxM = 11;
        const long long lastState = (1 << maxN) - 1;
        auto *hasOddZeroes = new bool[lastState + 1];
        auto dp = new long long *[maxM + 1];
        for (unsigned int i = 0; i <= maxM; ++i) {
            dp[i] = new long long[lastState + 1];
        }
        int n;
        int m;
        while (true) {
            scanf("%d%d", &n, &m);
            if (!n && !m) {
                break;
            }
            printf("%lld\n", mondrianDream(dp, n, m, hasOddZeroes));
        }
        delete[] hasOddZeroes;
        for (unsigned int i = 0; i <= maxM; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0291_H
