//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0876_H
#define ACWINGSOLUTION_PROBLEM0876_H

#include <iostream>

using namespace std;

class Problem0876 {
public:
    unsigned long long qmi(unsigned long long b, unsigned long long p, const unsigned long long m) {
        unsigned long long result = 1;
        while (p) {
            if (p & 1) {
                result = result * b % m;
            }
            p >>= 1;
            b = b * b % m;
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int a, p;
        while (n--) {
            scanf("%d%d", &a, &p);
            if (a % p) {
                printf("%lld\n", qmi(a, p - 2, p));
            } else {
                puts("impossible");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0876_H
