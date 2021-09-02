//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0010_H
#define ACWINGSOLUTION_PROBLEM0010_H

#include <iostream>
#include <cstring>

using namespace std;


class Problem0010 {
    // dp[r][v]：物品体积不超过v时，选择根结点为r的最大价值
private:
    struct Item {
        int v, w;
    };

    const int N = 102;
    int dp[N][N];
    Item items[N];
    int headIndex[N];
    int nextIndex[N];
    int vertexValue[N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void knapsack(const int m, const int n, const int root) {
        for (auto idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            auto son = vertexValue[idx];
            knapsack(m, n, son);
            for (int j = m - items[root].v; j >= 0; --j) {
                // 遍历所有可能方案
                for (int childV = 0; childV <= j; ++childV) {
                    dp[root][j] = max(dp[root][j], dp[root][j - childV] + dp[son][childV]);
                }
            }
        }
        // 将根结点加入背包
        for (int j = m; j >= items[root].v; --j) {
            dp[root][j] = dp[root][j - items[root].v] + items[root].w;
        }
        // 当背包容量小于根结点体积时，无法向背包中加入任何物品
        for (int j = items[root].v - 1; j >= 0; --j) {
            dp[root][j] = 0;
        }
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 0;
        int root = 0;
        for (int i = 1; i <= n; ++i) {
            int t;
            scanf("%d%d%d", &items[i].v, &items[i].w, &t);
            if (t == -1) {
                root = i;
            }
            addEdge(t, i, idx);
        }
        knapsack(m, n, root);
        printf("%d\n", dp[root][m]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0010_H
