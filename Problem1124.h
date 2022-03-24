//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1124_H
#define ACWINGSOLUTION_PROBLEM1124_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1124 {
    // 邻接矩阵上的欧拉路径，并要求字典序最小
private:
    const int N = 500;

    void Dfs(const int u, vector<vector<int>> &graph, int path[], int &p_top) {
        for (int v = 1; v <= N; ++v) {  // 为保证结果是字典序最小的，只要从小到大遍历邻接节点即可
            if (graph[u][v] == 0) {
                continue;
            }
            // 删除当前边
            --graph[u][v];
            --graph[v][u];
            Dfs(v, graph, path, p_top);
        }
        path[p_top++] = u;
    }

    int main() {
        vector<vector<int>> graph(N + 1, vector<int>(N + 1));
        int degree[N];
        memset(degree, 0, sizeof degree);
        int m;
        scanf("%d", &m);
        int a, b;
        while (m--) {
            scanf("%d%d", &a, &b);
            ++graph[a][b];  // 无向图，每次2条边
            ++graph[b][a];
            ++degree[a];
            ++degree[b];
        }
        int root = 1; // 设置起点初值为1，避免出错，所有点度数为偶数时，可以从任意点开始遍历
        for (int i = 1; i <= N; ++i) {
            if (degree[i] % 2) {  // 选择编号较小的奇数度点
                root = i;
                break;
            }
        }
        int path[2 * N + 50];
        int p_top = 0;
        Dfs(root, graph, path, p_top);
        for (int i = p_top - 1; i >= 0; --i) {
            printf("%d\n", path[i]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1124_H
