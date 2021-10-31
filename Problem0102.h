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
private:
    bool checkAvg(const int cows[], const int &n, const int &f, const double &avg) {
        double prefixSum[n + 1];
        memset(prefixSum, 0, sizeof prefixSum);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + (cows[i] - avg);
        }
        double preMin = prefixSum[0];
        for (int i = 1, j = f; j <= n; ++i, ++j) {  // 巧妙的解法：优化O(n^2)到O(n)
            preMin = min(preMin, prefixSum[i - 1]);
            if (prefixSum[j] - preMin >= 0) {
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
        while (r - l > 1e-5) {
            auto mid = l + (r - l) / 2;
            if (checkAvg(cows, n, f, mid)) {
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
