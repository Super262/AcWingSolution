//
// Created by Fengwei Zhang on 1/16/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1308_H
#define ACWINGSOLUTION_PROBLEM1308_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1308 {
    // https://www.acwing.com/solution/content/48085/
private:
    int quick_power(int a, int x, int m) {
        int res = 1;
        while (x) {
            if (x & 1) {
                res = (int) ((long long) res * a % m);
            }
            a = (int) ((long long) a * a % m);
            x >>= 1;
        }
        return res;
    }

    void Add(int res[], const int a[], const int b[], int n) {  // 数组低位存储数字低位
        for (int i = 0, t = 0; i < n; ++i) {
            t += a[i] + b[i];
            res[i] = t % 10;
            t /= 10;
        }
    }

    int main() {
        const int m = 1000;
        const int l = 150;
        int k, x;
        scanf("%d%d", &k, &x);
        auto n = quick_power(x, x, m);
        int c[n][k][l];  // 最大值为C(1000,100) = 10^143
        memset(c, 0, sizeof c);
        c[0][0][0] = 1;
        for (int i = 1; i <= n - 1; ++i) {
            for (int j = 0; j <= i && j <= k - 1; ++j) {
                if (j == 0) {
                    c[i][j][0] = 1;
                } else {
                    Add(c[i][j], c[i - 1][j], c[i - 1][j - 1], l);
                };
            }
        }
        auto it = l - 1;
        while (c[n - 1][k - 1][it] == 0) {
            --it;
        }
        while (it >= 0) {
            printf("%d", c[n - 1][k - 1][it]);
            --it;
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1308_H
