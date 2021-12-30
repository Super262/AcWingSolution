//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0344_H
#define ACWINGSOLUTION_PROBLEM0344_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0344 {
    // https://www.acwing.com/solution/content/9256/
private:
    const int INF = 0x3f3f3f3f;

    void GetPath(const int i, const int j, const vector<vector<int>> &mid_point, vector<int> &path) {
        if (mid_point[i][j] == -1) {
            return;
        }
        auto k = mid_point[i][j];
        GetPath(i, k, mid_point, path);
        path.emplace_back(k);
        GetPath(k, j, mid_point, path);
    }

    vector<int> Floyd(int n, const vector<vector<int>> &graph) {
        vector<vector<int>> mid_point(n + 1, vector<int>(n + 1, -1));  // 记录每个状态的中间结点
        vector<int> path;
        vector<vector<int>> dist(graph);
        auto res = INF;
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i < k; ++i) {  // 此时，k尚未被插入
                for (int j = i + 1; j < k; ++j) {
                    if ((long long) dist[i][j] + graph[j][k] + graph[k][i] >= res) {  // 注意类型转换
                        continue;
                    }
                    path.clear();
                    res = dist[i][j] + graph[j][k] + graph[k][i];
                    // 输出环（k -> i -> j -> k）的所有点：k，min_path[i:j]
                    path.emplace_back(k);
                    path.emplace_back(i);
                    GetPath(i, j, mid_point, path);
                    path.emplace_back(j);
                }
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] + dist[k][j] >= dist[i][j]) {
                        continue;
                    }
                    dist[i][j] = dist[i][k] + dist[k][j];
                    mid_point[i][j] = k;
                }
            }
        }
        return path;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
        for (int v = 1; v <= n; ++v) {
            graph[v][v] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v, l;
            scanf("%d%d%d", &u, &v, &l);
            graph[u][v] = min(graph[u][v], l);
            graph[v][u] = min(graph[v][u], l);
        }
        auto path = Floyd(n, graph);
        if (path.empty()) {
            printf("No solution.\n");
        } else {
            for (auto x: path) {
                printf("%d ", x);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0344_H
