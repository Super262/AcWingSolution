//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0487_H
#define ACWINGSOLUTION_PROBLEM0487_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0487 {
private:
    int knapsack(const vector<pair<int, int>> &masters,
                 const vector<vector<pair<int, int>>> &accessories,
                 const int &m) {
        int dp[m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i < (int) masters.size(); ++i) {
            if (masters[i].first == 0) {
                continue;
            }
            for (int j = m; j >= 0; --j) {
                for (int s = 0; s < (1 << accessories[i].size()); ++s) {
                    auto v = masters[i].first;
                    auto vw = masters[i].second;
                    for (int k = 0; k < (int) accessories[i].size(); ++k) {
                        if (((s >> k) & 1) == 0) {
                            continue;
                        }
                        v += accessories[i][k].first;
                        vw += accessories[i][k].second;
                    }
                    if (j >= v) {
                        dp[j] = max(dp[j], dp[j - v] + vw);
                    }
                }
            }
        }
        return dp[m];
    }

    int main() {
        int m;
        int n;
        scanf("%d%d", &m, &n);
        vector<pair<int, int>> masters(n + 1, pair<int, int>(0, 0));
        vector<vector<pair<int, int>>> accessories(n + 1, vector<pair<int, int>>());
        for (int i = 1; i <= n; ++i) {
            int v, w, q;
            scanf("%d%d%d", &v, &w, &q);
            if (q) {
                accessories[q].emplace_back(pair<int, int>(v, w * v));
            } else {
                masters[i].first = v;
                masters[i].second = w * v;
            }
        }
        printf("%d\n", knapsack(masters, accessories, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0487_H
