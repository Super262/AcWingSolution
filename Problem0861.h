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
    bool has_matched(int u, const vector<vector<int>> &graph, vector<int> &left_friends, bool visited[]) {
        for (const auto v: graph[u]) {
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            if (left_friends[v] == 0 || has_matched(left_friends[v], graph, left_friends, visited)) {
                left_friends[v] = u;
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
            graph[u].emplace_back(v);  // 这里我们只建立单向边
        }
        vector<int> left_friends(n2 + 1, 0);
        bool visited[n2 + 1];
        int result = 0;
        for (int u = 1; u <= n1; ++u) {
            memset(visited, 0, sizeof visited);
            if (has_matched(u, graph, left_friends, visited)) {
                ++result;
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0861_H
