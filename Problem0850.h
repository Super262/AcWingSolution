//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0850_H
#define ACWINGSOLUTION_PROBLEM0850_H

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

class Problem0850 {
private:
    const int N = 150010;
    int headIndex[N];
    int nextIndex[N];
    int vertexValue[N];
    int weight[N];

    void addEdge(const int a, const int b, const int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dijkstra(const int start, const int n) {
        auto dist = new int[n + 1];
        auto selected = new bool[n + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        memset(selected, 0, sizeof(bool) * (n + 1));
        dist[start] = 0;
        heap.emplace(pair<int, int>(dist[start], start));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto closestVertex = t.second;
            if (selected[closestVertex]) {
                continue;
            }
            selected[closestVertex] = true;
            for (int idx = headIndex[closestVertex]; idx != -1; idx = nextIndex[idx]) {
                int nextV = vertexValue[idx];
                if (weight[idx] == 0x7f7f7f7f || dist[nextV] < dist[closestVertex] + weight[idx]) {
                    continue;
                }
                dist[nextV] = dist[closestVertex] + weight[idx];
                heap.emplace(pair<int, int>(dist[nextV], nextV));
            }
        }
        int result = dist[n];
        delete[] dist;
        delete[] selected;
        return result == 0x7f7f7f7f ? -1 : result;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w, idx);
        }
        printf("%d\n", dijkstra(1, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0850_H
