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
        int left = start;
        int right = end;
        int pivot = a[start + (end - start) / 2];
        while (left <= right) {
            while (left <= right && a[left] < pivot) {
                ++left;
            }
            while (left <= right && a[right] > pivot) {
                --right;
            }
            if (left <= right) {
                swap(a[left], a[right]);
                ++left;
                --right;
            }
        }
        quick_sort(a, start, right);
        quick_sort(a, left, end);
    }

    int main() {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        quick_sort(a, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0785_H