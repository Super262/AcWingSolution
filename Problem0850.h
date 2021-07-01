//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0850_H
#define ACWINGSOLUTION_PROBLEM0850_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Problem0850 {
public:
    void addEdge(const int start,
                 const int end,
                 const int w,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 vector<int> &weight,
                 int &idx) {

        // 及时扩容，避免内存错误！
        if (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        if (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        if (idx >= weight.size()) {
            weight.emplace_back(0);
        }
        weight[idx] = w;
        vertexValue[idx] = end;
        nextIndex[idx] = headIndex[start];
        headIndex[start] = idx;
        ++idx;
    }

    int dijkstra(const vector<int> &headIndex,
                 const vector<int> &vertexValue,
                 const vector<int> &nextIndex,
                 const vector<int> &weight,
                 const int n) {
        vector<int> distance(n + 1, 0x3f3f3f3f);
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.emplace(pair<int, int>(0, 1));
        distance[1] = 0;
        while (!heap.empty()) {
            auto node = heap.top();
            heap.pop();
            int v = node.second;

            // 设置访问标记的时机：顶点出队时！
            if (visited[v]) {
                continue;
            }
            visited[v] = true;

            int d = node.first;
            for (int neighborIdx = headIndex[v]; neighborIdx != -1; neighborIdx = nextIndex[neighborIdx]) {
                int neighborV = vertexValue[neighborIdx];
                if (distance[neighborV] > d + weight[neighborIdx]) {
                    distance[neighborV] = d + weight[neighborIdx];
                    // 只有距离发生变化的点需要被放入堆中
                    // 堆中存放的是节点距起点的距离
                    heap.emplace(pair<int, int>(distance[neighborV], neighborV));
                }
            }
        }
        return distance[n] == 0x3f3f3f3f ? -1 : distance[n];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);
        vector<int> weight(n + 1, 0);
        vector<int> vertexValue(2 * n + 1, 0);
        vector<int> nextIndex(2 * n + 1, -1);
        int idx = 0;
        int x, y, z;
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            addEdge(x, y, z, headIndex, vertexValue, nextIndex, weight, idx);
        }
        printf("%d\n", dijkstra(headIndex, vertexValue, nextIndex, weight, n));
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0850_H
