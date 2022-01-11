//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0200_H
#define ACWINGSOLUTION_PROBLEM0200_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0200 {
    // https://www.acwing.com/solution/content/12086/
private:
    struct Factor {
        int p, s;
    };

    int Gcd(int a, int b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int GetPrimes(const int n, int primes[], bool filtered[]) {
        int p_cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[p_cnt++] = f;
            }
            for (int i = 0; primes[i] <= n / f; ++i) {
                filtered[primes[i] * f] = true;
                if (f % primes[i] == 0) {
                    break;
                }
            }
        }
        return p_cnt;
    }

    int GetFactors(int n, const int primes[], const int p_cnt, Factor factors[]) {
        int f_cnt = 0;
        for (int i = 0; i < p_cnt && primes[i] <= n / primes[i]; ++i) {
            const auto &p = primes[i];
            if (n % p) {
                continue;
            }
            int s = 0;
            while (n % p == 0) {
                n /= p;
                ++s;
            }
            factors[f_cnt++] = {p, s};
        }
        if (n > 1) {  // 不要忘记这个特殊条件
            factors[f_cnt++] = {n, 1};
        }
        return f_cnt;
    }

    void GetDivisors(const int n,
                     int p,
                     const Factor factors[],
                     const int f_idx,
                     const int f_cnt,
                     int divisors[],
                     int &d_cnt) {
        if (f_idx == f_cnt) {
            divisors[d_cnt++] = p;
            return;
        }
        for (int i = 0; i <= factors[f_idx].s; ++i) {  // 判断条件是小于或等于
            GetDivisors(n, p, factors, f_idx + 1, f_cnt, divisors, d_cnt);
            p *= factors[f_idx].p;
        }
    }

    int main() {
        const int N = 50010;  // 输入最大值为2e9，最大因子约为50000
        const int K = 10;  // 2e9范围内，质因子个数最多为10
        int primes[N + 1];
        bool filtered[N + 1];
        Factor factors[K];
        int divisors[N];
        memset(primes, 0, sizeof primes);
        memset(filtered, 0, sizeof filtered);
        auto p_cnt = GetPrimes(N, primes, filtered);  // 获取1～sqrt(N)中的质因子
        int t;
        scanf("%d", &t);
        while (t--) {
            memset(factors, 0, sizeof factors);
            memset(divisors, 0, sizeof divisors);
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            auto f_cnt = GetFactors(d, primes, p_cnt, factors);
            int d_cnt = 0;
            GetDivisors(d, 1, factors, 0, f_cnt, divisors, d_cnt);
            int res = 0;
            for (int i = 0; i < d_cnt; ++i) {
                auto x = divisors[i];
                if (Gcd(a, x) == b && (long long) c * x / Gcd(c, x) == d) {
                    ++res;
                }
            }
            printf("%d\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0200_H
