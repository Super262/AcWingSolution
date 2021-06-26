//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0787_H
#define ACWINGSOLUTION_PROBLEM0787_H

#include <iostream>

using namespace std;

class Problem0787 {
public:
    void merge_two_sides(const int left, const int mid, const int right, int arr[], int temp[]) {
        int tempTop = left;
        int pLeft = left;
        int pRight = mid + 1;
        while (pLeft <= mid && pRight <= right) {
            if (arr[pLeft] < arr[pRight]) {
                temp[tempTop++] = arr[pLeft++];
            } else {
                temp[tempTop++] = arr[pRight++];
            }
        }
        while (pLeft <= mid) {
            temp[tempTop++] = arr[pLeft++];
        }
        while (pRight <= right) {
            temp[tempTop++] = arr[pRight++];
        }
        for (int i = left; i <= right; ++i) {
            arr[i] = temp[i];
        }
    }

    void merge_sort(int arr[], int temp[], const int start, const int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        merge_sort(arr, temp, start, mid);
        merge_sort(arr, temp, mid + 1, end);
        merge_two_sides(start, mid, end, arr, temp);
    }

    int main() {
        int n;
        scanf("%d", &n);
        int *arr = new int[n];
        int *temp = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        merge_sort(arr, temp, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        delete[] temp;
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0787_H
