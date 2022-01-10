//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1289_H
#define ACWINGSOLUTION_PROBLEM1289_H

#include <iostream>

using namespace std;

class Problem1289 {
private:
    // 只有全等数列既是等差数列，又是等比数列
    // 时刻关注数据范围，避免发生溢出
    int qmi(int a, int k, const int m) {
        int result = 1;
        while (k) {
            if (k & 1) {
                result = (int) ((long long) result * a % m);
            }
            a = (int) ((long long) a * a % m);
            k >>= 1;
        }
        return result;
    }

    int main() {
        const int MOD = 200907;
        int t;
        scanf("%d", &t);
        while (t--) {
            int a, b, c, k;
            scanf("%d%d%d%d", &a, &b, &c, &k);
            if (2 * b == a + c) {
                printf("%lld\n", (a + (long long) (k - 1) * (b - a)) % MOD);
            } else {
                printf("%lld\n", (long long) a * qmi(b / a, k - 1, MOD) % MOD);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1289_H
