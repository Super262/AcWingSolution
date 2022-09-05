//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1140_H
#define ACWINGSOLUTION_PROBLEM1140_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem1140 {
private:
    int Prim(const vector<vector<int>> &graph) {
        const auto n = (int) graph.size();
        bool selected[n];
        int dist[n];
        int result = 0;
        memset(selected, 0, sizeof selected);
        memset(dist, 0x3f, sizeof dist);
        for (int k = 1; k <= n; ++k) {
            int close_v = -1;
            for (int v = 0; v < n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (close_v == -1 || dist[close_v] > dist[v]) {
                    close_v = v;
                }
            }
            if (close_v == -1) {
                return result;
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
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &graph[i][j]);
                graph[j][i] = graph[i][j];
            }
        }
        printf("%d\n", Prim(graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1140_H
