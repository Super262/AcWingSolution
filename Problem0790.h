//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0790_H
#define ACWINGSOLUTION_PROBLEM0790_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0790 {
public:
    long double cubicRoot(const long double x) {
        auto l = min(x, -1.0l);
        auto r = max(x, 1.0l);
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (fabs(mid * mid * mid - x) < 1e-8) {
                return mid;
            } else if (mid * mid * mid > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }

    int main() {
        long double x;
        scanf("%Lf", &x);
        printf("%.6Lf\n", cubicRoot(x));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0790_H
