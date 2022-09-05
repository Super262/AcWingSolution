//
// Created by Fengwei Zhang on 9/19/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1252_H
#define ACWINGSOLUTION_PROBLEM1252_H

#include <iostream>

using namespace std;

class Problem1252 {
private:
    static const int N = 10010;
    int dp[N];
    int value[N], price[N];
    int parent[N];

    int findRoot(int x) {
        auto u = x;
        while (u != parent[u]) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    void mergeSets(const int a, const int b) {
        auto pa = findRoot(a);
        auto pb = findRoot(b);
        if (pa == pb) {
            return;
        }
        parent[pa] = pb;
        value[pb] += value[pa];
        price[pb] += price[pa];
    }

    int knapsack(const int n, const int m) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i] != i) { // 不是根结点，跳过
                continue;
            }
            for (int j = m; j >= price[i]; --j) {
                dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
            }
        }
        return dp[m];
    }

    int main() {
        int n, m, w;
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &price[i], &value[i]);
        }
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            mergeSets(a, b);
        }
        printf("%d\n", knapsack(n, w));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1252_H
