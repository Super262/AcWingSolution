//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1127_H
#define ACWINGSOLUTION_PROBLEM1127_H

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

class Problem1127 {
public:
    int *headIndex;
    int *vertexValue;
    int *nextIndex;
    int *edgeWeight;
    const int INF = 0x7f7f7f7f;

    int dijkstraSum(const int start, const int p, const int *home, const int n) {
        auto dist = new int[p + 1];
        auto visited = new bool[p + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(dist, 0x7f, sizeof(int) * (p + 1));
        memset(visited, 0, sizeof(bool) * (p + 1));
        dist[start] = 0;
        heap.emplace(pair<int, int>(0, start));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rootV = t.second;
            if (visited[rootV]) {
                continue;
            }
            visited[rootV] = true;
            auto rootD = t.first;
            for (int idx = headIndex[rootV]; idx != -1; idx = nextIndex[idx]) {
                int childV = vertexValue[idx];
                if (rootD == INF || dist[childV] <= rootD + edgeWeight[idx]) {
                    continue;
                }
                dist[childV] = rootD + edgeWeight[idx];
                heap.emplace(pair<int, int>(dist[childV], childV));
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[home[i]] == INF) {
                result = INF;
                break;
            }
            result += dist[home[i]];
        }
        delete[] dist;
        return result;
    }

    void addEdge(const int s, const int e, const int w, int &idx) {
        vertexValue[idx] = e;
        edgeWeight[idx] = w;
        nextIndex[idx] = headIndex[s];
        headIndex[s] = idx;
        ++idx;
    }

    int main() {
        int n, p, c;
        scanf("%d%d%d", &n, &p, &c);
        headIndex = new int[p + 1];
        vertexValue = new int[2 * c + 1];
        nextIndex = new int[2 * c + 1];
        edgeWeight = new int[2 * c + 1];
        auto home = new int[n];
        memset(headIndex, -1, sizeof(int) * (p + 1));
        memset(vertexValue, 0, sizeof(int) * (2 * c + 1));
        memset(nextIndex, -1, sizeof(int) * (2 * c + 1));
        memset(edgeWeight, 0, sizeof(int) * (2 * c + 1));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &home[i]);
        }
        int idx = 0;
        for (int i = 0; i < c; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        int result = INF;
        for (int i = 1; i <= p; ++i) {
            result = min(result, dijkstraSum(i, p, home, n));
        }
        printf("%d\n", result);
        delete[] headIndex;
        delete[] vertexValue;
        delete[] nextIndex;
        delete[] edgeWeight;
        delete[] home;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1127_H
