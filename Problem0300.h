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
    // f[i] = min{f[i], (f[j] + st[i] * (sc[i] - sc[j]) + S * (sc[N] - sc[j])}
    // sc：c的前缀和；st：t的前缀和
private:
    long long minCost(const int st[], const int sc[], const int n, const int s) {
        long long f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] = min(f[i], f[j] + (long long) st[i] * (sc[i] - sc[j]) + (long long) s * (sc[n] - sc[j]));
            }
        }
        return f[n];
    }

    int main() {
        int n, s;
        scanf("%d%d", &n, &s);
        int sc[n + 1];
        int st[n + 1];
        memset(sc, 0, sizeof sc);
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &st[i], &sc[i]);
            st[i] += st[i - 1];
            sc[i] += sc[i - 1];
        }
        printf("%lld\n", minCost(st, sc, n, s));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0300_H
