//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0896_H
#define ACWINGSOLUTION_PROBLEM0896_H

#include <iostream>

using namespace std;

class Problem0896 {
public:
    unsigned int longestIS(const int *arr, const unsigned int n) {
        unsigned int result = 0;
        auto *lastItemInIS = new int[n + 1];
        lastItemInIS[0] = -2e9;
        for (unsigned int i = 0; i < n; ++i) {
            unsigned int left = 0;
            unsigned int right = result;
            // 二分搜索小于arr[i]的最大值
            while (left < right) {
                unsigned int mid = (left + right + 1) >> 1;
                if (lastItemInIS[mid] >= arr[i]) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            lastItemInIS[right + 1] = arr[i];
            result = max(result, right + 1);
        }
        delete[] lastItemInIS;
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto arr = new int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longestIS(arr, n));
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0896_H
