//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0885_H
#define ACWINGSOLUTION_PROBLEM0885_H

#include <iostream>
#include <cstring>

using namespace std;


class Problem0885 {
public:
    int main() {
        const unsigned long long LENGTH = 2001;
        const unsigned long long M = 1e9 + 7;
        auto **combination = new unsigned long long *[LENGTH];
        for (unsigned long i = 0; i < LENGTH; ++i) {
            combination[i] = new unsigned long long[LENGTH];
            memset(combination[i], 0, sizeof(unsigned long long));
            combination[i][0] = 1;
        }
        for (unsigned long long i = 1; i < LENGTH; ++i) {
            for (unsigned long long j = 1; j < LENGTH; ++j) {
                combination[i][j] = (combination[i - 1][j] + combination[i - 1][j - 1]) % M;
            }
        }
        int n, a, b;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &a, &b);
            printf("%lld\n", combination[a][b]);
        }
        for (unsigned long i = 0; i < LENGTH; ++i) {
            delete[] combination[i];
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0885_H
