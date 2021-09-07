//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM1068_H
#define ACWINGSOLUTION_PROBLEM1068_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1068 {
    // https://www.acwing.com/solution/content/15641/
    // 化环为链，大大降低复杂度
private:
    const int N = 200;
    int items[2 * N + 1];
    int dpMax[2 * N + 1][2 * N + 1];
    int dpMin[2 * N + 1][2 * N + 1];

    void rangeModel(const int n) {
        memset(dpMax, -0x3f, sizeof dpMax);
        memset(dpMin, 0x3f, sizeof dpMin);
        for (int i = 1; i <= 2 * n; ++i) {
            dpMin[i][i] = 0;
            dpMax[i][i] = 0;
            items[i] += items[i - 1];
        }
        for (int length = 1; length <= n; ++length) {
            for (int start = 1; start + length - 1 <= 2 * n; ++start) {
                int end = start + length - 1;
                for (int mid = start; mid < end; ++mid) {
                    dpMax[start][end] = max(dpMax[start][end],
                                            dpMax[start][mid] + dpMax[mid + 1][end] + items[end] - items[start - 1]);
                    dpMin[start][end] = min(dpMin[start][end],
                                            dpMin[start][mid] + dpMin[mid + 1][end] + items[end] - items[start - 1]);
                }
            }
        }
        int resMin = 0x3f3f3f3f;
        int resMax = -0x3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            resMin = min(resMin, dpMin[i][i + n - 1]);
            resMax = max(resMax, dpMax[i][i + n - 1]);
        }
        printf("%d\n%d\n", resMin, resMax);
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
            items[i + n] = items[i];
        }
        rangeModel(n);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1068_H
