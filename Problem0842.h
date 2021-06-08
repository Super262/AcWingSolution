//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0842_H
#define ACWINGSOLUTION_PROBLEM0842_H

#include <memory.h>
#include <iostream>

using namespace std;

class Problem0842 {
public:
    void dfs(const int n, const int k, int *path, bool *visited) {
        if (k == n) {
            for (int i = 1; i <= n; ++i) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            path[k + 1] = i;
            dfs(n, k + 1, path, visited);
            visited[i] = false;
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto *visited = new bool[n + 1];
        auto *path = new int[n + 1];
        memset(visited, 0, sizeof(bool) * (n + 1));
        dfs(n, 0, path, visited);
        delete[] path;
        delete[] visited;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0842_H
