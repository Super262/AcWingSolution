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
    long double getCubicRoot(const long double x) {
        auto left = min(-1.0l, x);
        auto right = max(1.0l, x);
        while (fabs(right - left) > 1e-8) {
            auto mid = left + (right - left) / 2;
            if (fabs(mid * mid * mid - x) < 1e-8) {
                return mid;
            } else if (mid * mid * mid > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

    int main() {
        long double x;
        scanf("%Lf", &x);
        printf("%.6Lf", getCubicRoot(x));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0790_H
