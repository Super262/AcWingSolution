//
// Created by Fengwei Zhang on 1/17/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1319_H
#define ACWINGSOLUTION_PROBLEM1319_H

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Problem1319 {
private:
    int SgFunc(int u, vector<int> &state, const vector<vector<int>> &graph) {
        if (state[u] != -1) {
            return state[u];
        }
        unordered_set<int> existed;
        for (const auto &v: graph[u]) {
            existed.insert(SgFunc(v, state, graph));
        }
        int s = 0;
        while (true) {
            if (existed.count(s)) {
                ++s;
            } else {
                state[u] = s;
                break;
            }
        }
        return state[u];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b);
        }
        vector<int> state(n + 1, -1);
        int res = 0;
        for (int i = 0; i < k; ++i) {
            int u;
            scanf("%d", &u);
            res ^= SgFunc(u, state, graph);
        }
        if (res) {
            printf("win\n");
        } else {
            printf("lose\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1319_H
