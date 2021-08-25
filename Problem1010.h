//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1010_H
#define ACWINGSOLUTION_PROBLEM1010_H

#include <iostream>

using namespace std;

class Problem1010 {
    // 第一问：最长上升子序列
    // 第二问贪心流程：
    // 从前向后扫描每个数，对于每个数：
    // 1. 如果现有子序列的结尾都小于当前数，则创建新的子序列
    // 2. 将当前数放到结尾最小的子序列的后面，原结尾大于等于这个数
private:
    int lis(const int height[], const int n) {
        auto dp = new int[n];
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
        delete[] dp;
        return result;
    }

    int leastLISs(const int height[], const int n) {
        auto lisHead = new int[n];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int minHeadIdx = n + 1;
            for (int j = 0; j < count; ++j) {
                if (lisHead[j] < height[i]) {
                    continue;
                }
                if (minHeadIdx == n + 1 || lisHead[j] < lisHead[minHeadIdx]) {
                    minHeadIdx = j;
                }
            }
            if (minHeadIdx == n + 1) {
                lisHead[count++] = height[i];
            } else {
                lisHead[minHeadIdx] = height[i];
            }
        }
        delete[] lisHead;
        return count;
    }

    int main() {
        auto height = new int[1000];
        int n = 0;
        while (cin >> height[n]) {
            ++n;
        }
        printf("%d\n", lis(height, n));
        printf("%d\n", leastLISs(height, n));
        delete[] height;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1010_H
