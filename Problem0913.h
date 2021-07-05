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
    unsigned long long minWaitingTime(unsigned int *costs, const int n) {
        sort(costs, costs + n);
        unsigned long long result = 0;
        for (int i = 0; i < n - 1; ++i) {
            result += ((unsigned long long) costs[i]) * (n - i - 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto costs = new unsigned int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &costs[i]);
        }
        printf("%lld\n", minWaitingTime(costs, n));
        delete[] costs;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0913_H
