//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0896_H
#define ACWINGSOLUTION_PROBLEM0896_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0896 {
private:
    int longestIS(const int arr[], const int n) {
        int lis_tail[n + 1];  // lis_tail[i]表示长度为i的LIS中最小的末尾元素
        memset(lis_tail, 0x7f, sizeof lis_tail);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto t = arr[i];
            int l = 0;
            auto r = ans;
            while (l < r) {
                auto mid = l + (r - l + 1) / 2;  // 靠右端点，查找长度上界（即最大的i，使lisTail[i] < t）
                if (lis_tail[mid] >= t) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            lis_tail[l + 1] = min(t, lis_tail[l + 1]);
            ans = max(ans, l + 1);
        }
        return ans;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longestIS(arr, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0896_H
