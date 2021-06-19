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

    unsigned long long mondrianDream(const unsigned int N,
                                     const unsigned int M,
                                     unsigned long long **dp,
                                     bool *hasContinuousZeros) {
        const unsigned long long lastState = (1 << N) - 1;
        memset(hasContinuousZeros, 0, sizeof(bool) * (lastState + 1));
        // 预计算
        unsigned int zerosSeqLen;
        for (unsigned long long s = 0; s <= lastState; ++s) {
            zerosSeqLen = 0;
            for (unsigned int offset = 0; offset < N; ++offset) {
                if ((s >> offset) & 1) {
                    if (zerosSeqLen & 1) {
                        break;
                    }
                    zerosSeqLen = 0;
                } else {
                    ++zerosSeqLen;
                }
            }
            if (zerosSeqLen & 1) {
                hasContinuousZeros[s] = true;
            }
        }
        dp[0][0] = 1;
        for (unsigned int i = 1; i <= M; ++i) {
            for (unsigned long long k = 0; k <= lastState; ++k) {
                dp[i][k] = 0;
                for (unsigned long long j = 0; j <= lastState; ++j) {
                    if ((k & j) || hasContinuousZeros[k | j]) {
                        continue;
                    }
                    dp[i][k] += dp[i - 1][j];
                }
            }
        }
        return dp[M][0];
    }

    int main() {
        const unsigned int maxN = 11;
        const unsigned int maxM = 11;
        const unsigned long long lastState = (1 << maxN) - 1;
        auto *hasContinuousZeros = new bool[lastState + 1];
        auto dp = new unsigned long long *[maxM + 1];
        for (unsigned int i = 0; i <= maxM; ++i) {
            dp[i] = new unsigned long long[lastState + 1];
        }
        unsigned int n;
        unsigned int m;
        while (true) {
            scanf("%d%d", &n, &m);
            if (!n && !m) {
                break;
            }
            printf("%lld\n", mondrianDream(n, m, dp, hasContinuousZeros));
        }
        delete[] hasContinuousZeros;
        for (unsigned int i = 0; i <= maxM; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0291_H
