//
// Created by Fengwei Zhang on 2021/6/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0890_H
#define ACWINGSOLUTION_PROBLEM0890_H

#include <iostream>

using namespace std;

class Problem0890 {
private:
    int CountHelper(const int n, const int primes[], const int p_cnt) {
        int result = 0;
        long long current;
        int sets_count;
        for (int s = 1; s < (1 << p_cnt); ++s) {
            current = 1;
            sets_count = 0;
            for (int j = 0; j < p_cnt; ++j) {
                if (!((s >> j) & 1)) {
                    continue;
                }
                current *= primes[j];
                if (current > n) {
                    current = 0;
                    break;
                }
                ++sets_count;
            }
            if (!current) {
                continue;
            }
            if (sets_count & 1) {
                result += n / (int) current;
            } else {
                result -= n / (int) current;
            }
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int primes[m];
        for (int i = 0; i < m; ++i) {
            scanf("%d", &primes[i]);
        }
        printf("%d\n", CountHelper(n, primes, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0890_H
