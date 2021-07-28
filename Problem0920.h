//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0920_H
#define ACWINGSOLUTION_PROBLEM0920_H

#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Problem0920 {
public:
    bool **graph;

    int bfs(const int start, const int end, const int n) {
        if (start == end) {
            return 1;
        }
        auto q = new int[n + 1];
        int hh = 0, tt = -1;
        auto visited = new bool[n + 1];
        int result = -1;
        bool hasReached = false;
        memset(visited, 0, sizeof(bool) * (n + 1));
        q[++tt] = start;
        visited[start] = true;
        while (hh <= tt) {
            int currentLevelSize = tt - hh + 1;
            ++result;
            while (currentLevelSize--) {
                auto root = q[hh++];
                if (root == end) {
                    hasReached = true;
                    break;
                }
                for (int i = 1; i <= n; ++i) {
                    if (i == root) {
                        continue;
                    }
                    if (graph[root][i] && !visited[i]) {
                        visited[i] = true;
                        q[++tt] = i;
                    }
                }
            }
        }
        delete[] visited;
        delete[] q;
        if (!hasReached) {
            return -1;
        }
        return result;
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        graph = new bool *[n + 1];
        for (int i = 1; i <= n; ++i) {
            graph[i] = new bool[n + 1];
            memset(graph[i], 0, sizeof(bool) * (n + 1));
        }
        string path;
        auto stops = new int[n];
        getline(cin, path);  // 过滤掉上一行的回车符！！
        for (int k = 0; k < m; ++k) {
            getline(cin, path);
            stringstream ssin(path);
            int s;
            int tt = 0;
            while (ssin >> s) {
                stops[tt++] = s;
            }
            for (int i = 0; i < tt; ++i) {
                for (int j = i + 1; j < tt; ++j) {
                    graph[stops[i]][stops[j]] = true;
                }
            }
        }
        int result = bfs(1, n, n);
        if (result == -1) {
            puts("NO");
        } else {
            printf("%d\n", result - 1);
        }
        for (int i = 1; i <= n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0920_H
