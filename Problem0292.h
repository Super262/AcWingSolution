//
// Created by Fengwei Zhang on 2021/7/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0292_H
#define ACWINGSOLUTION_PROBLEM0292_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0292 {
    // https://www.acwing.com/solution/content/12392/
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

    bool isValid(const int s, const int n) {
        // N < 3，此函数应仍能正确计算出结果，而不是直接返回true：(offset + 2) 可以大于 (N - 1)
        for (int i = 0; i < n; ++i) {
            if ((s >> i & 1) == 1 && ((s >> (i + 1) & 1) == 1 || (s >> (i + 2) & 1) == 1)) {
                return false;
            }
        }
        return true;
    }

    int maxSolution(const int graph[], const int n, const int m) {
        vector<int> states;
        vector<int> ones_num;
        for (int s = 0; s < (1 << m); ++s) {
            if (!isValid(s, m)) {
                continue;
            }
            states.emplace_back(s);
            ones_num.emplace_back(countOnes(s, m));
        }
        // dp[i][j][k]表示当前已经处理完前i行，第i行状态为k， 第(i - 1)行状态为j
        // 第i行和第(i - 1)行受第(i - 2)行的影响，所以我们遍历第(i - 2)行的状态值
        int dp[2][1 << m][1 << m];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n + 2; ++i) {
            for (int a = 0; a < (int) states.size(); ++a) {  // 枚举第i-2行状态
                for (int b = 0; b < (int) states.size(); ++b) {  // 枚举第i-1行状态
                    if (graph[i - 1] & states[b]) {  // 注意：这里不需要检测graph[i-2]和states[a]
                        continue;
                    }
                    for (int c = 0; c < (int) states.size(); ++c) {  // 枚举第i行状态
                        if (graph[i] & states[c]) {
                            continue;
                        }
                        if ((states[a] & states[b]) || (states[a] & states[c]) || (states[b] & states[c])) {
                            continue;
                        }
                        dp[i % 2][states[b]][states[c]] = max(dp[i % 2][states[b]][states[c]],
                                                              dp[(i - 1) % 2][states[a]][states[b]] + ones_num[c]);
                    }
                }
            }
        }
        return dp[(n + 2) % 2][0][0];  // 细节：n+2
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int graph[n + 3];
        memset(graph, 0, sizeof graph);
        char t;
        for (int i = 1; i <= n; ++i) {
            scanf("%c", &t);
            for (int j = 0; j < m; ++j) {
                graph[i] *= 2;
                scanf("%c", &t);
                if (t == 'H') {
                    ++graph[i];
                }
            }
        }
        printf("%d\n", maxSolution(graph, n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0292_H
