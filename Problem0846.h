//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0846_H
#define ACWINGSOLUTION_PROBLEM0846_H

#include <vector>
#include <iostream>

class Problem0846 {
public:
    void addEdge(const int a,
                 const int b,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 int &idx) { // 在有向图中插入边
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dfs(const int root,
            vector<bool> &visited,
            const vector<int> &headIndex,
            const vector<int> &vertexValue,
            const vector<int> &nextIndex,
            const int n,
            int &answer) { // 返回以root为根的子树的大小
        int nodesCount = 1;  // 当前子树的顶点数量
        int maxComponentSize = 1;  // 若root为重心，剩余各个连通块中点数的最大值

        visited[root] = true;
        for (int i = headIndex[root]; i != -1; i = nextIndex[i]) {
            int v = vertexValue[i];
            if (!visited[v]) {
                int childSize = dfs(v, visited, headIndex, vertexValue, nextIndex, n, answer);
                maxComponentSize = max(maxComponentSize, childSize);
                nodesCount += childSize;
            }
        }
        maxComponentSize = max(maxComponentSize, n - nodesCount);
        answer = min(answer, maxComponentSize);
        return nodesCount;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int idx = 0;
        int answer = n;

        // 邻接链表保存图信息
        vector<int> headIndex(n + 1, -1);  // 链表头节点（顶点）对应的idx值
        vector<int> vertexValue(2 * n, 0); // idx对应的顶点编号
        vector<int> nextIndex(2 * n, -1); // 当前节点的下个节点的idx值
        vector<bool> visited(n + 1, false); // 指示顶点是否被访问
        int a, b;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &a, &b);
            // 无向图，双向插入
            addEdge(a, b, headIndex, vertexValue, nextIndex, idx);
            addEdge(b, a, headIndex, vertexValue, nextIndex, idx);
        }
        dfs(1, visited, headIndex, vertexValue, nextIndex, n, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0846_H
