//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0323_H
#define ACWINGSOLUTION_PROBLEM0323_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0323 {
    // 保证所有边至少有1个顶点被选择
    // https://www.acwing.com/solution/content/66365/
private:
    const int N = 1501;
    int headIndex[N];
    int vertexValue[10 * N];
    int nextIndex[10 * N];
    int dp[N][2];
    bool hasFather[N];

    void addEdge(int a, int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(int root) {
        dp[root][0] = 0;
        dp[root][1] = 1;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            auto childV = vertexValue[idx];
            dfs(childV);
            dp[root][0] += dp[childV][1];
            dp[root][1] += min(dp[childV][1], dp[childV][0]);
        }
    }

    int main() {
        int n;
        while (cin >> n) {
            memset(headIndex, -1, sizeof headIndex);
            memset(nextIndex, -1, sizeof nextIndex);
            memset(hasFather, 0, sizeof hasFather);
            memset(dp, 0x3f, sizeof dp);
            int idx = 0;
            for (int i = 0; i < n; ++i) {
                int r, m;
                scanf("%d:(%d) ", &r, &m);
                for (int j = 0; j < m; ++j) {
                    int b;
                    scanf("%d", &b);
                    addEdge(r, b, idx);  // 所有边是单向边
                    hasFather[b] = true;
                }
            }
            int root = 0;
            while (hasFather[root]) {
                ++root;
            }
            dfs(root);
            printf("%d\n", min(dp[root][0], dp[root][1]));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0323_H
