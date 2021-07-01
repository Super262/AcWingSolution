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
    int prim(int** graph, const int n) {
        auto isSelected = new bool[n + 1];
        auto distance = new int[n + 1];
        memset(isSelected, 0, sizeof(bool) * (n + 1));
        memset(distance, 0x7f, sizeof(int) * (n + 1));
        const int INVALID_VALUE = 0x7f7f7f7f;
        int result = 0;
        for (int k = 0; k < n; ++k) {
            int closestVertex = 0;
            for (int v = 1; v <= n; ++v) {
                if (isSelected[v] || (closestVertex && distance[closestVertex] <= distance[v])) {
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
                distance[v] = min(graph[closestVertex][v], distance[v]);
            }
        }
        delete[] isSelected;
        delete[] distance;
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto graph = new int*[n + 1];
        for (int i = 1; i <= n; ++i) {
            graph[i] = new int[n + 1];
            memset(graph[i], 0x7f, sizeof(int) * (n + 1));
        }
        int x, y, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            // 无向图，每次添加2条边
            graph[x][y] = min(graph[x][y], w);
            graph[y][x] = graph[x][y];
        }
        int t = prim(graph, n);
        if (t == 0x7f7f7f7f) {
            puts("impossible");
        } else {
            printf("%d\n", t);
        }
        for (int i = 1; i <= n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0858_H
