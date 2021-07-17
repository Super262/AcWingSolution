//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM1077_H
#define ACWINGSOLUTION_PROBLEM1077_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1077 {
    // https://www.acwing.com/solution/content/13979/
public:
    const int N = 1502;
    int headIndex[N];
    int vertexValue[2 * N];
    int nextIndex[2 * N];
    int cost[N];
    int dp[N][3];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }
// dp[i][0]表示第i个节点由父节点处放置的守卫看护下的最小代价
// dp[i][1]表示第i个节点由子节点处放置的守卫看护下的最小代价
// dp[i][2]表示第i个节点由在该节点放置的守卫看护下的最小代价
// 1和3的意义很明显，2的意义代表，如果第i个节点由子节点守卫，那么所有子节点都不能由父节点守卫，
// 并且每个子节点都得到了守卫，且至少有一个子节点处放置了守卫

    void dfs(const int root) {
        dp[root][2] = cost[root];
        dp[root][0] = 0;
        int childrenCostSum = 0;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int childV = vertexValue[idx];
            dfs(childV);
            childrenCostSum += min(dp[childV][1], dp[childV][2]);
            dp[root][0] += min(dp[childV][1], dp[childV][2]);
            dp[root][2] += min(min(dp[childV][1], dp[childV][2]), dp[childV][0]);
        }
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int childV = vertexValue[idx];
            dp[root][1] = min(dp[root][1], dp[childV][2] + childrenCostSum - min(dp[childV][1], dp[childV][2]));
        }
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        memset(dp, 0x7f, sizeof dp);
        int n;
        scanf("%d", &n);
        auto hasParent = new bool[n + 1];
        memset(hasParent, 0, sizeof(bool) * (n + 1));
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            int v, c, k;
            scanf("%d%d%d", &v, &c, &k);
            cost[v] = c;
            for (int j = 0; j < k; ++j) {
                int u;
                scanf("%d", &u);
                // 单向边即可，无需孩子指向父亲的边：
                // DFS保证先计算子节点的状态，自动维护从孩子节点到父节点的依赖关系
                addEdge(v, u, idx);
                hasParent[u] = true;
            }
        }
        int root = 1;
        while (hasParent[root]) {
            ++root;
        }
        dfs(root);
        delete[] hasParent;
        printf("%d\n", min(dp[root][1], dp[root][2]));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1077_H
