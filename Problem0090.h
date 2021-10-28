//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0090_H
#define ACWINGSOLUTION_PROBLEM0090_H

#include <iostream>

using namespace std;

class Problem0090 {
private:
    long long quickMul(long long a, long long b, const long long &p) {
        long long res = 0;
        while (b) {
            if (b & 1) {
                res = (res + a) % p;
            }
            a = (a + a) % p;
            b >>= 1;
        }
        return res;
    }

    int main() {
        long long a, b, p;
        scanf("%lld%lld%lld", &a, &b, &p);
        printf("%lld\n", quickMul(a, b, p));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0090_H
