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
public:
    int knapsackMaxValue(const vector<pair<int, int>> &master,
                         const vector<vector<pair<int, int>>> &accessory,
                         const int packVolume) {
        vector<int> dp(packVolume + 1, 0);
        for (int i = 1; i < master.size(); ++i) {
            if (!master[i].first) {
                continue;
            }
            for (int j = packVolume; j >= 0; --j) {
                for (int k = 0; k < (1 << accessory[i].size()); ++k) {
                    int v = master[i].first;
                    int w = master[i].second;
                    for (int u = 0; u < accessory[i].size(); ++u) {
                        if ((k >> u) & 1) {
                            v += accessory[i][u].first;
                            w += accessory[i][u].second;
                        }
                    }
                    if (j >= v) {
                        dp[j] = max(dp[j], dp[j - v] + w);
                    }
                }
            }
        }
        return dp[packVolume];
    }

    int main() {
        int packVolume;
        int n;
        scanf("%d%d", &packVolume, &n);
        vector<pair<int, int>> master(n + 1, pair<int, int>(0, 0));
        vector<vector<pair<int, int>>> accessory(n + 1, vector<pair<int, int>>());
        for (int i = 1; i <= n; ++i) {
            int v, w, q;
            scanf("%d%d%d", &v, &w, &q);
            if (q) {
                accessory[q].emplace_back(pair<int, int>(v, v * w));
            } else {
                master[i].first = v;
                master[i].second = v * w;
            }
        }
        printf("%d\n", knapsackMaxValue(master, accessory, packVolume));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0487_H
