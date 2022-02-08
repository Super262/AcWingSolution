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
    int lds_tail[N];
    int lis_tail[N];
    int height[N];

    void dfs(const int n, const int idx, const int lds_cnt, const int lis_cnt, int &result) {
        // 剪枝：当前结果比已有结果差，直接返回
        if (lds_cnt + lis_cnt >= result) {
            return;
        }
        if (idx == n) {
            result = lds_cnt + lis_cnt;
            return;
        }
        // 尝试在所有的LDS中寻找插入位置或建立新的LDS
        int k = -1;
        for (int i = 0; i < lds_cnt; ++i) {
            if (lds_tail[i] <= height[idx]) {
                continue;
            }
            if (k == -1 || lds_tail[i] < lds_tail[k]) {
                k = i;
            }
        }
        if (k == -1) {
            auto t = lds_tail[lds_cnt];
            lds_tail[lds_cnt] = height[idx];
            dfs(n, idx + 1, lds_cnt + 1, lis_cnt, result);
            lds_tail[lds_cnt] = t;
        } else {
            auto t = lds_tail[k];
            lds_tail[k] = height[idx];
            dfs(n, idx + 1, lds_cnt, lis_cnt, result);
            lds_tail[k] = t;
        }
        // 尝试在所有的LIS中寻找插入位置或建立新的LIS
        k = -1;
        for (int i = 0; i < lis_cnt; ++i) {
            if (lis_tail[i] >= height[idx]) {
                continue;
            }
            if (k == -1 || lis_tail[i] > lis_tail[k]) {
                k = i;
            }
        }
        if (k == -1) {
            auto t = lis_tail[lis_cnt];
            lis_tail[lis_cnt] = height[idx];
            dfs(n, idx + 1, lds_cnt, lis_cnt + 1, result);
            lis_tail[lis_cnt] = t;
        } else {
            auto t = lis_tail[k];
            lis_tail[k] = height[idx];
            dfs(n, idx + 1, lds_cnt, lis_cnt, result);
            lis_tail[k] = t;
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
