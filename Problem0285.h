//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0285_H
#define ACWINGSOLUTION_PROBLEM0285_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0285 {
private:
    const int N = 6010;
    // dp[u][0]：所有从以u为根的子树中选择，但不选择u的方案
    // dp[u][1]：所有从以u为根的子树中选择，选择u的方案
    int dp[N][2];
    int headIndex[N];
    int nextIndex[2 * N];
    int vertexValue[2 * N];
    bool hasFather[N];
    int happiness[N];

    void addEdge(const int a, const int b, int &idx) {
        hasFather[b] = true;
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(const int root) {
        dp[root][1] = happiness[root];
        for (auto idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            auto childV = vertexValue[idx];
            dfs(childV);
            dp[root][1] += dp[childV][0];
            dp[root][0] += max(dp[childV][0], dp[childV][1]);
        }
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &happiness[i]);
        }
        int idx = 0;
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(b, a, idx);
        }
        int root = 1;
        while (hasFather[root]) {
            ++root;
        }
        dfs(root);
        printf("%d\n", max(dp[root][0], dp[root][1]));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0285_H
