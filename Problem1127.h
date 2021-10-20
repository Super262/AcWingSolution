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
private:
    const int N = 810, M = 3000;
    int headIndex[N];
    int nextIndex[M];
    int vertexValue[M];
    int weight[M];

    void addEdge(const int &a, const int &b, const int &w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dijkstraSum(const int &start, const int &p, const int home[], const int &n) {
        int dist[p + 1];
        bool selected[p + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[start] = 0;
        heap.emplace(pair<int, int>(dist[start], start));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto root = t.second;
            if (selected[root]) {
                continue;
            }
            selected[root] = true;
            for (auto idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                auto nV = vertexValue[idx];
                if (dist[nV] < dist[root] + weight[idx]) {
                    continue;
                }
                dist[nV] = dist[root] + weight[idx];
                heap.emplace(pair<int, int>(dist[nV], nV));
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[home[i]] == 0x3f3f3f3f) {
                return 0x3f3f3f3f;
            }
            result += dist[home[i]];
        }
        return result;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, p, c;
        scanf("%d%d%d", &n, &p, &c);
        int home[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &home[i]);
        }
        int x, y, w;
        int idx = 0;
        for (int i = 0; i < c; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w, idx);
            addEdge(y, x, w, idx);
        }
        int result = 0x3f3f3f3f;
        for (int i = 1; i <= p; ++i) {
            result = min(result, dijkstraSum(i, p, home, n));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1127_H
