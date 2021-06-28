//
// Created by Fengwei Zhang on 2021/6/3.
//

#ifndef ACWINGSOLUTION_PROBLEM0800_H
#define ACWINGSOLUTION_PROBLEM0800_H

#include <iostream>

using namespace std;

class Problem0800 {
public:
    int main() {
        unsigned long long n, m;
        int target;
        scanf("%lld%lld%d", &n, &m, &target);
        auto arr1 = new int[n];
        auto arr2 = new int[m];
        for (unsigned long long i = 0; i < n; ++i) {
            scanf("%d", &arr1[i]);
        }
        for (unsigned long long i = 0; i < m; ++i) {
            scanf("%d", &arr2[i]);
        }
        unsigned long long i = 0;
        unsigned long long j = m - 1;
        while (i < n && j >= 0) {
            if (arr1[i] + arr2[j] == target) {
                printf("%llu %llu\n", i, j);
                break;
            } else if (arr1[i] + arr2[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        delete[] arr1;
        delete[] arr2;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0800_H
