//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0877_H
#define ACWINGSOLUTION_PROBLEM0877_H

#include <iostream>

using namespace std;

class Problem0877 {
public:
    int exgcd(int a, int &x, int b, int &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1, gcd;
        gcd = exgcd(b, x1, a % b, y1);
        x = y1;
        y = x1 - a / b * y1;
        return gcd;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int a, x, b, y;
        while (n--) {
            scanf("%d%d", &a, &b);
            exgcd(a, x, b, y);
            printf("%d %d\n", x, y);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0877_H
