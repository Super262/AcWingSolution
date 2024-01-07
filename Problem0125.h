//
// Created by Fengwei Zhang on 2021/6/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0125_H
#define ACWINGSOLUTION_PROBLEM0125_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0125
{
private:
    struct WSPair
    {
        int weight;
        int strength;

        bool operator<(const WSPair &b) const
        {
            return weight + strength < b.weight + b.strength;
        }
    };

    int min_risk(WSPair *cows, const int &n)
    {
        if (!cows || n == 0)
        {
            return 0;
        }
        sort(cows, cows + n);
        auto result = -cows[0].strength; // 注意result的初始值！
        for (int i = 1, weight_sum = cows[0].weight; i < n; ++i)
        {
            result = max(result, weight_sum - cows[i].strength);
            weight_sum += cows[i].weight;
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        WSPair cows[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &cows[i].weight, &cows[i].strength);
        }
        printf("%d\n", min_risk(cows, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0125_H
