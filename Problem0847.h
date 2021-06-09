//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0847_H
#define ACWINGSOLUTION_PROBLEM0847_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Problem0847 {
public:
    void addEdge(const int start,
                 const int end,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 int &idx) {
        if (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        if (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        vertexValue[idx] = end;
        nextIndex[idx] = headIndex[start];
        headIndex[start] = idx;
        ++idx;
    }

    int bfs(const int start,
            const int end,
            vector<int> &headIndex,
            vector<int> &vertexValue,
            vector<int> &nextIndex,
            vector<int> &distance) {
        // 注意：图中可能存在重边和自环
        if (headIndex[start] == -1) {
            return -1;
        }
        queue<int> q;
        q.emplace(start);
        distance[start] = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            int v;
            while (levelSize--) {
                v = q.front();
                q.pop();
                for (int neighbor = headIndex[v]; neighbor != -1; neighbor = nextIndex[neighbor]) {
                    if (distance[vertexValue[neighbor]] != -1) {
                        continue;
                    }
                    distance[vertexValue[neighbor]] = distance[v] + 1;
                    if (vertexValue[neighbor] == end) {
                        return distance[end];
                    }
                    q.emplace(vertexValue[neighbor]);
                }
            }
        }
        return -1;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);  // 链表头节点（顶点）对应的idx值
        vector<int> vertexValue(2 * n, 0); // idx对应的顶点编号
        vector<int> nextIndex(2 * n, -1); // 当前节点的下个节点的idx值
        vector<int> distance(n + 1, -1); // 指示顶点距根的距离
        int start, end;
        int idx = 0;
        while (m--) {
            scanf("%d%d", &start, &end);
            addEdge(start, end, headIndex, vertexValue, nextIndex, idx);
        }
        printf("%d\n", bfs(1, n, headIndex, vertexValue, nextIndex, distance));
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0847_H
