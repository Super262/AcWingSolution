//
// Created by Fengwei Zhang on 2021/6/1.
//

#ifndef ACWINGSOLUTION_PROBLEM0799_H
#define ACWINGSOLUTION_PROBLEM0799_H

#include <iostream>

using namespace std;

class Problem0799 {
public:
    const int N = 100010;
    int n;
    int arr[N];
    int count[N];

    int longestUniqueSeq() {
        if (n < 2) {
            return n;
        }
        int result = 0;
        for (int left = 0, right = 0; right < n; ++right) {
            ++count[arr[right]];
            while (left < right && count[arr[right]] > 1) {
                --count[arr[left]];
                ++left;
            }
            result = max(right - left + 1, result);
        }
        return result;
    }

    int main() {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longestUniqueSeq());
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0799_H
