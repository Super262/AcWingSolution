//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0842_H
#define ACWINGSOLUTION_PROBLEM0842_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0842
{
private:
    void dfs(const int k, const int n, int *path, bool *visited)
    {
        if (k > n)
        {
            for (int i = 1; i <= n; ++i)
            {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i])
            {
                continue;
            }
            visited[i] = true;
            path[k] = i;
            dfs(k + 1, n, path, visited);
            visited[i] = false;
        }
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int path[n + 1];
        bool visited[n + 1];
        memset(visited, 0, sizeof(bool) * (n + 1));
        dfs(1, n, path, visited);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0842_H
