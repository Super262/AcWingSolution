//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0524_H
#define ACWINGSOLUTION_PROBLEM0524_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

class Problem0524 {
    // https://www.acwing.com/solution/content/4028/
public:
    int cmpDouble(const double a, const double b) {
        const double EPS = 1e-8;
        if (fabs(a - b) < EPS) {
            return 0;
        }
        if (a < b) {
            return -1;
        }
        return 1;
    }

    int minCoveringLines(const pair<double, double> *points, const int N) {
        // path[i][j]表示穿过第i个点和第j个点的抛物线的状态值
        auto path = new int *[N];
        for (int x = 0; x < N; ++x) {
            path[x] = new int[N];
            memset(path[x], 0, sizeof(int) * N);
        }
        for (int i = 0; i < N; ++i) {
            path[i][i] = 1 << i;
            for (int j = 0; j < N; ++j) {
                double x1 = points[i].first;
                double y1 = points[i].second;
                double x2 = points[j].first;
                double y2 = points[j].second;

                // 两点横坐标相同，不能构成抛物线
                if (cmpDouble(x1, x2) == 0) {
                    continue;
                }
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);

                // a >= 0 时，不符合题意（与坐标轴平行的线或一次函数均不合题意）
                if (cmpDouble(a, 0) >= 0) {
                    continue;
                }

                double b = y1 / x1 - a * x1;

                // 遍历所有点，将当前抛物线穿过的点设置为"1"
                int s = 0;
                for (int k = 0; k < N; ++k) {
                    if (cmpDouble(a * points[k].first * points[k].first + b * points[k].first, points[k].second) == 0) {
                        s += 1 << k;
                    }
                }
                path[i][j] = s;
            }
        }
        const int LAST_STATE = 1 << N;
        auto dp = new int[LAST_STATE];
        memset(dp, 0x7f, LAST_STATE * sizeof(int));
        dp[0] = 0;
        // 遍历所有可能状态（从0到111...110），找到状态为"全1"时的最小值
        for (int s = 0; s < LAST_STATE - 1; ++s) {
            // 找到当前状态没有覆盖的一个点x1
            int x1;
            for (x1 = 0; x1 < N; ++x1) {
                if (((s >> x1) & 1) == 0) {
                    break;
                }
            }
            // 遍历所有经过x1的抛物线，计算结果
            for (int x2 = 0; x2 < N; ++x2) {
                dp[s | path[x1][x2]] = min(dp[s | path[x1][x2]], dp[s] + 1);
            }
        }
        for (int i = 0; i < N; ++i) {
            delete[] path[i];
        }
        delete[] path;
        int result = dp[LAST_STATE - 1];
        delete[] dp;
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, m;
            scanf("%d%d", &n, &m);
            auto points = new pair<double, double>[n];
            for (int i = 0; i < n; ++i) {
                scanf("%lf%lf", &points[i].first, &points[i].second);
            }
            printf("%d\n", minCoveringLines(points, n));
            delete[] points;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0524_H
