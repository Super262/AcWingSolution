//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0154_H
#define ACWINGSOLUTION_PROBLEM0154_H

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

class Problem0154 {
public:
    void printMinInWindow(const vector<int> &arr, const long k) {
        if (k >= arr.size()) {
            printf("%d\n", *min_element(arr.begin(), arr.end()));
            return;
        }
        deque<int> q;
        long = 0;
        auto p = arr.begin();
        while (p != arr.end()) {
            while (currentWindowSize < k) {
                while (!q.empty() && q.back() > *p) { // 注意：边界条件应是">"，不是">="
                    q.pop_back();
                }
                q.emplace_back(*p);
                ++;
                ++p;
            }
            printf("%d ", q.front());
            if (q.front() == *(p - k)) {
                q.pop_front();
            }
            --;
        }
        printf("\n");
    }

    void printMaxInWindow(const vector<int> &arr, const long k) {
        if (k >= arr.size()) {
            printf("%d\n", *max_element(arr.begin(), arr.end()));
            return;
        }
        deque<int> q;
        long currentWindowSize = 0;
        auto p = arr.begin();
        while (p != arr.end()) {
            while (currentWindowSize < k) {
                while (!q.empty() && q.back() < *p) {  // 注意：边界条件应是"<"，不是"<="
                    q.pop_back();
                }
                q.emplace_back(*p);
                ++currentWindowSize;
                ++p;
            }
            printf("%d ", q.front());
            if (q.front() == *(p - k)) {
                q.pop_front();
            }
            --currentWindowSize;
        }
        printf("\n");
    }

    int main() {
        long n, k;
        scanf("%ld%ld", &n, &k);
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
