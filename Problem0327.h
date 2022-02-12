//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0327_H
#define ACWINGSOLUTION_PROBLEM0327_H

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Problem0327 {
    // https://www.acwing.com/solution/content/17569/
private:
    bool isValid(const int s, const int N) {
        // N < 2，此函数应仍能正确计算出结果，而不是直接返回true：(offset + 1) 可以大于 (N - 1)
        for (int offset = 0; offset < N; ++offset) {
            if (((s >> offset) & 1) && ((s >> (offset + 1)) & 1)) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> getPossiblePrev(const vector<int> &states) {
        vector<vector<int>> prev_states(states.size(), vector<int>());
        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < states.size(); ++j) {
                if (states[i] & states[j]) {
                    continue;
                }
                prev_states[i].emplace_back(j);
            }
        }
        return prev_states;
    }

    int solutionsNum(const int m, const int n, const int graph[]) {
        const int MOD = 1e8;
        vector<int> states;
        for (int s = 0; s < (1 << n); ++s) {
            if (!isValid(s, n)) {
                states.emplace_back(s);
            }
        }
        auto prev_states = getPossiblePrev(states);
        // dp[i][s] 表示前i行摆放完成、第i行摆放方案为s（0是空位，1是）的方案数
        int dp[2][1 << n];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;  // 初始值
        for (int i = 1; i <= m + 1; ++i) {
            memset(dp[i % 2], 0, sizeof dp[i % 2]);  // 滚动数组，不忘清零操作
            for (int k = 0; k < (int) states.size(); ++k) {
                if (states[k] & graph[i]) {
                    continue;
                }
                for (const auto &prev_idx: prev_states[k]) {
                    dp[i % 2][states[k]] = (int) (((long long) dp[i % 2][states[k]] +
                                                   dp[(i - 1) % 2][states[prev_idx]]) % MOD);
                }
            }
        }
        return dp[(m + 1) % 2][0];
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        int graph[m + 2];
        memset(graph, 0, sizeof graph);
        for (int i = 1; i <= m; ++i) {
            int t;
            for (int j = 0; j < n; ++j) {
                graph[i] *= 2;
                scanf("%d", &t);
                if (t == 0) {
                    ++graph[i];
                }
            }
        }
        printf("%d\n", solutionsNum(m, n, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0327_H
