//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0790_H
#define ACWINGSOLUTION_PROBLEM0790_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0790
{
private:
    long double myCubicRoot(const long double &x)
    {
        auto l = min(x, -1.0l); // 牢记左、右起点的临界值
        auto r = max(x, 1.0l);
        while (l < r)
        {
            auto mid = l + (r - l) / 2;
            auto t = mid * mid * mid;
            if (fabs(t - x) < 1e-10)
            {
                return mid;
            }
            else if (t > x)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }

    int main()
    {
        long double x;
        scanf("%Lf", &x);
        printf("%.6Lf\n", myCubicRoot(x));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0790_H
