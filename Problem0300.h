//
// Created by Fengwei Zhang on 2021/7/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0300_H
#define ACWINGSOLUTION_PROBLEM0300_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0300 {
    // https://www.acwing.com/solution/content/13391/
    // f[i]：将前i个任务分成若干批执行的最小费用（添加启动时间的影响S到后续所有任务）
    // f[i] = min{f[i], (f[j] + sumT[i] * (sumC[i] - sumC[j]) + S * (sumC[N] - sumC[j])}
private:
    long long minCost(const int t_prefix[], const int c_prefix[], const int n, const int s) {
        long long f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] = min(f[i],
                           f[j] + (long long) t_prefix[i] * (c_prefix[i] - c_prefix[j]) +
                           (long long) s * (c_prefix[n] - c_prefix[j]));
            }
        }
        return f[n];
    }

    int main() {
        int n, s;
        scanf("%d%d", &n, &s);
        int c_sum[n + 1];
        int t_sum[n + 1];
        memset(c_sum, 0, sizeof c_sum);
        memset(t_sum, 0, sizeof t_sum);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &t_sum[i], &c_sum[i]);
            t_sum[i] += t_sum[i - 1];
            c_sum[i] += c_sum[i - 1];
        }
        printf("%lld\n", minCost(t_sum, c_sum, n, s));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0300_H
