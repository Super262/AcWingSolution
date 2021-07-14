//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0292_H
#define ACWINGSOLUTION_PROBLEM0292_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0292 {
    // https://www.acwing.com/solution/content/12392/
public:
    int countOnes(const unsigned int s, const unsigned int N) {
        int result = 0;
        for (unsigned int offset = 0; offset < N; ++offset) {
            if ((s >> offset) & 1) {
                ++result;
            }
        }
        return result;
    }

    bool validState(const unsigned int s, const unsigned int N) {
        // N < 3，此函数应仍能正确计算出结果，而不是直接返回true：(offset + 2) 可以大于 (N - 1)
        for (unsigned int offset = 0; offset < N; ++offset) {
            const unsigned int a = (s >> offset) & 1;
            const unsigned int b = (s >> (offset + 1)) & 1;
            const unsigned int c = (s >> (offset + 2)) & 1;
            if (a + b + c > 1) {
                return false;
            }
        }
        return true;
    }

    int maxSolution(const vector<int> &graph, const int N, const int M) {
        vector<int> states;
        vector<int> onesNum;
        for (int s = 0; s < (1 << M); ++s) {
            if (!validState(s, M)) {
                continue;
            }
            states.emplace_back(s);
            onesNum.emplace_back(countOnes(s, M));
        }
        // dp[i][j][k]表示当前已经处理完前i行，第i行状态为k， 第(i - 1)行状态为j
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(1 << M, vector<int>(1 << M, 0)));
        for (int i = 1; i <= N + 2; ++i) {
            for (int a = 0; a < states.size(); ++a) {
                for (int b = 0; b < states.size(); ++b) {
                    if (graph[i - 1] & states[b]) {
                        continue;
                    }
                    for (int c = 0; c < states.size(); ++c) {
                        if (graph[i] & states[c]) {
                            continue;
                        }
                        if ((states[a] & states[b]) || (states[a] & states[c]) || (states[b] & states[c])) {
                            continue;
                        }
                        dp[i % 2][states[b]][states[c]] = max(dp[i % 2][states[b]][states[c]],
                                                              dp[(i - 1) % 2][states[a]][states[b]] + onesNum[c]);
                    }
                }
            }
        }
        return dp[(N + 2) % 2][0][0];
    }

    int main() {
        int N, M;
        scanf("%d%d", &N, &M);
        vector<int> graph(N + 3, 0);
        char t;
        for (int i = 1; i <= N; ++i) {
            scanf("%c", &t);
            for (int j = 0; j < M; ++j) {
                graph[i] *= 2;
                scanf("%c", &t);
                if (t == 'H') {
                    ++graph[i];
                }
            }
        }
        printf("%d\n", maxSolution(graph, N, M));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0292_H
