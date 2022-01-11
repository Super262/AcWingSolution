//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0873_H
#define ACWINGSOLUTION_PROBLEM0873_H

#include <iostream>

using namespace std;

class Problem0873 {
private:
    int Euler(int n) {
        auto result = n;
        for (int f = 2; f <= n / f; ++f) {
            if (n % f) {
                continue;
            }
            while (n % f == 0) {
                n /= f;
            }
            result = result / f * (f - 1);  // 为保证结果正确，不使用 result * (1 - 1 / a)，这里都是整除运算；为避免溢出，先除后乘
        }
        if (n > 1) {
            result = result / n * (n - 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int m;
        while (n--) {
            scanf("%d", &m);
            printf("%d\n", Euler(m));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0873_H
