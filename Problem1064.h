//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM1064_H
#define ACWINGSOLUTION_PROBLEM1064_H

#include <vector>
#include <iostream>

using namespace std;

class Problem1064 {
public:
    int countOnes(const int state, const int n) {
        int result = 0;
        for (int offset = 0; offset < n; ++offset) {
            if ((state >> offset) & 1) {
                ++result;
            }
        }
        return result;
    }

    bool noAdjacentOnes(const int state, const int n) {
        for (int offset = 0; offset < n - 1; ++offset) {
            if (((state >> offset) & 1) && ((state >> (offset + 1)) & 1)) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> getPossiblePrev(const vector<int> &states, const int N) {
        vector<vector<int>> prevStates(states.size(), vector<int>());
        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < states.size(); ++j) {
                if ((states[i] & states[j]) || !noAdjacentOnes(states[i] | states[j], N)) {
                    continue;
                }
                prevStates[i].emplace_back(j);
            }
        }
        return prevStates;
    }

    long long solutionsNum(const int N, const int M) {
        vector<int> states;
        vector<int> onesCount;
        for (int s = 0; s < (1 << N); ++s) {
            if (noAdjacentOnes(s, N)) {
                states.emplace_back(s);
                onesCount.emplace_back(countOnes(s, N));
            }
        }
        vector<vector<int>> prevStates = getPossiblePrev(states, N);

        // dp[i][k][s] 表示前i行共摆放了k个国王、第i行摆放方案为s（1表示摆放，0表示空白）的方案数量
        vector<vector<vector<long long>>> dp(N + 2, vector<vector<long long>>(M + 1, vector<long long>(1 << N, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= N + 1; ++i) {
            for (int kingsNum = 0; kingsNum <= M; ++kingsNum) {
                for (int k = 0; k < states.size(); ++k) {
                    for (int preStateIdx : prevStates[k]) {
                        if (onesCount[k] > kingsNum) {
                            continue;
                        }
                        dp[i][kingsNum][states[k]] += dp[i - 1][kingsNum - onesCount[k]][states[preStateIdx]];
                    }
                }
            }
        }
        return dp[N + 1][M][0];
    }

    int main() {
        int N, M;
        scanf("%d%d", &N, &M);
        printf("%lld\n", solutionsNum(N, M));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1064_H
