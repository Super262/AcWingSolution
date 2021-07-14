//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0327_H
#define ACWINGSOLUTION_PROBLEM0327_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0327 {
    // https://www.acwing.com/solution/content/17569/
public:
    bool noAdjacentOnes(const int s, const int N) {
        // N < 2，此函数应仍能正确计算出结果，而不是直接返回true：(offset + 1) 可以大于 (N - 1)
        for (int offset = 0; offset < N; ++offset) {
            if (((s >> offset) & 1) && ((s >> (offset + 1)) & 1)) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> getPossiblePrev(const vector<int> &states) {
        vector<vector<int>> prevStates(states.size(), vector<int>());
        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < states.size(); ++j) {
                if (states[i] & states[j]) {
                    continue;
                }
                prevStates[i].emplace_back(j);
            }
        }
        return prevStates;
    }

    int solutionsNum(const int M, const int N, const vector<int> &graph) {
        const int MOD = 100000000;
        vector<int> states;
        for (int s = 0; s < (1 << N); ++s) {
            if (noAdjacentOnes(s, N)) {
                states.emplace_back(s);
            }
        }
        vector<vector<int>> prevStates = getPossiblePrev(states);

        // dp[i][s] 表示前i行摆放完成、第i行摆放方案为s（0是空位，1是）的方案数
        vector<vector<int>> dp(M + 2, vector<int>(1 << N, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= M + 1; ++i) {
            for (int k = 0; k < states.size(); ++k) {
                if (states[k] & graph[i]) {
                    continue;
                }
                for (int prevStateIdx : prevStates[k]) {
                    dp[i][states[k]] = (int) (((long long) dp[i][states[k]] + dp[i - 1][states[prevStateIdx]]) % MOD);
                }
            }
        }
        return dp[M + 1][0];
    }

    int main() {
        int M, N;
        scanf("%d%d", &M, &N);
        vector<int> graph(M + 2, 0);
        for (int i = 1; i <= M; ++i) {
            int t;
            for (int j = 0; j < N; ++j) {
                graph[i] *= 2;
                scanf("%d", &t);
                if (t == 0) {
                    ++graph[i];
                }
            }
        }
        printf("%d\n", solutionsNum(M, N, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0327_H
