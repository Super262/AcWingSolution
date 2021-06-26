//
// Created by Fengwei Zhang on 2021/6/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0125_H
#define ACWINGSOLUTION_PROBLEM0125_H

#include <iostream>
#include <algorithm>

using namespace std;

struct WSPair {
    int weight;
    int strength;

    bool operator<(const WSPair &b) const {
        return weight + strength < b.weight + b.strength;
    }
};

class Problem0125 {
public:
    int minRisk(WSPair *cows, const unsigned int n) {
        if (!cows || n == 0) {
            return 0;
        }
        sort(cows, cows + n);
        int result = -cows[0].strength;  // 注意result的初始值！
        int weightSum = cows[0].weight;
        for (unsigned int i = 1; i < n; ++i) {
            result = max(result, weightSum - cows[i].strength);
            weightSum += cows[i].weight;
        }
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto cows = new WSPair[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d%d", &cows[i].weight, &cows[i].strength);
        }
        printf("%d\n", minRisk(cows, n));
        delete[] cows;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0125_H
