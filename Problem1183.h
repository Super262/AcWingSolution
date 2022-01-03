//
// Created by Fengwei Zhang on 1/3/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1183_H
#define ACWINGSOLUTION_PROBLEM1183_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem1183 {
    // 为什么边双连通分量求解时的栈不需要一个 in_stack 的数组呢？因为无向图里是没有横插边的，所以不可能走到前面的点
    // 思想：求割点，如果没有割点那答案就是连通块的个数，否则，就是删去割点后连通块的个数。
    // https://www.acwing.com/solution/content/43015/
private:
    void Tarjan(const int u,
                const int root,
                const vector<vector<int>> &graph,
                int disc[],
                int low[],
                int &time_stamp,
                int &answer) {  // 由于不需要找到每个连通分量，所以不需要用到栈
        ++time_stamp;
        disc[u] = time_stamp;
        low[u] = time_stamp;
        int vdcc = 0;  // 如果当前点u是割点的话，去掉该点u得到的连通分量的个数
        for (const auto &v: graph[u]) {
            if (!disc[v]) {
                Tarjan(v, root, graph, disc, low, time_stamp, answer);
                low[u] = min(low[u], low[v]);
                if (disc[u] <= low[v]) {  // 说明u存在一棵子树，删除u后，新增连通块
                    ++vdcc;
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (u != root) { // 如果不是根节点，最后还要加上父节点部分
            ++vdcc;
        }
        answer = max(answer, vdcc);
    }

    int main() {
        while (true) {
            int n, m;
            scanf("%d%d", &n, &m);
            if (n == 0 && m == 0) {
                break;
            }
            vector<vector<int>> graph(n);
            while (m--) {
                int a, b;
                scanf("%d%d", &a, &b);
                graph[a].emplace_back(b);
                graph[b].emplace_back(a);
            }
            int disc[n];
            int low[n];
            int time_stamp = 0;
            int answer = 0;  // 记录每个连通块去掉一个点形成的连通块数目的最大值
            memset(disc, 0, sizeof disc);
            memset(low, 0, sizeof low);
            int counter = 0;  // 记录连通块的数目
            for (int root = 0; root < n; ++root) {  // 将图转树，设置根结点
                if (disc[root]) {
                    continue;
                }
                ++counter;
                Tarjan(root, root, graph, disc, low, time_stamp, answer);
            }
            printf("%d\n", counter + answer - 1);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1183_H
