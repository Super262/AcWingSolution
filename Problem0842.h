//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0842_H
#define ACWINGSOLUTION_PROBLEM0842_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0842 {
public:
    void dfs(int k, const int n, bool *visited, int *path) {
        if (k == n) {
            for (int i = 0; i < n; ++i) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                continue;
            }
            path[k] = i;
            visited[i] = true;
            dfs(k + 1, n, visited, path);
            visited[i] = false;
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto visited = new bool[n + 1];
        auto path = new int[n];
        memset(visited, 0, sizeof(bool) * (n + 1));
        dfs(0, n, visited, path);
        delete[] path;
        delete[] visited;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0842_H
