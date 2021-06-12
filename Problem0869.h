//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0869_H
#define ACWINGSOLUTION_PROBLEM0869_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0869 {
public:
    void getDivisors(const int n, int *divisors, int &count) {
        count = 0;
        for (int f = 1; f <= n / f; ++f) {
            if (n % f) {
                continue;
            }
            divisors[count++] = f;
            if (f != n / f) {
                divisors[count++] = n / f;
            }
        }
        sort(divisors, divisors + count);
    }

    int main() {
        int m;
        scanf("%d", &m);
        int n;
        int *divisors = new int[100];
        int count = 0;
        while (m--) {
            scanf("%d", &n);
            getDivisors(n, divisors, count);
            for (int i = 0; i < count; ++i) {
                printf("%d ", divisors[i]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0869_H
