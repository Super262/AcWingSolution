//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef ACWINGSOLUTION_PROBLEM2154_H
#define ACWINGSOLUTION_PROBLEM2154_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem2154 { // https://www.acwing.com/solution/content/65396/
private:
    const int N = 100010;
    const int M = 1000010;

    int headIndex[M], vertexValue[N], nextIndex[N];
    int color[N];
    int parent[M], setSize[M];
    int segsCnt = 1;

    void addEdge(const int &a, const int &b, int &idx) {
        ++setSize[a];
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void merge_sets(int &px, int &py) { // 所以映射的本质是将颜色x看成颜色y，颜色y看成颜色x
        if (px == py) {
            return;
        }
        if (setSize[px] > setSize[py]) {
            swap(px, py);
        }
        for (int idx = headIndex[px]; idx != -1; idx = nextIndex[idx]) {
            auto ci = vertexValue[idx];
            if (ci > 0 && color[ci - 1] == py) {
                --segsCnt;
            }
            if (color[ci + 1] == py) {
                --segsCnt;
            }
        }
        for (int idx = headIndex[px]; idx != -1; idx = nextIndex[idx]) {
            auto ci = vertexValue[idx];
            color[ci] = py;
            if (nextIndex[idx] == -1) {
                nextIndex[idx] = headIndex[py];
                headIndex[py] = headIndex[px];
                break;
            }
        }
        headIndex[px] = -1;
        setSize[py] += setSize[px];
        setSize[px] = 0;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        for (int i = 0; i < M; ++i) {
            parent[i] = i;
        }
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &color[i]);
            addEdge(color[i], i, idx);
            if (i > 0 && color[i] != color[i - 1]) {
                ++segsCnt;
            }
        }
        int op, x, y;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &x, &y);
                merge_sets(parent[x], parent[y]);
            } else {
                printf("%d\n", segsCnt);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2154_H
