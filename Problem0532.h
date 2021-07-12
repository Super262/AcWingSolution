//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0532_H
#define ACWINGSOLUTION_PROBLEM0532_H

#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class Problem0532 {
public:
    int uniqueElements(int *arr, const int N) {
        sort(arr, arr + N);
        int result = 0;
        auto dp = new int[arr[N - 1] + 1];
        memset(dp, 0, sizeof(int) * (arr[N - 1] + 1));
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            if (!dp[arr[i]]) {
                ++result;
            }
            for (int j = arr[i]; j <= arr[N - 1]; ++j) {
                dp[j] += dp[j - arr[i]];
            }
        }
        delete[] dp;
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            auto arr = new int[n];
            for (int i = 0; i < n; ++i) {
                scanf("%d", &arr[i]);
            }
            printf("%d\n", uniqueElements(arr, n));
            delete[] arr;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0532_H
