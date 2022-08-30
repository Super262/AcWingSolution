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
private:
    static const int N = 20;
    int line[N][N];
    int dp[1 << N];
    pair<double, double> points[N];

    int cmpDouble(double a, double b) {
        if (fabs(a - b) < 1e-8) {
            return 0;
        } else if (a > b) {
            return 1;
        }
        return -1;
    }

    int stateCompress(const int n) {
        memset(dp, 0x3f, sizeof dp);
        memset(line, 0, sizeof line);
        for (int i = 0; i < n; ++i) {  // 预处理，计算穿过任意2点points[i]、points[j]的直线line[i][j]所穿过的点
            line[i][i] = 1 << i;  // 不要忘记这步初始化操作
            for (int j = 0; j < n; ++j) {
                auto x1 = points[i].first;
                auto y1 = points[i].second;
                auto x2 = points[j].first;
                auto y2 = points[j].second;
                if (cmpDouble(x1, x2) == 0) {
                    continue;
                }
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                if (a >= 0) {
                    continue;
                }
                double b = y1 / x1 - a * x1;
                int s = 0;
                for (int k = 0; k < n; ++k) {
                    auto x = points[k].first;
                    auto y = points[k].second;
                    if (cmpDouble(a * x * x + b * x, y) == 0) {
                        s += 1 << k;
                    }
                }
                line[i][j] = s;
            }
        }
        dp[0] = 0;
        for (int s = 0; s < (1 << n) - 1; ++s) {  // 从小到大枚举每个状态（穿过点的情况）
            int x1 = 0;
            while (x1 < n && ((s >> x1) & 1) != 0) {
                ++x1;
            }
            for (int x2 = 0; x2 < n; ++x2) {
                dp[s | line[x1][x2]] = min(dp[s | line[x1][x2]], dp[s] + 1);
            }
        }
        return dp[(1 << n) - 1];
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, m;
            scanf("%d%d", &n, &m);
            for (int i = 0; i < n; ++i) {
                scanf("%lf%lf", &points[i].first, &points[i].second);
            }
            printf("%d\n", stateCompress(n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0524_H
