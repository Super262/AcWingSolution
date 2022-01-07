//
// Created by Fengwei Zhang on 1/6/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0456_H
#define ACWINGSOLUTION_PROBLEM0456_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0456 {
    // 注意虚拟中点的应用：https://www.acwing.com/solution/content/8537/
    // 用拓扑排序解决差分约束问题：要求最小值，就求最长路
private:
    vector<int> TopoSort(const int n, const vector<vector<pair<int, int>>> &graph, int degree[]) {
        vector<int> result;
        queue<int> q;
        for (int v = 1; v <= n; ++v) {
            if (degree[v]) {
                continue;
            }
            q.emplace(v);
        }
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            result.emplace_back(root);
            for (const auto &nt: graph[root]) {
                auto nv = nt.second;
                --degree[nv];
                if (degree[nv]) {
                    continue;
                }
                q.emplace(nv);
            }
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + m + 1);  // m条线路，需要m个虚拟中点
        bool stop[n + 1];  // 记录第i条线路经停的站点
        int degree[n + m + 1];  // 记录所有点的入度
        memset(degree, 0, sizeof degree);
        for (int mid = n + 1; mid <= n + m; ++mid) {  // 虚拟中点的编号：n + 1 ～ n + m
            memset(stop, 0, sizeof stop);
            int k;
            scanf("%d", &k);
            int st = n, ed = 1;  // 当前线路的起点和终点；注意：建图时，只考虑起点和终点以内的边
            while (k--) {
                int t;
                scanf("%d", &t);
                stop[t] = true;
                st = min(st, t);
                ed = max(ed, t);
            }
            for (int v = st; v <= ed; ++v) {
                if (stop[v]) {
                    graph[mid].emplace_back(1, v);
                    ++degree[v];
                } else {
                    graph[v].emplace_back(0, mid);
                    ++degree[mid];
                }
            }
        }
        vector<int> topo_order = TopoSort(n + m, graph, degree);
        int dist[n + m + 1];
        memset(dist, 0, sizeof dist);
        for (int v = 1; v <= n; ++v) {
            dist[v] = 1;
        }
        for (const auto &u: topo_order) {
            for (const auto &t: graph[u]) {
                auto v = t.second;
                dist[v] = max(dist[v], dist[u] + t.first);
            }
        }
        int result = 0;
        for (int v = 1; v <= n; ++v) {
            result = max(result, dist[v]);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0456_H
