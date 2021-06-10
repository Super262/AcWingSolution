//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0858_H
#define ACWINGSOLUTION_PROBLEM0858_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0858 {
public:
    int prim(const int n, int **graph) {
        const int INVALID_VALUE = 0x7fffffff;
        int *distance = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            distance[i] = INVALID_VALUE;
        }
        bool *isSelected = new bool[n + 1];
        memset(isSelected, 0, (n + 1) * sizeof(bool));
        int result = 0;
        int closestVertex;
        for (int k = 0; k < n; ++k) {
            closestVertex = 0;
            for (int v = 1; v <= n; ++v) {
                if (isSelected[v] || (closestVertex != 0 && distance[closestVertex] <= distance[v])) {
                    continue;
                }
                closestVertex = v;
            }
            if (k && distance[closestVertex] == INVALID_VALUE) {
                return INVALID_VALUE;
            }
            if (k) {
                result += distance[closestVertex];
            }
            isSelected[closestVertex] = true;
            for (int v = 1; v <= n; ++v) {
                distance[v] = min(distance[v], graph[closestVertex][v]);
            }
        }
        delete[] isSelected;
        delete[] distance;
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        const int INVALID_VALUE = 0x7fffffff;
        int **graph = new int *[n + 1];
        for (int i = 1; i <= n; ++i) {
            graph[i] = new int[n + 1];
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = INVALID_VALUE;
            }
        }
        int u, v, w;
        while (m--) {
            scanf("%d%d%d", &u, &v, &w);
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = graph[u][v];
        }
        int result = prim(n, graph);
        if (result == INVALID_VALUE) {
            puts("impossible");
        } else {
            printf("%d\n", result);
        }
        for (int i = 0; i <= n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0858_H
