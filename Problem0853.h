//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0853_H
#define ACWINGSOLUTION_PROBLEM0853_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0853 {
private:
    struct Edge {
        int start;
        int end;
        int weight;
    };

    Edge edges[10010];

    int bellmanFord(const int start, const int n, const int edgesSize, int pathLen) {
        auto dist = new int[n + 1];
        auto temp = new int[n + 1];
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        dist[start] = 0;
        while (pathLen--) {
            // 不要忘记这个备份！
            memcpy(temp, dist, sizeof(int) * (n + 1));
            for (int i = 0; i < edgesSize; ++i) {
                dist[edges[i].end] = min(dist[edges[i].end], temp[edges[i].start] + edges[i].weight);
            }
        }
        int result = dist[n];
        delete[] temp;
        delete[] dist;
        // "正无穷"可能被负权边更新而减小，所以这里使用"0x3f3f3f3f/2"
        return result >= 0x3f3f3f3f / 2 ? 0x3f3f3f3f : result;
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].start, &edges[i].end, &edges[i].weight);
        }
        int result = bellmanFord(1, n, m, k);
        if (result == 0x7f7f7f7f) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0853_H
