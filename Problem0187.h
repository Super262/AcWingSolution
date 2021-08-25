//
// Created by Fengwei Zhang on 2021/7/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0187_H
#define ACWINGSOLUTION_PROBLEM0187_H

#include <iostream>

using namespace std;

class Problem0187 {
private:
    const int N = 50;
    int lisHead[N];
    int ldsHead[N];
    int height[N];

    void dfs(const int n, const int numIdx, const int lisCount, const int ldsCount, int &result) {
        // 剪枝：当前结果比已有结果差，直接返回
        if (lisCount + ldsCount >= result) {
            return;
        }
        if (numIdx == n) {
            result = lisCount + ldsCount;
            return;
        }
        // 尝试在所有的LIS中寻找插入位置或建立新的LIS
        int k = -1;
        for (int i = 0; i < lisCount; ++i) {
            if (lisHead[i] <= height[numIdx]) {
                continue;
            }
            if (k == -1 || lisHead[i] < lisHead[k]) {
                k = i;
            }
        }
        if (k == -1) {
            auto t = lisHead[lisCount];
            lisHead[lisCount] = height[numIdx];
            dfs(n, numIdx + 1, lisCount + 1, ldsCount, result);
            lisHead[lisCount] = t;
        } else {
            auto t = lisHead[k];
            lisHead[k] = height[numIdx];
            dfs(n, numIdx + 1, lisCount, ldsCount, result);
            lisHead[k] = t;
        }
        // 尝试在所有的LDS中寻找插入位置或建立新的LDS
        k = -1;
        for (int i = 0; i < ldsCount; ++i) {
            if (ldsHead[i] >= height[numIdx]) {
                continue;
            }
            if (k == -1 || ldsHead[i] > ldsHead[k]) {
                k = i;
            }
        }
        if (k == -1) {
            auto t = ldsHead[ldsCount];
            ldsHead[ldsCount] = height[numIdx];
            dfs(n, numIdx + 1, lisCount, ldsCount + 1, result);
            ldsHead[ldsCount] = t;
        } else {
            auto t = ldsHead[k];
            ldsHead[k] = height[numIdx];
            dfs(n, numIdx + 1, lisCount, ldsCount, result);
            ldsHead[k] = t;
        }
    }

    int main() {
        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            for (int i = 0; i < n; ++i) {
                scanf("%d", &height[i]);
            }
            int result = n;
            dfs(n, 0, 0, 0, result);
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0187_H
