//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0785_H
#define ACWINGSOLUTION_PROBLEM0785_H

#include <iostream>

using namespace std;

class Problem0785 {
public:
    void quick_sort(int a[], const int start, const int end) {
        if (start >= end) {
            return;
        }
        int left = start - 1;
        int right = end + 1;
        int pivot = a[start + (end - start) / 2];  // 此处必须选择偏左的中点
        while (left < right) {
            while (a[++left] < pivot);
            while (a[--right] > pivot);
            if (left < right) {
                swap(a[left], a[right]);
            }
        }
        quick_sort(a, start, right);  // 此处一定要选择右指针
        quick_sort(a, right + 1, end);
    }

    int main() {
        int n;
        scanf("%d", &n);
        int *a = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        quick_sort(a, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0785_H
