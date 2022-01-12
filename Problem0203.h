//
// Created by Fengwei Zhang on 1/11/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0203_H
#define ACWINGSOLUTION_PROBLEM0203_H

#include <iostream>

using namespace std;

class Problem0203 {
    // https://www.acwing.com/solution/content/79802/
private:
    int ExGcd(int a, int &x, int b, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = ExGcd(b, x1, a % b, y1);
        x = y1;
        y = x1 - a / b * y1;
        return d;
    }

    int main() {
        int a, b;
        scanf("%d%d", &a, &b);
        int x, y;
        ExGcd(a, x, b, y);
        printf("%d\n", (x % b + b) % b);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0203_H
