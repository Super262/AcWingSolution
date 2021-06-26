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
    unsigned int minDistance(int *coordinates, const unsigned int n) {
        if (n < 2) {
            return 0;
        }
        sort(coordinates, coordinates + n);
        const unsigned int m = (n >> 1);  // 若n为偶数，中位数偏左或偏右均可
        unsigned int result = 0;
        for (unsigned int i = 0; i < n; ++i) {
            result += abs(coordinates[i] - coordinates[m]);
        }
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto coordinates = new int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &coordinates[i]);
        }
        printf("%d\n", minDistance(coordinates, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0104_H
