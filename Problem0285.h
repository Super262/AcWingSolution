//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0285_H
#define ACWINGSOLUTION_PROBLEM0285_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0285 {
public:
    void addEdge(const int a,
                 const int b,
                 int *headIndex,
                 int *vertexValue,
                 int *nextIndex,
                 bool *hasFather,
                 int &idx) {
        hasFather[b] = true;
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(const int root,
             int **dp,
             const int *headIndex,
             const int *vertexValue,
             const int *nextIndex,
             const int *happiness) {
        dp[root][1] = happiness[root];
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int childV = vertexValue[idx];
            dfs(childV, dp, headIndex, vertexValue, nextIndex, happiness);
            dp[root][0] += max(dp[childV][0], dp[childV][1]);
            dp[root][1] += dp[childV][0];
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto happiness = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &happiness[i]);
        }
        auto headIndex = new int[n + 1];
        auto vertexValue = new int[n];
        auto nextIndex = new int[n];
        auto hasFather = new bool[n + 1];
        int idx = 0;
        memset(headIndex, -1, sizeof(int) * (n + 1));
        memset(vertexValue, 0, sizeof(int) * n);
        memset(nextIndex, -1, sizeof(int) * n);
        memset(hasFather, 0, sizeof(bool) * (n + 1));
        int a, b;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &b, &a);
            addEdge(a, b, headIndex, vertexValue, nextIndex, hasFather, idx);
        }
        auto dp = new int *[n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[i] = new int[2]{0, 0};
        }
        int root = 1;
        while (hasFather[root]) {
            ++root;
        }
        dfs(root, dp, headIndex, vertexValue, nextIndex, happiness);
        printf("%d\n", max(dp[root][0], dp[root][1]));
        delete[] headIndex;
        delete[] vertexValue;
        delete[] nextIndex;
        delete[] hasFather;
        delete[] happiness;
        for (int i = 1; i <= n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0285_H
