//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0868_H
#define ACWINGSOLUTION_PROBLEM0868_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0868 {
public:
    int primesCount(const int n) {
        int result = 0;
        bool *isNotPrime = new bool[n + 1];
        memset(isNotPrime, 0, (n + 1) * sizeof(bool));
        for (int f = 2; f <= n; ++f) {
            if (isNotPrime[f]) {
                continue;
            }
            ++result;
            for (int j = f * 2; j <= n; j += f) {
                isNotPrime[j] = true;
            }
        }
        delete[] isNotPrime;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%d", primesCount(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0868_H
