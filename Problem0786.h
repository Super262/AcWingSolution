//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0786_H
#define ACWINGSOLUTION_PROBLEM0786_H

#include <iostream>

using namespace std;

class Problem0786 {
public:
    int arr[100000];
    int n;

    void quickPartition(const int start, const int end, const int k) {
        if (start >= end) {
            return;
        }
        auto pivot = arr[start + (end - start) / 2];
        auto left = start - 1;
        auto right = end + 1;
        while (left < right) {
            while (arr[++left] < pivot);
            while (arr[--right] > pivot);
            if (left < right) {
                swap(arr[left], arr[right]);
            }
        }
        if (right - start + 1 >= k) {
            quickPartition(start, right, k);
        } else {
            quickPartition(right + 1, end, k - (right - start + 1));
        }
    }

    int main() {
        int k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        quickPartition(0, n - 1, k);
        printf("%d\n", arr[k - 1]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0786_H
