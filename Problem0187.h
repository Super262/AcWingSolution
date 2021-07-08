//
// Created by Fengwei Zhang on 2021/7/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0187_H
#define ACWINGSOLUTION_PROBLEM0187_H

#include <iostream>

using namespace std;

class Problem0187 {
public:
    void
    dfs(const int *arr, const int idx, const int N, int *lisTail, const int lisCount, int *ldsTail, const int ldsCount,
        int &result) {
        if (ldsCount + lisCount >= result) {
            return;
        }
        if (idx == N) {
            result = ldsCount + lisCount;
            return;
        }

        // 1. 尝试将当前数加到上升子序列中（尾部）
        int k = 0;
        while (k < lisCount && lisTail[k] >= arr[idx]) {
            ++k;
        }
        int t = lisTail[k];
        lisTail[k] = arr[idx];
        if (k >= lisCount) {
            dfs(arr, idx + 1, N, lisTail, lisCount + 1, ldsTail, ldsCount, result);
        } else {
            dfs(arr, idx + 1, N, lisTail, lisCount, ldsTail, ldsCount, result);
        }
        lisTail[k] = t;

        // 2. 尝试将当前数加到下降子序列中（尾部）
        k = 0;
        while (k < ldsCount && ldsTail[k] <= arr[idx]) {
            ++k;
        }
        t = ldsTail[k];
        ldsTail[k] = arr[idx];
        if (k >= ldsCount) {
            dfs(arr, idx + 1, N, lisTail, lisCount, ldsTail, ldsCount + 1, result);
        } else {
            dfs(arr, idx + 1, N, lisTail, lisCount, ldsTail, ldsCount, result);
        }
        ldsTail[k] = t;
    }

    int main() {
        auto arr = new int[50];
        auto lisTail = new int[50];
        auto ldsTail = new int[50];
        int n;
        while (true) {
            scanf("%d", &n);
            if (!n) {
                break;
            }
            for (int i = 0; i < n; ++i) {
                scanf("%d", &arr[i]);
            }
            int result = n;
            dfs(arr, 0, n, lisTail, 0, ldsTail, 0, result);
            printf("%d\n", result);
        }
        delete[] arr;
        delete[] lisTail;
        delete[] ldsTail;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0187_H
