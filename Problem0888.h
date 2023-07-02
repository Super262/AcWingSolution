//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0888_H
#define ACWINGSOLUTION_PROBLEM0888_H

#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Problem0888 {
    // https://www.acwing.com/solution/content/26559/
public:
    void collectPrimesFromOneToN(int n, int *primes, int &count) {
        bool *isFiltered = new bool[n + 1];
        count = 0;
        memset(isFiltered, 0, sizeof(bool));
        for (int num = 2; num <= n; ++num) {
            if (!isFiltered[num]) {
                primes[count++] = num;
            }
            for (int j = 0; primes[j] <= n / num; ++j) {
                isFiltered[primes[j] * num] = true;
                if (num % primes[j] == 0) {
                    break;
                }
            }
        }
        delete[] isFiltered;
    }

    int countOccurrenceInFactorialN(int n, int prime) {
        int frequency = 0;
        while (n) {
            frequency += n / prime;
            n /= prime;
        }
        return frequency;
    }

    vector<int> multiplyBigInt(const vector<int> &a, int b) {
        vector<int> result;
        int remains = 0;
        for (int digit : a) {
            remains += digit * b;
            result.emplace_back(remains % 10);
            remains /= 10;
        }
        while (remains) {
            result.emplace_back(remains % 10);
            remains /= 10;
        }
        return result;
    }

    vector<int> combinatorialNumber(int a, int b) {
        int *primeFactorOfA = new int[a + 1];
        int *factorFrequencyOfResult = new int[a + 1];
        int factorsCount = 0;
        memset(factorFrequencyOfResult, 0, sizeof(int));
        memset(primeFactorOfA, 0, sizeof(int));
        collectPrimesFromOneToN(a, primeFactorOfA, factorsCount);
        for (int i = 0; i < factorsCount; ++i) {
            factorFrequencyOfResult[i] = countOccurrenceInFactorialN(a, primeFactorOfA[i]) -
                                         countOccurrenceInFactorialN(b, primeFactorOfA[i]) -
                                         countOccurrenceInFactorialN(a - b, primeFactorOfA[i]);
        }
        vector<int> result(1, 1);
        for (int i = 0; i < factorsCount; ++i) {
            for (int f = 0; f < factorFrequencyOfResult[i]; ++f) {
                result = multiplyBigInt(result, primeFactorOfA[i]);
            }
        }
        reverse(result.begin(), result.end());
        delete[] primeFactorOfA;
        delete[] factorFrequencyOfResult;
        return result;
    }

    int main() {
        int a, b;
        scanf("%d%d", &a, &b);
        vector<int> result = combinatorialNumber(a, b);
        for (const int &digit : result) {
            printf("%d", digit);
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0888_H
