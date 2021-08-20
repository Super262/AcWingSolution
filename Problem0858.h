//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0858_H
#define ACWINGSOLUTION_PROBLEM0858_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0858 {
private:
    const int N = 510;
    const int INF = 0x7f7f7f7f;
    int graph[N][N];

    int prim(const int n) {
        auto isSelected = new bool[n + 1];
        auto dist = new int[n + 1];
        memset(isSelected, 0, sizeof(bool) * (n + 1));
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        int result = 0;
        bool hasMST = true;
        for (int k = 0; k < n; ++k) {
            int closestVertex = 0;
            for (int v = 1; v <= n; ++v) {
                if (isSelected[v] || (closestVertex && dist[closestVertex] <= dist[v])) {
                    continue;
                }
                closestVertex = v;
            }
            if (k && dist[closestVertex] == INF) {
                hasMST = false;
                break;
            }
            isSelected[closestVertex] = true;
            // 先更新result再更新dist
            if (k) {
                result += dist[closestVertex];
            }
            for (int v = 1; v <= n; ++v) {
                dist[v] = min(dist[v], graph[closestVertex][v]);
            }
        }
        if (!hasMST) {
            result = INF;
        }
        delete[] isSelected;
        delete[] dist;
        return result;
    }

    int main() {
        memset(graph, 0x7f, sizeof graph);
        int n, m;
        scanf("%d%d", &n, &m);
        int a, b, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &w);
            graph[a][b] = min(graph[a][b], w);
            graph[b][a] = graph[a][b];
        }
        int result = prim(n);
        if (result == INF) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0858_H
