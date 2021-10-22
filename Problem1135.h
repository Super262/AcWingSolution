//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM1135_H
#define ACWINGSOLUTION_PROBLEM1135_H

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

class Problem1135 {
    // 1. 预处理出从1，a，b，c，d，e出发到其它所有点的最短路径
    // 2. DFS遍历所有拜访顺序，对于每1种拜访顺序，通过查表得到最短距离
private:
    const int N = 50010;
    const int M = 200010;
    const int SOURCES_NUM = 6;
    int sourceV[SOURCES_NUM];
    int headIndex[N];
    int vertexValue[M];
    int nextIndex[M];
    int edgeWeight[M];
    int dist[SOURCES_NUM][N];
    bool visited[N];

    void addEdge(const int s, const int e, const int w, int &idx) {
        vertexValue[idx] = e;
        edgeWeight[idx] = w;
        nextIndex[idx] = headIndex[s];
        headIndex[s] = idx;
        ++idx;
    }

    void dijkstra(const int sIdx) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(visited, 0, sizeof visited);
        memset(dist[sIdx], 0x7f, sizeof dist[sIdx]);
        heap.emplace(pair<int, int>(0, sourceV[sIdx]));
        dist[sIdx][sourceV[sIdx]] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rootV = t.second;
            if (visited[rootV]) {
                continue;
            }
            visited[rootV] = true;
            auto rootD = t.first;
            for (auto idx = headIndex[rootV]; idx != -1; idx = nextIndex[idx]) {
                auto childV = vertexValue[idx];
                if (dist[sIdx][childV] <= rootD + edgeWeight[idx]) {
                    continue;
                }
                dist[sIdx][childV] = rootD + edgeWeight[idx];
                heap.emplace(pair<int, int>(dist[sIdx][childV], childV));
            }
        }
    }

    int dfs(const int selectedSourcesCount, const int currentV, const int d) {
        if (selectedSourcesCount == SOURCES_NUM) {
            return d;
        }
        int res = 0x7f7f7f7f;
        for (int i = 1; i < SOURCES_NUM; ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            res = min(res, dfs(selectedSourcesCount + 1, i, d + dist[currentV][sourceV[i]]));
            visited[i] = false;
        }
        return res;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(vertexValue, 0, sizeof vertexValue);
        memset(nextIndex, -1, sizeof nextIndex);
        memset(edgeWeight, 0, sizeof edgeWeight);
        int n, m;
        scanf("%d%d", &n, &m);
        sourceV[0] = 1;
        for (int i = 1; i < SOURCES_NUM; ++i) {
            scanf("%d", &sourceV[i]);
        }
        int idx = 0;
        for (int i = 1; i <= m; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        for (int i = 0; i < SOURCES_NUM; ++i) {
            dijkstra(i);
        }
        memset(visited, 0, sizeof visited);
        visited[0] = true;
        printf("%d\n", dfs(1, 0, 0));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1135_H
