//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0345_H
#define ACWINGSOLUTION_PROBLEM0345_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Problem0345 {
    // 基于Floyd算法设计的新算法，满足结合律，可以使用快速幂：https://www.acwing.com/solution/content/17209/
private:
    const int INF = 0x3f3f3f3f;

    vector<vector<int>> Multiply(const int n, vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> temp(n + 1, vector<int>(n + 1, INF));
        for (int t = 1; t <= n; ++t) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    temp[i][j] = min(temp[i][j], a[i][t] + b[t][j]);
                }
            }
        }
        return temp;
    }

    vector<vector<int>> Qmi(const int n, vector<vector<int>> &graph, int k) {
        vector<vector<int>> res(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; ++i) {
            res[i][i] = 0;
        }
        while (k) {
            if (k & 1) {
                res = Multiply(n, res, graph);
            }
            graph = Multiply(n, graph, graph);
            k >>= 1;
        }
        return res;
    }

    int main() {
        const int N = 210;
        int k, m, s, e;
        scanf("%d%d%d%d", &k, &m, &s, &e);
        unordered_map<int, int> ids;
        vector<vector<int>> graph(N, vector<int>(N, INF));
        int n = 0;
        if (!ids.count(s)) {
            ids[s] = ++n;
        }
        if (!ids.count(e)) {
            ids[e] = ++n;
        }
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &c, &a, &b);
            if (!ids.count(a)) {
                ids[a] = ++n;
            }
            if (!ids.count(b)) {
                ids[b] = ++n;
            }
            a = ids[a];
            b = ids[b];
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = graph[a][b];
        }
        auto res = Qmi(n, graph, k);
        printf("%d\n", res[ids[s]][ids[e]]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0345_H
