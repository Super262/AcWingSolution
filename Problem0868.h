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
    // 时间复杂度：O(n)
    int primesCount(const int n) {
        int result = 0;
        bool isFiltered[n + 1];
        int primes[n + 1];
        memset(isFiltered, 0, sizeof isFiltered);
        memset(primes, 0, sizeof primes);
        for (int f = 2; f <= n; ++f) {
            if (!isFiltered[f]) {
                primes[result++] = f;
            }
            for (int j = 0; primes[j] <= n / f; ++j) {
                isFiltered[primes[j] * f] = true;
                if (f % primes[j] == 0) {
                    break;
                }
            }
        }
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
