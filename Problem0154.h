//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0154_H
#define ACWINGSOLUTION_PROBLEM0154_H

#include <vector>
#include <deque>
#include <iostream>

class Problem0154 {
public:
    void printMinInWindow(const vector<int> &arr, const int windowSize) {
        deque<int> q;
        for (int i = 0; i < arr.size(); ++i) {
            if (!q.empty() && q.front() < i - windowSize + 1) {
                q.pop_front();
            }
            while (!q.empty() && arr[q.back()] >= arr[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
            if (i >= windowSize - 1) {
                printf("%d ", arr[q.front()]);
            }
        }
        printf("\n");
    }

    void printMaxInWindow(const vector<int> &arr, const int windowSize) {
        deque<int> q;
        for (int i = 0; i < arr.size(); ++i) {
            if (!q.empty() && q.front() < i - windowSize + 1) {
                q.pop_front();
            }
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
            if (i >= windowSize - 1) {
                printf("%d ", arr[q.front()]);
            }
        }
        printf("\n");
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printMinInWindow(arr, k);
        printMaxInWindow(arr, k);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0154_H
