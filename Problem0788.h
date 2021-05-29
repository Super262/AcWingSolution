//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0788_H
#define ACWINGSOLUTION_PROBLEM0788_H

#include <iostream>

using namespace std;

class Problem0788 {
public:
#include <iostream>

    using namespace std;

    unsigned long mergeSortToGetCount(int a[], int temp[], const unsigned long start, const unsigned long end) {
        // 返回值会超过int的表示范围
        if (start >= end) {
            return 0;
        }
        unsigned long mid = start + (end - start) / 2;
        unsigned long result = mergeSortToGetCount(a, temp, start, mid) + mergeSortToGetCount(a, temp, mid + 1, end);
        unsigned long pLeft = start;
        unsigned long pRight = mid + 1;
        unsigned long tempTop = start;
        while (pLeft <= mid && pRight <= end) {
            if (a[pLeft] <= a[pRight]) {  // 此处的边界条件应为"小于或等于"，而不是"小于"！
                temp[tempTop++] = a[pLeft++];
            } else {
                temp[tempTop++] = a[pRight++];
                result += mid - pLeft + 1;
            }
        }
        while (pLeft <= mid) {
            temp[tempTop++] = a[pLeft++];
        }
        while (pRight <= end) {
            temp[tempTop++] = a[pRight++];
            result += mid - pLeft + 1;
        }
        for (unsigned long i = start; i <= end; ++i) {
            a[i] = temp[i];
        }
        return result;
    }

    int main() {
        unsigned long n;
        cin >> n;
        int *arr = new int[n];
        int *temp = new int[n];
        for (unsigned long i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << mergeSortToGetCount(arr, temp, 0, n - 1) << endl;
        delete[] arr;
        delete[] temp;
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0788_H