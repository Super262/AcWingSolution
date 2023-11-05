//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0843_H
#define ACWINGSOLUTION_PROBLEM0843_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0843
{
    // 以截距为对角线编号
private:
    void dfs(const int &r, const int &n, char **graph, bool *col_used, bool *dg_used, bool *udg_used)
    {
        if (r >= n)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("%c", graph[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            return;
        }
        for (int c = 0; c < n; ++c)
        {
            if (col_used[c] || dg_used[c + r] || udg_used[n - r + c] || graph[r][c] == 'Q')
            {
                continue;
            }
            col_used[c] = true;
            dg_used[c + r] = true;
            udg_used[n - r + c] = true;
            graph[r][c] = 'Q';
            dfs(r + 1, n, graph, col_used, dg_used, udg_used);
            col_used[c] = false;
            dg_used[c + r] = false;
            udg_used[n - r + c] = false;
            graph[r][c] = '.';
        }
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        bool col_used[n];
        bool dg_used[2 * n];
        bool udg_used[2 * n];
        memset(col_used, 0, sizeof col_used);
        memset(dg_used, 0, sizeof dg_used);
        memset(udg_used, 0, sizeof udg_used);
        char *graph[n];
        for (int i = 0; i < n; ++i)
        {
            graph[i] = new char[n];
            for (int j = 0; j < n; ++j)
            {
                graph[i][j] = '.';
            }
        }
        dfs(0, n, graph, col_used, dg_used, udg_used);
        for (int i = 0; i < n; ++i)
        {
            delete[] graph[i];
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0843_H
