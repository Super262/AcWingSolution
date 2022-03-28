//
// Created by Fengwei Zhang on 3/27/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0301_H
#define ACWINGSOLUTION_PROBLEM0301_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0301 {
    // https://www.acwing.com/solution/content/35208/
    // f[i] = min{f[j] + st[i] * (sc[i] - sc[j]) + S * (sc[N] - sc[j])}
    //      = st[i] * sc[i] + S * sc[N] + min{f[j] - sc[j] * (S + st[i])}
    // 对于f[j] - st[i] * sc[j] - S * sc[j]，令f[j] = y(j), sc[j] = x(j), k = S + st[i]
    // 则f[i] = st[i] * sc[i] + S * sc[N] + min{y - k * x}，即f[i] = st[i] * sc[i] + S * sc[N] + min{b}
    // 因此，求一个点(x, y)，使当前斜率为k的直线在y轴上的截距b最小
    // 由于本题凸包边缘的斜率单调递增、新加入的点的横坐标也一定单调递增，所以我们应使用滑动窗口优化搜索
private:
    long long minCost(const long long st[], const long long sc[], const int n, const int s) {
        int q[n + 1];
        int hh = 0, tt = -1;
        long long f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        q[++tt] = 0;
        for (int i = 1; i <= n; ++i) {
            // 获得斜率需要2个点，队列长度要大于1
            while (hh < tt && f[q[hh + 1]] - f[q[hh]] <= (s + st[i]) * (sc[q[hh + 1]] - sc[q[hh]])) {
                ++hh;
            }
            f[i] = st[i] * sc[i] + s * sc[n] + (f[q[hh]] - sc[q[hh]] * (s + st[i]));
            while (hh < tt &&
                   (f[q[tt]] - f[q[tt - 1]]) * (sc[i] - sc[q[tt]]) >= (f[i] - f[q[tt]]) * (sc[q[tt]] - sc[q[tt - 1]])) {
                --tt;
            }
            q[++tt] = i;
        }
        return f[n];
    }

    int main() {
        int n, s;
        scanf("%d%d", &n, &s);
        long long sc[n + 1];
        long long st[n + 1];
        memset(sc, 0, sizeof sc);
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &st[i], &sc[i]);
            st[i] += st[i - 1];
            sc[i] += sc[i - 1];
        }
        printf("%lld\n", minCost(st, sc, n, s));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0301_H
