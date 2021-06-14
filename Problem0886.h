//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0886_H
#define ACWINGSOLUTION_PROBLEM0886_H

#include <iostream>

using namespace std;

class Problem0886 {
public:
    unsigned int qmi(unsigned int a, unsigned int x, const unsigned int m) {
        unsigned int result = 1;
        while (x) {
            if (x & 1) {
                result = (unsigned int) ((unsigned long long) result * a % m);
            }
            x >>= 1;
            a = (unsigned int) ((unsigned long long) a * a % m);
        }
        return result;
    }

    int main() {
        const unsigned int N = 100000;
        const unsigned int M = 1e9 + 7;
        auto fact = new unsigned int[N + 1];
        auto inFact = new unsigned int[N + 1];
        fact[0] = inFact[0] = 1;
        for (unsigned int i = 1; i <= N; ++i) {
            fact[i] = (unsigned int) ((unsigned long long) fact[i - 1] * i % M);
            inFact[i] = (unsigned int) ((unsigned long long) inFact[i - 1] * qmi(i, M - 2, M) % M);
        }
        int n, a, b;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", (unsigned int) ((unsigned long long) fact[a] * inFact[b] % M * inFact[a - b] % M));
        }
        delete[] fact;
        delete[] inFact;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0886_H
