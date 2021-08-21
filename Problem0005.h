//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0005_H
#define ACWINGSOLUTION_PROBLEM0005_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0005 {
private:
    struct Item {
        int size;
        int value;
    };

    int dp[2010];

    int knapsack(const vector<Item> &items, const int packVolume) {
        for (auto item : items) {
            for (int j = packVolume; j >= item.size; --j) {
                dp[j] = max(dp[j], dp[j - item.size] + item.value);
            }
        }
        return dp[packVolume];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Item> items;
        for (int i = 0; i < n; ++i) {
            int s, v, num;
            scanf("%d%d%d", &s, &v, &num);
            int factor = 1;
            while (num >= factor) {
                Item item{factor * s, factor * v};
                items.emplace_back(item);
                num -= factor;
                factor <<= 1;
            }
            if (num > 0) {
                Item item{num * s, num * v};
                items.emplace_back(item);
            }
        }
        printf("%d\n", knapsack(items, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0005_H
