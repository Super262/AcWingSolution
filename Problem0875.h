//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0875_H
#define ACWINGSOLUTION_PROBLEM0875_H

#include <iostream>

using namespace std;


class Problem0875 {
public:
    long long qmi(long long b, long long p, long long m) {
        long long result = 1;
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
        long long b, p, m;
        while (n--) {
            scanf("%lld%lld%lld", &b, &p, &m);
            printf("%lld\n", qmi(b, p, m));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0875_H
