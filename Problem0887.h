//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0887_H
#define ACWINGSOLUTION_PROBLEM0887_H

#include <iostream>

using namespace std;

class Problem0887 {
    // 卢卡斯定理：https://www.acwing.com/solution/content/26553/
private:
    int quick_power(int a, int x, const int &m) {
        int result = 1;
        while (x) {
            if (x & 1) {
                result = (int) ((long long) result * a % m);
            }
            x >>= 1;
            a = (int) ((long long) a * a % m);
        }
        return result;
    }

    int Combination(const int n, const int m, const int p) {
        int result = 1;
        for (int i = 1, j = n; i <= m; ++i, --j) {
            result = (int) ((long long) result * j % p);
            result = (int) ((long long) result * quick_power(i, p - 2, p) % p);
        }
        return result;
    }

    int Lucas(const long long n, const long long m, const int p) {
        if (n < p && m < p) {
            return Combination((int) n, (int) m, p);
        }
        return (int) ((long long) Combination((int) (n % p), (int) (m % p), p) * Lucas(n / p, m / p, p) % p);
    }

    int main() {
        int n;
        scanf("%d", &n);
        long long a, b;
        int p;
        while (n--) {
            scanf("%lld%lld%d", &a, &b, &p);
            printf("%d\n", Lucas(a, b, p));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0887_H
