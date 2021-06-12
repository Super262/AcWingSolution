//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0873_H
#define ACWINGSOLUTION_PROBLEM0873_H

#include <iostream>

using namespace std;


class Problem0873 {
public:
    unsigned long long euler(unsigned long long n) {
        unsigned long long result = n;
        for (unsigned long long f = 2; f <= n / f; ++f) {
            if (n % f) {
                continue;
            }
            while (n % f == 0) {
                n /= f;
            }
            result = result / f * (f - 1);
        }
        if (n > 1) {
            result = result / n * (n - 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        unsigned long long m;
        while (n--) {
            scanf("%lld", &m);
            printf("%lld\n", euler(m));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0873_H
