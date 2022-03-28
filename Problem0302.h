//
// Created by Fengwei Zhang on 3/27/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0302_H
#define ACWINGSOLUTION_PROBLEM0302_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0302 {
    // 本题凸包边缘的斜率不再单调、新加入的点的横坐标单调递增
    // 查询最近斜率时，只能用二分法；插入新点时，将队尾不在凸包上的点全部删掉
    // https://www.acwing.com/solution/content/68118/
    // 队列中的点(Xi, Yi)与待加入的点(x, y)构成的直线的斜率随i增大而递增
    // double可以保存比long long更大的数
private:
    long long minCost(const long long st[], const long long sc[], const int n, const int s) {
        int q[n + 1];
        int hh = 0, tt = -1;
        long long f[n + 1];
        f[0] = 0;
        q[++tt] = 0;
        for (int i = 1; i <= n; ++i) {
            auto l = hh;
            auto r = tt;
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (f[q[mid + 1]] - f[q[mid]] > (st[i] + s) * (sc[q[mid + 1]] - sc[q[mid]])) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            auto j = q[r];
            f[i] = f[j] - (st[i] + s) * sc[j] + st[i] * sc[i] + s * sc[n];
            while (hh < tt &&
                   (double) (f[q[tt]] - f[q[tt - 1]]) * (double) (sc[i] - sc[q[tt]]) >=
                   (double) (f[i] - f[q[tt]]) * (double) (sc[q[tt]] - sc[q[tt - 1]])) {
                --tt;
            }
            q[++tt] = i;
        }
        return f[n];
    }

    int main() {
        int n, s;
        scanf("%d%d", &n, &s);
        long long st[n + 1];
        long long sc[n + 1];
        memset(st, 0, sizeof st);
        memset(sc, 0, sizeof sc);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &st[i], &sc[i]);
            st[i] += st[i - 1];
            sc[i] += sc[i - 1];
        }
        printf("%lld\n", minCost(st, sc, n, s));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0302_H
