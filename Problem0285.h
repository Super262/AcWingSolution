//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0285_H
#define ACWINGSOLUTION_PROBLEM0285_H

#include <iostream>

using namespace std;

class Problem0285 {
public:
    void addEdge(const int start,
                 const int end,
                 int *headIndex,
                 int *nextIndex,
                 int *vertexValue,
                 bool *hasFather,
                 int &idx) {
        hasFather[end] = true;
        vertexValue[idx] = end;
        nextIndex[idx] = headIndex[start];
        headIndex[start] = idx;
        ++idx;
    }

    void dfs(const int root,
             const int *headIndex,
             const int *nextIndex,
             const int *vertexValue,
             const int *happiness,
             int **dp) {
        dp[root][1] = happiness[root];
        for (int childIdx = headIndex[root]; childIdx != -1; childIdx = nextIndex[childIdx]) {
            const int childV = vertexValue[childIdx];
            dfs(childV, headIndex, nextIndex, vertexValue, happiness, dp);
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
        int a;
        int b;
        int idx = 0;
        auto headIndex = new int[n + 2];
        auto nextIndex = new int[n + 2];  // 需要尾部的多余位保存"-1"，指示链表终点
        auto vertexValue = new int[n + 2];
        auto hasFather = new bool[n + 2];

        // Initialization.
        for (int i = 0; i <= n + 1; ++i) {
            headIndex[i] = -1;
            nextIndex[i] = -1;
            vertexValue[i] = 0;
            hasFather[i] = false;
        }

        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &a, &b);
            addEdge(b, a, headIndex, nextIndex, vertexValue, hasFather, idx);
        }

        // Find the root.
        int root = 1;
        while (hasFather[root]) {
            ++root;
        }
        auto dp = new int *[n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new int[2]{0, 0};
        }

        dfs(root, headIndex, nextIndex, vertexValue, happiness, dp);
        printf("%d\n", max(dp[root][0], dp[root][1]));

        delete[] happiness;
        delete[] headIndex;
        delete[] nextIndex;
        delete[] vertexValue;
        for (int i = 0; i <= n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0285_H
