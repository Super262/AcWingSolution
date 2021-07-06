//
// Created by Fengwei Zhang on 2021/6/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0913_H
#define ACWINGSOLUTION_PROBLEM0913_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0913 {
public:
    long minWaitingTime(int *arr, const int N) {
        sort(arr, arr + N);
        long result = 0;
        for (int i = 0; i < N; ++i) {
            result += (long) arr[i] * (N - i - 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto arr = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%ld\n", minWaitingTime(arr, n));
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0913_H
