//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1072_H
#define ACWINGSOLUTION_PROBLEM1072_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1072 {
public:
    int headIndex[10010];
    int nextIndex[20010];
    int vertexValue[20010];
    int weight[20010];

    void addEdge(const int a, const int b, const int w, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        weight[idx] = w;
        ++idx;
    }

    int dfs(const int root, const int father, int &answer) {
        int d1 = 0; // 最长的向下的路的长度
        int d2 = 0; // 次长的向下的路的长度
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int child = vertexValue[idx];
            if (child == father) {
                continue;
            }
            int childD1 = dfs(child, root, answer) + weight[idx];
            if (childD1 >= d1) { // 注意：这里是“大于或等于”，不是“大于”！
                d2 = d1;
                d1 = childD1;
            } else if (childD1 > d2) {
                d2 = childD1;
            }
        }
        answer = max(answer, d1 + d2);
        return d1;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int idx = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        int answer = 0;
        dfs(1, -1, answer);  // 任选1个点即可
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1072_H
