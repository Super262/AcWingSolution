//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1074_H
#define ACWINGSOLUTION_PROBLEM1074_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1074 {
    // https://www.acwing.com/solution/content/10714/
private:
    const int N = 101;
    int headIndex[N];
    int vertexValue[2 * N];
    int nextIndex[2 * N];
    int weight[2 * N];
    int dp[N][2 * N];

    void addEdge(const int a, const int b, const int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(const int root, const int father, const int m) {
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int childV = vertexValue[idx];
            if (childV == father) {
                continue;
            }
            dfs(childV, root, m);
            for (int j = m; j >= 0; --j) {
                for (int k = 0; k < j; ++k) {
                    // 注意：根结点和子节点间有1条边，所以是 j - k - 1
                    dp[root][j] = max(dp[root][j], dp[root][j - k - 1] + weight[idx] + dp[childV][k]);
                }
            }
        }
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(headIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 0;
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        dfs(1, -1, m);
        printf("%d\n", dp[1][m]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1074_H
