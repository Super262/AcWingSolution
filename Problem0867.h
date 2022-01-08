//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0867_H
#define ACWINGSOLUTION_PROBLEM0867_H

#include <iostream>

using namespace std;

class Problem0867 {
public:
    void primeFactorizations(int n) {
        for (int f = 2; f <= n / f; ++f) {
            if (n % f == 0) {
                int s = 0;
                while (n % f == 0) {
                    n /= f;
                    ++s;
                }
                printf("%d %d\n", f, s);
            }
        }
        if (n > 1) {
            printf("%d %d\n", n, 1);
        }
        printf("\n");
    }

    int main() {
        int m;
        scanf("%d", &m);
        int n;
        while (m--) {
            scanf("%d", &n);
            primeFactorizations(n);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0867_H
