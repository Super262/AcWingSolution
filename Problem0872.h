//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0872_H
#define ACWINGSOLUTION_PROBLEM0872_H

#include <iostream>

using namespace std;

class Problem0872 {
public:
    int gcd(int a, int b) {
        int t;
        while (b) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int a, b;
        while (n--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", gcd(a, b));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0872_H
