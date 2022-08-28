//
// Created by Fengwei Zhang on 2021/6/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0104_H
#define ACWINGSOLUTION_PROBLEM0104_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0104 {
public:
    long minDistance(int *coordinates, const int N) {
        long result = 0;
        sort(coordinates, coordinates + N);
        const int mid = N >> 1;  // 无论mid偏左或偏右（长度为偶数），结果都是正确的
        for (int i = 0; i < N; ++i) {
            result += abs(coordinates[i] - coordinates[mid]);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int coordinates[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &coordinates[i]);
        }
        printf("%ld\n", minDistance(coordinates, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0104_H
