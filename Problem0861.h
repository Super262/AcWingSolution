//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0861_H
#define ACWINGSOLUTION_PROBLEM0861_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0861 {
private:
    bool has_matched(int root, const vector<vector<int>> &graph, vector<int> &left_friends, bool visited[]) {
        for (const auto nv: graph[root]) {
            if (visited[nv]) {
                continue;
            }
            visited[nv] = true;
            if (left_friends[nv] == 0 || has_matched(left_friends[nv], graph, left_friends, visited)) {
                left_friends[nv] = root;
                return true;
            }
        }
        return false;
    }

    int main() {
        int n1, n2, m;
        scanf("%d%d%d", &n1, &n2, &m);
        vector<vector<int>> graph(n1 + 1, vector<int>());
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
        }
        vector<int> left_friends(n2 + 1, 0);
        bool visited[n2 + 1];
        int result = 0;
        for (int v = 1; v <= n1; ++v) {
            memset(visited, 0, sizeof visited);
            if (has_matched(v, graph, left_friends, visited)) {
                ++result;
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0861_H
