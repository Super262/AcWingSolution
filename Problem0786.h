//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0786_H
#define ACWINGSOLUTION_PROBLEM0786_H

#include <iostream>

using namespace std;

class Problem0786 {
public:
    void quick_partition(int *arr, const int start, const int end, const int k) {
        if (start >= end) {
            return;
        }
        int pivot = arr[start + (end - start) / 2];
        int i = start;
        int j = end;
        while (i <= j) {
            while (i <= j && arr[i] < pivot) {
                ++i;
            }
            while (i <= j && arr[j] > pivot) {
                --j;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }
        if (j - start + 1 >= k) {
            quick_partition(arr, start, j, k);
        } else if (i - start + 1 <= k) {
            quick_partition(arr, i, end, k - (i - start + 1));
        }
    }

    int main() {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        quick_partition(arr, 0, n - 1, k);
        cout << arr[k - 1] << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0786_H
