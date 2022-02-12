//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM1064_H
#define ACWINGSOLUTION_PROBLEM1064_H

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Problem1064 {
private:
    int countOnes(const int s, const int n) {
        int result = 0;
        for (int offset = 0; offset < n; ++offset) {
            if ((s >> offset) & 1) {
                ++result;
            }
        }
        return result;
    }

    bool hasContinousOnes(const int s, const int n) {
        // N < 2，此函数应仍能正确计算出结果，而不是直接返回false：(offset + 1) 可以大于 (N - 1)
        for (int offset = 0; offset < n; ++offset) {
            if (((s >> offset) & 1) && ((s >> (offset + 1)) & 1)) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> getPossiblePrevIdxes(vector<int> states, const int n) {
        vector<vector<int>> res(states.size(), vector<int>());
        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < states.size(); ++j) {
                if ((states[i] & states[j]) || hasContinousOnes(states[i] | states[j], n)) {
                    continue;
                }
                res[i].emplace_back(j);
            }
        }
        return res;
    }

    long long stateCompression(const int n, const int k) {
        vector<int> states;
        vector<int> num_of_ones;
        // 预处理出第i行所有可能的合法状态
        for (int s = 0; s < (1 << n); ++s) {
            if (hasContinousOnes(s, n)) {
                continue;
            }
            states.emplace_back(s);
            num_of_ones.emplace_back(countOnes(s, n));
        }
        // 获取第(i-1)行的所有可能状态
        auto prev_state = getPossiblePrevIdxes(states, n);
        // dp[i][k][s] 表示前i行共摆放了k个国王、第i行摆放方案为s（1表示摆放，0表示空白）的方案数量
        long long dp[n + 2][k + 1][1 << n];
        memset(dp, 0, sizeof dp);
        // 不要忘记初始化
        dp[0][0][0] = 1;
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int cur = 0; cur < states.size(); ++cur) {
                    for (int prev: prev_state[cur]) {
                        if (num_of_ones[cur] + num_of_ones[prev] > j) {
                            continue;
                        }
                        dp[i][j][states[cur]] += dp[i - 1][j - num_of_ones[cur]][states[prev]];
                    }
                }
            }
        }
        return dp[n + 1][k][0];  // 巧妙的做法：用n+1位保存结果
    }

    int main() {
        int N, K;
        scanf("%d%d", &N, &K);
        printf("%lld\n", stateCompression(N, K));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1064_H
