//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1010_H
#define ACWINGSOLUTION_PROBLEM1010_H

#include <iostream>

using namespace std;

class Problem1010 {
    // 第一问：最长下降子序列
    // 第二问贪心流程：
    // 从前向后扫描每个数，对于每个数：
    // 1. 如果现有子序列的结尾都小于当前数，则创建新的子序列
    // 2. 将当前数放到结尾最小的（最接近的）子序列的后面，原结尾大于等于这个数
private:
    int lds(const int height[], const int n) {
        int dp[n];
        int result = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = n - 1; j > i; --j) {
                if (height[j] > height[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int leastLDSs(const int height[], const int n) {
        int lis_head[n];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            auto min_head_idx = n + 1;
            for (int j = 0; j < count; ++j) {
                if (lis_head[j] < height[i]) {
                    continue;
                }
                if (min_head_idx == n + 1 || lis_head[j] < lis_head[min_head_idx]) {
                    min_head_idx = j;
                }
            }
            if (min_head_idx == n + 1) {
                lis_head[count] = height[i];
                ++count;
            } else {
                lis_head[min_head_idx] = height[i];
            }
        }
        return count;
    }

    int main() {
        int height[1000];
        int n = 0;
        while (scanf("%d", &height[n]) != -1) {
            ++n;
        }
        printf("%d\n", lds(height, n));
        printf("%d\n", leastLDSs(height, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1010_H
