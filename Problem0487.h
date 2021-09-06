//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0487_H
#define ACWINGSOLUTION_PROBLEM0487_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Problem0487 {
private:
    int knapsack(const int m,
                 const vector<pair<int, int>> &masters,
                 const vector<vector<pair<int, int>>> &accessories) {
        vector<int> dp(m + 1, 0);
        for (int i = 1; i < masters.size(); ++i) {
            if (masters[i].first == 0) {
                continue;
            }
            for (int j = m; j >= 0; --j) {
                // 利用二进制进行压缩
                for (int k = 0; k < (1 << accessories[i].size()); ++k) {
                    auto v = masters[i].first;
                    auto wv = masters[i].second;
                    for (int u = 0; u < accessories[i].size(); ++u) {
                        if (((k >> u) & 1) == 0) {
                            continue;
                        }
                        v += accessories[i][u].first;
                        wv += accessories[i][u].second;
                    }
                    if (j >= v) {
                        dp[j] = max(dp[j - v] + wv, dp[j]);
                    }
                }
            }
        }
        return dp[m];
    }

    int main() {
        int m, n;
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
        printf("%d\n", knapsack(m, masters, accessories));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0487_H
