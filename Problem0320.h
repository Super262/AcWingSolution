//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0320_H
#define ACWINGSOLUTION_PROBLEM0320_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0320 {
private:
    int rangeModel(const int items[], const int &n) {
        int dp[2 * n + 1][2 * n + 1];
        memset(dp, 0, sizeof dp);
        for (int length = 3; length <= n + 1; ++length) {  // 注意length的起点和终点
            for (int st = 0; st + length - 1 <= 2 * n; ++st) {
                auto ed = st + length - 1;
                for (auto mid = st + 1; mid + 1 <= ed; ++mid) {
                    dp[st][ed] = max(dp[st][ed], dp[st][mid] + dp[mid][ed] + items[st] * items[mid] * items[ed]);
                }
            }
        }
        int result = 0;
        for (int st = 1; st + n <= 2 * n; ++st) {
            result = max(result, dp[st][st + n]);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int items[2 * n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
            items[i + n] = items[i];
        }
        printf("%d\n", rangeModel(items, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0320_H
