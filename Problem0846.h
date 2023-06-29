//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0846_H
#define ACWINGSOLUTION_PROBLEM0846_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0846 {
private:
    int dfs(int root, const int n, const vector<vector<int>> &graph, vector<bool> &visited, int &answer) {
        visited[root] = true;
        int nodes_count = 1;
        int max_component = 0;
        for (const auto &v: graph[root]) {
            if (visited[v]) {
                continue;
            }
            auto child_size = dfs(v, n, graph, visited, answer);
            max_component = max(max_component, child_size);
            nodes_count += child_size;
        }
        max_component = max(max_component, n - nodes_count);
        answer = min(answer, max_component);
        return nodes_count;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<int>> graph(n + 1, vector<int>());
        int a, b;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        auto answer = n;
        vector<bool> visited(n + 1, false);
        dfs(1, n, graph, visited, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0846_H
