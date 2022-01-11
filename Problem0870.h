//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0870_H
#define ACWINGSOLUTION_PROBLEM0870_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0870 {
public:
    void GetFactorsCount(int n, unordered_map<int, int> &prime_count) {
        for (int f = 2; f <= n / f; ++f) {
            while (n % f == 0) {
                n /= f;
                ++prime_count[f];
            }
        }
        if (n > 1) {
            ++prime_count[n];
        }
    }

    int main() {
        int m;
        scanf("%d", &m);
        int n;
        unordered_map<int, int> prime_count;
        while (m--) {
            scanf("%d", &n);
            GetFactorsCount(n, prime_count);
        }
        int result = 1;
        const int MOD = 1e9 + 7;
        for (const auto &p: prime_count) {
            result = (int) ((long long) result * (p.second + 1) % MOD);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0870_H
