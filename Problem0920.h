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
private:
    bool graph[501][501];

    int bfs(const int &start, const int &end, const int &n) {
        if (start == end) {
            return 1;
        }
        int q[n + 1];
        bool visited[n + 1];
        int hh = 0, tt = -1;
        memset(visited, 0, sizeof visited);
        int result = -1;
        q[++tt] = start;
        visited[start] = true;
        while (hh <= tt) {
            auto curL = tt - hh + 1;
            ++result;
            while (curL--) {
                auto root = q[hh++];
                if (root == end) {
                    return result;
                }
                for (int i = 1; i <= n; ++i) {
                    if (!graph[root][i] || visited[i]) {
                        continue;
                    }
                    q[++tt] = i;
                    visited[i] = true;
                }
            }
        }
        return -1;
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        memset(graph, 0, sizeof graph);
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
        int result = bfs(1, n, n);
        if (result == -1) {
            puts("NO");
        } else {
            printf("%d\n", result - 1);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0920_H
