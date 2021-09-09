//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1072_H
#define ACWINGSOLUTION_PROBLEM1072_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1072 {
    // 任取一点为起点，找到距离该点最远的点u
    // 找到距离u最远的点v；u和v间的距离即为直径
private:
    const int N = 10005;
    int headIndex[N];
    int nextIndex[2 * N];
    int vertexValue[2 * N];
    int weight[2 * N];

    void addEdge(int a, int b, int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int treeModel(int root, int father, int &answer) {
        int d1 = 0, d2 = 0;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            auto childV = vertexValue[idx];
            if (childV == father) {
                continue;
            }
            int childD1 = treeModel(childV, root, answer) + weight[idx];
            if (childD1 >= d1) {
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
        int n;
        scanf("%d", &n);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        int answer = 0;
        treeModel(1, -1, answer);
        printf("%d\n", answer);
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM1072_H
