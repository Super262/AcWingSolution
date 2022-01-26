//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0102_H
#define ACWINGSOLUTION_PROBLEM0102_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0102 {
    // https://www.acwing.com/solution/content/1148/
    // 注意2个浮点数的比较方式，注意"零值"的精度
private:
    bool CheckAvg(const int cows[], const int &n, const int &f, const double &avg) {
        double prefix_sum[n + 1];
        memset(prefix_sum, 0, sizeof prefix_sum);
        // 利用前缀和，巧妙的解法，类似滑动窗口：优化O(n^2)到O(n)
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + (cows[i] - avg);
        }
        double pre_min = prefix_sum[0];
        for (int i = 1, j = f; j <= n; ++i, ++j) {
            pre_min = min(pre_min, prefix_sum[i - 1]);  // 只检验最大值，只需比较和pre_min的差
            if (prefix_sum[j] - pre_min > 1e-9) {
                return true;
            }
        }
        return false;
    }

    int main() {
        int n, f;
        scanf("%d%d", &n, &f);
        int cows[n + 1];
        double l = 0, r = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &cows[i]);
            r = max(r, (double) cows[i]);
        }
        while (r - l > 1e-5) {  // 二分查找浮点数
            auto mid = l + (r - l) / 2;
            if (CheckAvg(cows, n, f, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d\n", (int) (r * 1000));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0102_H
