//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0323_H
#define ACWINGSOLUTION_PROBLEM0323_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0323 {
public:
    const int N = 1501;
    int headIndex[N];
    int nextIndex[10 * N];
    int vertexValue[10 * N];
    int dp[N][2];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(const int root) {
        dp[root][0] = 0;
        dp[root][1] = 1;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int childV = vertexValue[idx];
            dfs(childV);
            dp[root][0] += dp[childV][1];
            dp[root][1] += min(dp[childV][0], dp[childV][1]);
        }
    }

    int main() {
        int n;
        auto hasParent = new bool[N];
        while (scanf("%d", &n) != -1) {
            memset(hasParent, 0, sizeof(bool) * N);
            memset(headIndex, -1, sizeof headIndex);
            memset(nextIndex, -1, sizeof nextIndex);
            memset(vertexValue, -1, sizeof vertexValue);
            memset(dp, 0x7f, sizeof dp);
            int idx = 0;
            for (int i = 0; i < n; ++i) {
                int v, kidsNum;
                scanf("%d:(%d)", &v, &kidsNum);
                for (int j = 0; j < kidsNum; ++j) {
                    int u;
                    scanf("%d", &u);
                    addEdge(v, u, idx);
                    hasParent[u] = true;
                }
            }
            int root = 0;
            while (hasParent[root]) {
                ++root;
            }
            dfs(root);
            printf("%d\n", min(dp[root][0], dp[root][1]));
        }
        delete[] hasParent;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0323_H
