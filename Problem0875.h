//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0875_H
#define ACWINGSOLUTION_PROBLEM0875_H

#include <iostream>

using namespace std;

class Problem0875 {
private:
    int QuickPower(int b, int p, const int m) {
        int result = 1;
        while (p) {
            if (p & 1) {
                result = (int) ((long long) result * b % m);
            }
            p >>= 1;
            b = (int) ((long long) b * b % m);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int b, p, m;
        while (n--) {
            scanf("%d%d%d", &b, &p, &m);
            printf("%d\n", QuickPower(b, p, m));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0875_H
