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
    void rangeModel(int items[], const int n) {
        int dp_max[2 * n + 1][2 * n + 1];
        int dp_min[2 * n + 1][2 * n + 1];
        memset(dp_max, -0x3f, sizeof dp_max);
        memset(dp_min, 0x3f, sizeof dp_min);
        for (int i = 1; i <= 2 * n; ++i) {
            items[i] += items[i - 1];
            dp_min[i][i] = 0;
            dp_max[i][i] = 0;
        }
        for (int l = 2; l <= n; ++l) {
            for (int st = 1; st + l - 1 <= 2 * n; ++st) {
                auto ed = st + l - 1;
                for (int mid = st; mid < ed; ++mid) {
                    dp_max[st][ed] = max(dp_max[st][ed], dp_max[st][mid] + dp_max[mid + 1][ed] + items[ed] - items[st - 1]);
                    dp_min[st][ed] = min(dp_min[st][ed], dp_min[st][mid] + dp_min[mid + 1][ed] + items[ed] - items[st - 1]);
                }
            }
        }
        int minimal = 0x3f3f3f3f;
        int maximal = -0x3f3f3f3f;
        for (int st = 1; st + n - 1 <= 2 * n; ++st) {
            minimal = min(minimal, dp_min[st][st + n - 1]);
            maximal = max(maximal, dp_max[st][st + n - 1]);
        }
        printf("%d\n", minimal);
        printf("%d\n", maximal);
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
