//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0848_H
#define ACWINGSOLUTION_PROBLEM0848_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Problem0848 {
public:
    void addEdge(const int start,
                 const int end,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 vector<int> &inDegree,
                 int &idx) {
        if (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        if (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        ++inDegree[end];
        vertexValue[idx] = end;
        nextIndex[idx] = headIndex[start];
        headIndex[start] = idx;
        ++idx;
    }

    vector<int> bfsTopo(vector<int> &headIndex,
                        vector<int> &vertexValue,
                        vector<int> &nextIndex,
                        vector<int> &inDegree,
                        vector<bool> &visited) {

        // 初始化
        queue<int> q;
        for (int i = 1; i < inDegree.size(); ++i) {
            if (inDegree[i]) {
                continue;
            }
            q.emplace(i);
            visited[i] = true;
        }

        int levelSize;
        int v;
        vector<int> result;
        while (!q.empty()) {
            levelSize = (int) q.size();
            while (levelSize--) {
                v = q.front();
                q.pop();
                for (int neighborIdx = headIndex[v]; neighborIdx != -1; neighborIdx = nextIndex[neighborIdx]) {
                    --inDegree[vertexValue[neighborIdx]];
                    if (!visited[vertexValue[neighborIdx]] && !inDegree[vertexValue[neighborIdx]]) {
                        q.emplace(vertexValue[neighborIdx]);
                        visited[vertexValue[neighborIdx]] = true;
                    }
                }
                result.emplace_back(v);
            }
        }

        // 不要忘记最后的特判！
        // 某些点未被输出，不存在拓扑序列
        if (result.size() < headIndex.size() - 1) {
            return vector<int>();
        }

        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);
        vector<int> vertexValue(2 * n + 1, 0);
        vector<int> nextIndex(2 * n + 1, -1);
        vector<int> inDegree(n + 1, 0);
        int idx = 0;
        int a, b;
        while (m--) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, headIndex, vertexValue, nextIndex, inDegree, idx);
        }
        vector<bool> visited(n + 1, false);
        vector<int> topoList = bfsTopo(headIndex, vertexValue, nextIndex, inDegree, visited);
        if (!topoList.empty()) {
            for (int &num:topoList) {
                printf("%d ", num);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0848_H
