//
// Created by Fengwei Zhang on 2021/7/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0187_H
#define ACWINGSOLUTION_PROBLEM0187_H

#include <iostream>

using namespace std;

class Problem0187 {
private:
    static const int N = 50;
    int lis_head[N];
    int lds_head[N];
    int height[N];

    void dfs(const int n, const int idx, const int lis_cnt, const int lds_cnt, int &result) {
        // 剪枝：当前结果比已有结果差，直接返回
        if (lis_cnt + lds_cnt >= result) {
            return;
        }
        if (idx == n) {
            result = lis_cnt + lds_cnt;
            return;
        }
        // 尝试在所有的LIS中寻找插入位置或建立新的LIS
        int k = -1;
        for (int i = 0; i < lis_cnt; ++i) {
            if (lis_head[i] <= height[idx]) {
                continue;
            }
            if (k == -1 || lis_head[i] < lis_head[k]) {
                k = i;
            }
        }
        if (k == -1) {
            auto t = lis_head[lis_cnt];
            lis_head[lis_cnt] = height[idx];
            dfs(n, idx + 1, lis_cnt + 1, lds_cnt, result);
            lis_head[lis_cnt] = t;
        } else {
            auto t = lis_head[k];
            lis_head[k] = height[idx];
            dfs(n, idx + 1, lis_cnt, lds_cnt, result);
            lis_head[k] = t;
        }
        // 尝试在所有的LDS中寻找插入位置或建立新的LDS
        k = -1;
        for (int i = 0; i < lds_cnt; ++i) {
            if (lds_head[i] >= height[idx]) {
                continue;
            }
            if (k == -1 || lds_head[i] > lds_head[k]) {
                k = i;
            }
        }
        if (k == -1) {
            auto t = lds_head[lds_cnt];
            lds_head[lds_cnt] = height[idx];
            dfs(n, idx + 1, lis_cnt, lds_cnt + 1, result);
            lds_head[lds_cnt] = t;
        } else {
            auto t = lds_head[k];
            lds_head[k] = height[idx];
            dfs(n, idx + 1, lis_cnt, lds_cnt, result);
            lds_head[k] = t;
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
