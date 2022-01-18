//
// Created by Fengwei Zhang on 1/17/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0217_H
#define ACWINGSOLUTION_PROBLEM0217_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0217 {
    // https://www.acwing.com/solution/content/25991/
private:
    const double zero_Value = 1e-6;

    double GetExpectation(int u, const vector<vector<pair<int, int>>> &graph, const int degree[], double dp[]) {
        if (dp[u] >= zero_Value) {
            return dp[u];
        }
        dp[u] = 0;
        for (const auto &nt: graph[u]) {
            auto nv = nt.second;
            auto nd = nt.first;
            dp[u] += (nd + GetExpectation(nv, graph, degree, dp)) / degree[u];
        }
        return dp[u];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1);
        int degree[n + 1];
        memset(degree, 0, sizeof degree);
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            graph[a].push_back({c, b});
            ++degree[a];
        }
        double dp[n + 1];
        memset(dp, -1, sizeof dp);
        dp[n] = 0;
        printf("%.2lf\n", GetExpectation(1, graph, degree, dp));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0217_H
