//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0240_H
#define ACWINGSOLUTION_PROBLEM0240_H

#include <iostream>

using namespace std;

class Problem0240
{
    // https://www.acwing.com/solution/content/24842/
private:
    int find_root(const int &x, int *parent, int *dist)
    {
        if (x != parent[x])
        {
            auto root = find_root(parent[x], parent, dist); // 递归：按从根到底的顺序更新dist[i]
            dist[x] += dist[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    bool merge_sets(const int &x, const int &y, const int &rel, int *parent, int *dist)
    {
        auto px = find_root(x, parent, dist);
        auto py = find_root(y, parent, dist);
        if (rel == 1 && px == py && (dist[x] - dist[y]) % 3)
        {
            return false;
        }
        if (rel == 2 && px == py && (dist[x] - dist[y] - 1) % 3)
        {
            return false;
        }
        if (px == py)
        {
            return true;
        }
        parent[px] = py;
        if (rel == 1)
        {
            dist[px] = dist[y] - dist[x];
        }
        else
        {
            dist[px] = dist[y] - dist[x] + 1;
        }
        return true;
    }

    int main()
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int parent[n + 1];
        int dist[n + 1]; // 当前节点到根结点的距离
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            dist[i] = 0;
        }
        int ans = 0;
        for (int i = 0, op, x, y; i < k; --k)
        {
            scanf("%d%d%d", &op, &x, &y);
            if (x > n || y > n)
            {
                ++ans;
                continue;
            }
            if (!merge_sets(x, y, op, parent, dist))
            {
                ++ans;
            }
        }
        printf("%d\n", ans);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0240_H
