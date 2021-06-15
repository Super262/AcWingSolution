//
// Created by Fengwei Zhang on 2021/6/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0890_H
#define ACWINGSOLUTION_PROBLEM0890_H

#include <iostream>

using namespace std;

class Problem0890 {
public:
    unsigned int countHelper(const unsigned int n, const unsigned int *primes, const unsigned int primesCount) {
        unsigned int result = 0;
        unsigned long long currentPrime;  // 当前选中的
        unsigned int selectedSetsCount;


        for (unsigned int s = 1; s < (1 << primesCount); ++s) {
            currentPrime = 1;
            selectedSetsCount = 0;
            for (unsigned int j = 0; j < primesCount; ++j) {
                if (!((s >> j) & 1)) {
                    continue;
                }
                currentPrime *= primes[j];
                if (currentPrime > n) {
                    currentPrime = 0;
                    break;
                }
                ++selectedSetsCount;
            }
            if (!currentPrime) {
                continue;
            }
            if (selectedSetsCount & 1) {
                result += n / (unsigned int) currentPrime;
            } else {
                result -= n / (unsigned int) currentPrime;
            }
        }
        return result;
    }

    int main() {
        unsigned int n, m;
        scanf("%d%d", &n, &m);
        auto primes = new unsigned int[m];
        for (unsigned int i = 0; i < m; ++i) {
            scanf("%d", &primes[i]);
        }
        printf("%d\n", countHelper(n, primes, (unsigned int) m));
        delete[] primes;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0890_H
