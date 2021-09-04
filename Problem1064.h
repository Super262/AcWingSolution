//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM1064_H
#define ACWINGSOLUTION_PROBLEM1064_H

#include <vector>
#include <iostream>

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
        vector<vector<int>> result(states.size(), vector<int>());
        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < states.size(); ++j) {
                if ((states[i] & states[j]) || hasContinousOnes(states[i] | states[j], n)) {
                    continue;
                }
                result[i].emplace_back(j);
            }
        }
        return result;
    }

    long long stateCompression(const int n, const int k) {
        vector<int> currentS;
        vector<int> numOfOnes;
        // 预处理出第i行所有可能的合法状态
        for (int s = 0; s < (1 << n); ++s) {
            if (hasContinousOnes(s, n)) {
                continue;
            }
            currentS.emplace_back(s);
            numOfOnes.emplace_back(countOnes(s, n));
        }
        // 获取第(i-1)行的所有可能状态
        auto prevSIdxes = getPossiblePrevIdxes(currentS, n);
        // dp[i][k][s] 表示前i行共摆放了k个国王、第i行摆放方案为s（1表示摆放，0表示空白）的方案数量
        vector<vector<vector<long long>>> dp(n + 2, vector<vector<long long>>(k + 1, vector<long long>(1 << n, 0)));
        // 不要忘记初始化
        dp[0][0][0] = 1;
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int curSIdx = 0; curSIdx < currentS.size(); ++curSIdx) {
                    for (int prevSIdx: prevSIdxes[curSIdx]) {
                        if (numOfOnes[curSIdx] + numOfOnes[prevSIdx] > j) {
                            continue;
                        }
                        dp[i][j][currentS[curSIdx]] += dp[i - 1][j - numOfOnes[curSIdx]][currentS[prevSIdx]];
                    }
                }
            }
        }
        return dp[n + 1][k][0];
    }

    int main() {
        int N, K;
        scanf("%d%d", &N, &K);
        printf("%lld\n", stateCompression(N, K));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1064_H
