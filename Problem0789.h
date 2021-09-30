//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0789_H
#define ACWINGSOLUTION_PROBLEM0789_H

#include <iostream>

using namespace std;

class Problem0789 {
private:
    int arr[100000];
    int n;

    void printRange(const int target) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            auto mid = left + ((right - left) >> 1);
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (arr[left] != target) {
            printf("-1 -1\n");
            return;
        }
        printf("%d ", left);
        left = 0;
        right = n - 1;
        while (left < right) {
            auto mid = left + ((right - left + 1) >> 1);
            if (arr[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if (arr[left] != target) {
            printf("-1 -1\n");
            return;
        }
        printf("%d\n", right);
    }

    int main() {
        int q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < q; ++i) {
            int t;
            scanf("%d", &t);
            printRange(t);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0789_H
