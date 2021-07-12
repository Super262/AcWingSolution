//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0010_H
#define ACWINGSOLUTION_PROBLEM0010_H

#include <iostream>
#include <cstring>

using namespace std;


class Problem0010 {
public:
    void addEdge(const int a, const int b, int *headIndex, int *nextIndex, int *vertexValue, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(int **dp,
             const int root,
             const int packVolume,
             const int *headIndex,
             const int *nextIndex,
             const int *vertexValue,
             const int *itemValue,
             const int *itemSize) {
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int son = vertexValue[idx];
            dfs(dp, son, packVolume, headIndex, nextIndex, vertexValue, itemValue, itemSize);
            for (int j = packVolume - itemSize[root]; j >= 0; --j) {
                for (int k = 0; k <= j; ++k) {
                    dp[root][j] = max(dp[root][j], dp[root][j - k] + dp[son][k]);
                }
            }
        }
        for (int j = packVolume; j >= itemSize[root]; --j) {
            dp[root][j] = dp[root][j - itemSize[root]] + itemValue[root];
        }
        for (int j = 0; j < itemSize[root]; ++j) {
            dp[root][j] = 0;
        }
    }

    int main() {
        int n;
        int packVolume;
        scanf("%d%d", &n, &packVolume);
        auto headIndex = new int[n + 2];
        auto nextIndex = new int[n + 2];
        auto vertexValue = new int[n + 2];
        auto itemValue = new int[n + 2];
        auto itemSize = new int[n + 2];
        auto dp = new int *[n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new int[packVolume + 1];
            memset(dp[i], 0, sizeof(int) * (packVolume + 1));
        }
        memset(headIndex, -1, sizeof(int) * (n + 2));
        memset(nextIndex, -1, sizeof(int) * (n + 2));
        memset(vertexValue, 0, sizeof(int) * (n + 2));
        memset(itemValue, 0, sizeof(int) * (n + 2));
        memset(itemSize, 0, sizeof(int) * (n + 2));
        int root = -1;
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            int p;
            scanf("%d%d%d", &itemSize[i], &itemValue[i], &p);
            if (p == -1) {
                root = i;
            }
            addEdge(p, i, headIndex, nextIndex, vertexValue, idx);
        }
        dfs(dp, root, packVolume, headIndex, nextIndex, vertexValue, itemValue, itemSize);
        printf("%d\n", dp[root][packVolume]);
        delete[] headIndex;
        delete[] nextIndex;
        delete[] vertexValue;
        delete[] itemValue;
        delete[] itemSize;
        for (int i = 0; i <= n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0010_H
