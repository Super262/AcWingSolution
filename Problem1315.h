//
// Created by Fengwei Zhang on 1/15/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1315_H
#define ACWINGSOLUTION_PROBLEM1315_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1315 {
    // https://www.acwing.com/solution/content/46130/
private:
    int GetPrimes(int n, int primes[], bool filtered[]) {
        int cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[cnt++] = f;
            }
            for (int i = 0; i < cnt && primes[i] <= n / f; ++i) {
                filtered[f * primes[i]] = true;
                if (f % primes[i] == 0) {
                    break;
                }
            }
        }
        return cnt;
    }

    int GetPower(int n, int p) {
        int s = 0;
        while (n) {
            s += n / p;
            n /= p;
        }
        return s;
    }

    void Multiply(int res[], int &length, int x) {
        int t = 0;
        for (int i = 0; i < length; ++i) {
            t += res[i] * x;
            res[i] = t % 10;
            t /= 10;
        }
        while (t) {
            res[length++] = t % 10;
            t /= 10;
        }
    }

    int Combination(int x, int y, int res[], const int primes[], int p_cnt) {
        int length = 0;
        res[length++] = 1;
        for (int i = 0; i < p_cnt; ++i) {
            auto p = primes[i];
            auto s = GetPower(x, p) - GetPower(y, p) - GetPower(x - y, p);
            while (s--) {
                Multiply(res, length, p);
            }
        }
        return length;
    }

    void Subtract(int a[], int al, const int b[], int bl) {
        for (int i = 0, t = 0; i < al; ++i) {
            a[i] -= t + b[i];
            if (a[i] < 0) {
                a[i] += 10;
                t = 1;
            } else {
                t = 0;
            }
        }
    }

    int main() {
        const int N = 10010;
        int primes[N];
        bool filtered[N];
        memset(filtered, 0, sizeof filtered);
        auto p_cnt = GetPrimes(N - 1, primes, filtered);
        int n, m;
        scanf("%d%d", &n, &m);
        int a[N], b[N];
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        auto al = Combination(n + m, m, a, primes, p_cnt);
        auto bl = Combination(n + m, n + 1, b, primes, p_cnt);
        Subtract(a, al, b, bl);
        auto k = al - 1;
        while (!a[k] && k > 0) {
            --k;
        }
        while (k >= 0) {
            printf("%d", a[k]);
            --k;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1315_H
