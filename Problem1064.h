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

    bool isInvalid(const int s, const int n) {  // 检测状态s是否非法
        // N < 2，此函数应仍能正确计算出结果，而不是直接返回false：(offset + 1) 可以大于 (N - 1)
        for (int offset = 0; offset < n; ++offset) {
            if (((s >> offset) & 1) && ((s >> (offset + 1)) & 1)) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> getPreStateIdx(const vector<int> &states, const int n) {
        vector<vector<int>> res(states.size(), vector<int>());
        for (int i = 0; i < (int) states.size(); ++i) {
            for (int j = 0; j < (int) states.size(); ++j) {
                if ((states[i] & states[j]) || isInvalid(states[i] | states[j], n)) {
                    continue;
                }
                res[i].emplace_back(j);
            }
        }
        return res;
    }

    long long stateCompression(const int n, const int k) {
        vector<int> states;
        vector<int> ones_num;
        // 预处理出第i行所有可能的合法状态
        for (int s = 0; s < (1 << n); ++s) {
            if (isInvalid(s, n)) {
                continue;
            }
            states.emplace_back(s);
            ones_num.emplace_back(countOnes(s, n));
        }
        // 获取第(i-1)行的所有可能状态
        const auto prev_state_idx = getPreStateIdx(states, n);
        // dp[i][k][s] 表示前i行共摆放了k个国王、第i行摆放方案为s（1表示摆放，0表示空白）的方案数量
        long long dp[2][k + 1][1 << n];
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;  // 不要忘记初始化
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j <= k; ++j) {
                memset(dp[i % 2][j], 0, sizeof dp[i % 2][j]);  // 滚动数组，不忘清零
                for (int cur = 0; cur < (int) states.size(); ++cur) {
                    for (int prev: prev_state_idx[cur]) {
                        if (ones_num[cur] + ones_num[prev] > j) {
                            continue;
                        }
                        dp[i % 2][j][states[cur]] += dp[(i - 1) % 2][j - ones_num[cur]][states[prev]];
                    }
                }
            }
        }
        return dp[(n + 1) % 2][k][0];  // 巧妙的做法：用n+1位保存结果
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%lld\n", stateCompression(n, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1064_H
