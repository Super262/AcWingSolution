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
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int t = arr[i];
            int min_l = 0, max_l = result;
            while (min_l < max_l) {
                auto mid = min_l + (max_l - min_l + 1) / 2;  // 靠右端点，查找长度上界（即最大的i，使lisTail[i] < t）
                if (lis_tail[mid] >= t) {
                    max_l = mid - 1;
                } else {
                    min_l = mid;
                }
            }
            lis_tail[max_l + 1] = min(t, lis_tail[max_l + 1]);
            result = max(result, max_l + 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto arr = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longestIS(arr, n));
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0896_H
