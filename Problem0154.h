//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0154_H
#define ACWINGSOLUTION_PROBLEM0154_H

#include <iostream>

class Problem0154 {
private:
    const int N = 1000010;
    int arr[N];
    int dq[N];  // 双端队列保存元素的索引

    void printMaximalsInWindows(const int n, const int k) {
        int hh = 0, tt = -1;
        for (int i = 0; i < n; ++i) {
            while (hh <= tt && i - k + 1 > dq[hh]) {
                ++hh;
            }
            while (hh <= tt && arr[dq[tt]] <= arr[i]) {
                --tt;
            }
            dq[++tt] = i;
            if (i >= k - 1) {  // 当前遍历的数不足k时，无需输出
                printf("%d ", arr[dq[hh]]);
            }
        }
        printf("\n");
    }

    void printMinimalsInWindows(const int n, const int k) {
        int hh = 0, tt = -1;
        for (int i = 0; i < n; ++i) {
            while (hh <= tt && i - k + 1 > dq[hh]) {
                ++hh;
            }
            while (hh <= tt && arr[dq[tt]] >= arr[i]) {
                --tt;
            }
            dq[++tt] = i;
            if (i >= k - 1) {  // 当前遍历的数不足k时，无需输出
                printf("%d ", arr[dq[hh]]);
            }
        }
        printf("\n");
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printMinimalsInWindows(n, k);
        printMaximalsInWindows(n, k);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0154_H
