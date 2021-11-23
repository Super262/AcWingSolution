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
    void rangeModel(int items[], const int &n) {
        int dpMax[2 * n + 1][2 * n + 1];
        int dpMin[2 * n + 1][2 * n + 1];
        memset(dpMax, -0x3f, sizeof dpMax);
        memset(dpMin, 0x3f, sizeof dpMin);
        for (int i = 1; i <= 2 * n; ++i) {
            items[i] += items[i - 1];
            dpMin[i][i] = 0;
            dpMax[i][i] = 0;
        }
        for (int length = 2; length <= n; ++length) {
            for (int st = 1; st + length - 1 <= 2 * n; ++st) {
                auto ed = st + length - 1;
                for (int mid = st; mid < ed; ++mid) {
                    dpMax[st][ed] = max(dpMax[st][ed], dpMax[st][mid] + dpMax[mid + 1][ed] + items[ed] - items[st - 1]);
                    dpMin[st][ed] = min(dpMin[st][ed], dpMin[st][mid] + dpMin[mid + 1][ed] + items[ed] - items[st - 1]);
                }
            }
        }
        int resMin = 0x3f3f3f3f;
        int resMax = -0x3f3f3f3f;
        for (int st = 1; st + n - 1 <= 2 * n; ++st) {
            resMin = min(resMin, dpMin[st][st + n - 1]);
            resMax = max(resMax, dpMax[st][st + n - 1]);
        }
        printf("%d\n", resMin);
        printf("%d\n", resMax);
    }

    int main() {
        int n;
        scanf("%d", &n);
        int items[2 * n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
            items[i + n] = items[i];
        }
        rangeModel(items, n);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1068_H
