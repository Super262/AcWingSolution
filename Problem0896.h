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
        auto lisTail = new int[n + 1];
        int result = 0;
        lisTail[result] = -0x7f7f7f7f;
        for (int i = 0; i < n; ++i) {
            int t = arr[i];
            int minL = 0, maxL = result;
            while (minL < maxL) {
                int mid = minL + (maxL - minL + 1) / 2;  // 靠右端点，查找长度上界
                if (lisTail[mid] >= t) {
                    maxL = mid - 1;
                } else {
                    minL = mid;
                }
            }
            lisTail[maxL + 1] = t;
            result = max(result, maxL + 1);
        }
        delete[] lisTail;
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
