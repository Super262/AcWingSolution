//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0790_H
#define ACWINGSOLUTION_PROBLEM0790_H

#include <iostream>

using namespace std;

class Problem0790 {
public:
    long double getCubicRoot(long double x) {
        long double left = min(-1.0l, x);
        long double right = max(1.0l, x);
        long double mid;
        while (right - left > 1e-8) {
            mid = left + (right - left) / 2;
            if (mid * mid * mid >= x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

    int main() {
        long double x;
        cin >> x;
        printf("%.6Lf\n", getCubicRoot(x));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0790_H
