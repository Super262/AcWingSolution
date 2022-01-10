//
// Created by Fengwei Zhang on 1/8/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0196_H
#define ACWINGSOLUTION_PROBLEM0196_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0196 {
    // https://www.acwing.com/solution/content/11586/
private:
    int GetPrimes(const int n, int primes[], bool filtered[]) {  // 线性筛
        int cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[cnt++] = f;
            }
            for (int j = 0; primes[j] <= n / f; ++j) {
                filtered[primes[j] * f] = true;
                if (primes[j] % f == 0) {
                    break;
                }
            }
        }
        return cnt;
    }

    int GeneratePrimes(const int l, const int r, int primes[], const int n, bool filtered[]) {
        for (int i = 0; i < n; ++i) {
            long long p = primes[i];  // 避免溢出
            // 大于等于l的最小的p的倍数：(l + p - 1) / p * p
            for (auto num = max(2 * p, (l + p - 1) / p * p); num <= r; num += p) {  // 筛去[L, R]间p的倍数
                filtered[num - l] = true;  // 使用偏移量，因为num可能大于或等于数组长度
            }
        }
        int cnt = 0;
        for (int offset = 0; offset <= r - l; ++offset) {  // 记录[L, R]间所有质数
            if (filtered[offset] || offset + l < 2) {
                continue;
            }
            primes[cnt++] = offset + l;
        }
        return cnt;
    }

    int main() {
        const int N = 1000000;
        const int M = 50000;
        bool filtered[N + 1];
        int primes[N + 1];
        int l, r;
        while (scanf("%d%d", &l, &r) != -1) {
            memset(primes, 0, sizeof primes);
            memset(filtered, 0, sizeof filtered);
            auto cnt = GetPrimes(M, primes, filtered);  // 想复用primes，所以要每次重新预处理，复杂度可接受
            memset(filtered, 0, sizeof filtered);
            cnt = GeneratePrimes(l, r, primes, cnt, filtered);
            if (cnt < 2) {
                puts("There are no adjacent primes.");
            } else {
                int min_p = 0;
                int max_p = 0;
                for (int i = 0; i + 1 < cnt; ++i) {
                    int d = primes[i + 1] - primes[i];
                    if (d < primes[min_p + 1] - primes[min_p]) {
                        min_p = i;
                    }
                    if (d > primes[max_p + 1] - primes[max_p]) {
                        max_p = i;
                    }
                }
                printf("%d,%d are closest, %d,%d are most distant.\n",
                       primes[min_p], primes[min_p + 1],
                       primes[max_p], primes[max_p + 1]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0196_H
