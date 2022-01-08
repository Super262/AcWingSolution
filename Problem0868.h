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
    int PrimesCount(const int n) {
        bool is_filtered[n + 1];
        int primes[n + 1];
        int p_cnt = 0;
        memset(is_filtered, 0, sizeof is_filtered);
        memset(primes, 0, sizeof primes);
        for (int f = 2; f <= n; ++f) {
            if (!is_filtered[f]) {
                primes[p_cnt++] = f;
            }
            for (int j = 0; primes[j] <= n / f; ++j) {
                is_filtered[primes[j] * f] = true;
                if (f % primes[j] == 0) {
                    break;
                }
            }
        }
        return p_cnt;
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%d\n", PrimesCount(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0868_H
