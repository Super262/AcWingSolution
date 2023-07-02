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
        bool filtered[n + 1];
        count = 0;
        memset(filtered, 0, sizeof(bool) * (n + 1));
        for (int num = 2; num <= n; ++num) {
            if (!filtered[num]) {
                primes[count++] = num;
            }
            for (int j = 0; j < count && primes[j] <= n / num; ++j) {
                filtered[primes[j] * num] = true;
                if (num % primes[j] == 0) {
                    break;
                }
            }
        }
    }

    int countOccurrence(int n, int factor) {
        int answer = 0;
        while (n) {
            answer += n / factor;
            n /= factor;
        }
        return answer;
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
        int primeFactors[a + 1];
        int factorFrequency[a + 1];
        int numOfFactors = 0;
        memset(factorFrequency, 0, sizeof(int) * (a + 1));
        collectPrimesFromOneToN(a, primeFactors, numOfFactors);
        for (int i = 0; i < numOfFactors; ++i) {
            factorFrequency[i] = countOccurrence(a, primeFactors[i]) -
                                         countOccurrence(b, primeFactors[i]) -
                                         countOccurrence(a - b, primeFactors[i]);
        }
        vector<int> result(1, 1);
        for (int i = 0; i < numOfFactors; ++i) {
            for (int f = 0; f < factorFrequency[i]; ++f) {
                result = multiplyBigInt(result, primeFactors[i]);
            }
        }
        reverse(result.begin(), result.end());
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
