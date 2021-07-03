//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0896_H
#define ACWINGSOLUTION_PROBLEM0896_H

#include <iostream>

using namespace std;

class Problem0896 {
public:
    int longestIS(const int *arr, const int n) {
        auto lastItemInLS = new int[n + 1];
        int result = 0;
        lastItemInLS[0] = -2e9;
        for (int i = 0; i < n; ++i) {
            int left = 0;
            int right = result;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (lastItemInLS[mid] >= arr[i]) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            result = max(result, right + 1);
            lastItemInLS[right + 1] = arr[i];
        }
        delete[] lastItemInLS;
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
