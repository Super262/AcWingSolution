//
// Created by Fengwei Zhang on 12/25/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1146_H
#define ACWINGSOLUTION_PROBLEM1146_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem1146 {
    // 技巧：超级源点
    // https://www.acwing.com/solution/content/8713/
private:
    const int INF = 0x3f3f3f3f;

    int Prim(const vector<vector<int>> &graph) {
        int result = 0;
        const auto n = (int) graph.size();
        int dist[n];
        bool selected[n];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        for (int k = 1; k <= n; ++k) {
            int close_v = -1;
            for (int v = 0; v < n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (close_v == -1 || dist[v] < dist[close_v]) {
                    close_v = v;
                }
            }
            if (close_v == -1) {  // 不要忘记这个判断
                return INF;
            }
            if (k > 1 && dist[close_v] == INF) {  // 不要忘记这个判断
                return INF;
            }
            selected[close_v] = true;
            if (k > 1) {
                result += dist[close_v];
            }
            for (int v = 0; v < n; ++v) {
                dist[v] = min(dist[v], graph[close_v][v]);
            }
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1));
        for (int v = 1; v <= n; ++v) {
            int t;
            scanf("%d", &t);
            graph[0][v] = t;
            graph[v][0] = t;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int t;
                scanf("%d", &t);
                graph[i][j] = t;
                graph[j][i] = t;
            }
        }
        printf("%d", Prim(graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1146_H
