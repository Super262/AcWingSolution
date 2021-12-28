//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0920_H
#define ACWINGSOLUTION_PROBLEM0920_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem0920 {
private:
    int Bfs(const int &start, const int &end, const int &n, const vector<vector<bool>> &graph) {
        queue<int> q;
        bool visited[n + 1];
        int result = 0;
        memset(visited, 0, sizeof visited);
        q.emplace(start);
        visited[start] = true;
        while (!q.empty()) {
            auto cur_size = (int) q.size();
            while (cur_size--) {
                auto root = q.front();
                q.pop();
                if (root == end) {
                    return result;
                }
                for (int i = 1; i <= n; ++i) {
                    if (!graph[root][i] || visited[i]) {
                        continue;
                    }
                    q.emplace(i);
                    visited[i] = true;
                }
            }
            ++result;
        }
        return -1;
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
        int stops[n + 1];
        string path;
        getline(cin, path);
        for (int k = 0; k < m; ++k) {
            getline(cin, path);
            stringstream ssin(path);
            int tt = 0;
            while (ssin >> stops[tt]) {
                ++tt;
            }
            for (int i = 0; i < tt; ++i) {
                for (int j = i + 1; j < tt; ++j) {
                    graph[stops[i]][stops[j]] = true;
                }
            }
        }
        auto result = Bfs(1, n, n, graph);
        if (result == -1) {
            puts("NO");
        } else {
            printf("%d\n", result - 1);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0920_H
