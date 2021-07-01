//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0852_H
#define ACWINGSOLUTION_PROBLEM0852_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Problem0852 {
public:
    void addEdge(const int a,
                 const int b,
                 const int w,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 vector<int> &weight, int &idx) {
        weight[idx] = w;
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

// 每次做一遍SPFA一定是正确的，但时间复杂度较高，可能会超时。初始时将所有点插入队列中可以按如下方式理解：
// 在原图的基础上新建一个虚拟源点，从该点向其他所有点连一条权值为0的有向边。那么原图有负环等价于新图有负环。
    bool spfa(const vector<int> &headIndex,
              const vector<int> &vertexValue,
              const vector<int> &nextIndex,
              const vector<int> &weight) {
        const int n = headIndex.size() - 1;
        vector<bool> isInQueue(n + 1, false);
        vector<int> distance(n + 1, 0);
        vector<int> edgesCount(n + 1, 0);
        queue<int> q;
        for (int v = 1; v <= n; ++v) {
            q.emplace(v);
            isInQueue[v] = true;
        }
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            isInQueue[v] = false;
            for (int idx = headIndex[v]; idx != -1; idx = nextIndex[idx]) {
                int neighbor = vertexValue[idx];
                if (distance[neighbor] < distance[v] + weight[idx]) {
                    continue;
                }
                distance[neighbor] = distance[v] + weight[idx];
                edgesCount[neighbor] = edgesCount[v] + 1;
                if (edgesCount[neighbor] >= n) {
                    return true;
                }
                if (!isInQueue[neighbor]) {
                    isInQueue[neighbor] = true;
                    q.emplace(neighbor);
                }
            }
        }
        return false;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);

        // 提前分配空间，避免执行过多emplace_back操作；
        vector<int> headIndex(n + 1, -1);
        vector<int> vertexValue(m, 0);
        vector<int> nextIndex(m, -1);
        vector<int> weight(m, 0);

        int idx = 0;
        int x, y, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w, headIndex, vertexValue, nextIndex, weight, idx);
        }
        if (spfa(headIndex, vertexValue, nextIndex, weight)) {
            puts("Yes");
        } else {
            puts("No");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0852_H
