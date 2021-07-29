//
// Created by Fengwei Zhang on 2021/7/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0342_H
#define ACWINGSOLUTION_PROBLEM0342_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Problem0342 {
    // https://www.acwing.com/solution/content/3950/
    // 依照拓扑序依次处理每个团：在团内部通过Dijkstra计算最短路
public:
    const int N = 25010, M = 150010;
    const int INF = 0x7f7f7f7f;
    int headIndex[N];
    int nextIndex[M];
    int vertexValue[M];
    int edgeWeight[M];
    int vertexBlock[N];
    int blockInDegree[N];
    bool visited[N];
    vector<int> blockVertexes[N];
    int dist[N];
    queue<int> blockQueue;

    void addEdge(const int s, const int e, const int w, int &idx) {
        vertexValue[idx] = e;
        edgeWeight[idx] = w;
        nextIndex[idx] = headIndex[s];
        headIndex[s] = idx;
        ++idx;
    }

    void dfs(const int root, const int bIdx) {
        vertexBlock[root] = bIdx;
        blockVertexes[bIdx].emplace_back(root);
        for (int vIdx = headIndex[root]; vIdx != -1; vIdx = nextIndex[vIdx]) {
            int childV = vertexValue[vIdx];
            if (vertexBlock[childV] != -1) {
                continue;
            }
            dfs(childV, bIdx);
        }
    }

    void dijkstra(const int bIdx) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto v : blockVertexes[bIdx]) {
            heap.emplace(pair<int, int>(dist[v], v));
        }
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int rootV = t.second;
            if (visited[rootV]) {
                continue;
            }
            visited[rootV] = true;
            int rootD = t.first;
            for (int idx = headIndex[rootV]; idx != -1; idx = nextIndex[idx]) {
                int childV = vertexValue[idx];
                if (dist[rootV] != INF && dist[childV] > rootD + edgeWeight[idx]) {
                    dist[childV] = rootD + edgeWeight[idx];
                    if (vertexBlock[childV] == vertexBlock[rootV]) {
                        heap.emplace(pair<int, int>(dist[childV], childV));
                    }
                }
                if (vertexBlock[childV] != vertexBlock[rootV]) {
                    --blockInDegree[vertexBlock[childV]];
                    if (blockInDegree[vertexBlock[childV]] == 0) {
                        blockQueue.emplace(vertexBlock[childV]);
                    }
                }
            }
        }
    }

    void topSort(const int bCount, const int s) {
        for (int i = 0; i < bCount; ++i) {
            if (blockInDegree[i] != 0) {
                continue;
            }
            blockQueue.emplace(i);
        }
        memset(dist, 0x7f, sizeof dist);
        dist[s] = 0;
        while (!blockQueue.empty()) {
            int t = blockQueue.front();
            blockQueue.pop();
            dijkstra(t);
        }
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        memset(vertexBlock, -1, sizeof vertexBlock);
        int t, r, p, s;
        int vIdx = 0;
        scanf("%d%d%d%d", &t, &r, &p, &s);
        for (int i = 0; i < r; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, vIdx);
            addEdge(b, a, w, vIdx);
        }
        int bCount = 0;
        for (int i = 1; i <= t; ++i) {
            if (vertexBlock[i] != -1) {
                continue;
            }
            dfs(i, bCount++);
        }
        for (int i = 1; i <= p; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, vIdx);
            ++blockInDegree[vertexBlock[b]];
        }
        topSort(bCount, s);
        for (int i = 1; i <= t; ++i) {
            if (dist[i] >= INF - (10000 * 50000)) { // 不通的路可能有负边，不能直接用INF
                puts("NO PATH");
            } else {
                printf("%d\n", dist[i]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0342_H
