//
// Created by Fengwei Zhang on 1/17/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0215_H
#define ACWINGSOLUTION_PROBLEM0215_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0215 {
    // 利用整数除法的性质：https://www.acwing.com/solution/content/17858/
private:
    void GetMobius(const int n, int mobius[]) {
        int primes[n + 1];
        int p_cnt = 0;
        bool filtered[n + 1];
        memset(filtered, 0, sizeof filtered);
        mobius[1] = 1;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[p_cnt] = f;
                mobius[f] = -1;
                ++p_cnt;
            }
            for (int i = 0; i < p_cnt && primes[i] <= n / f; ++i) {
                auto t = primes[i] * f;
                filtered[t] = true;
                if (f % primes[i]) {
                    mobius[t] = mobius[f] * -1;
                } else {
                    mobius[t] = 0;
                    break;
                }
            }
        }
    }

    int main() {
        const int N = 50000;
        int mobius[N + 1];
        memset(mobius, 0, sizeof mobius);
        GetMobius(N, mobius);
        int prefix[N + 1];
        memset(prefix, 0, sizeof prefix);
        for (int i = 1; i <= N; ++i) {
            prefix[i] = prefix[i - 1] + mobius[i];
        }
        int t;
        scanf("%d", &t);
        while (t--) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            a /= d;
            b /= d;
            auto n = min(a, b);
            long long res = (long long) a * b;
            for (int l = 2, r; l <= n; l = r + 1) {
                r = min(n, min(a / (a / l), b / (b / l)));
                res += (prefix[r] - prefix[l - 1]) * ((long long) (a / l) * (b / l));
            }
            printf("%lld\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0215_H
