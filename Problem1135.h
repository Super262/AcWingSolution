//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM1135_H
#define ACWINGSOLUTION_PROBLEM1135_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Problem1135 {
    // 1. 预处理出从1，a，b，c，d，e出发到其它所有点的最短路径
    // 2. DFS遍历所有拜访顺序，对于每1种拜访顺序，通过查表得到最短距离
private:
    void Dijkstra(const int st,
                  const vector<vector<pair<int, int>>> &graph,
                  vector<int> &dist) {
        vector<bool> visited(graph.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.emplace(pair<int, int>(0, st));
        dist[st] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rv = t.second;
            if (visited[rv]) {
                continue;
            }
            visited[rv] = true;
            auto rd = t.first;
            for (const auto &nt: graph[rv]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] <= rd + nd) {
                    continue;
                }
                dist[nv] = rd + nd;
                heap.emplace(pair<int, int>(dist[nv], nv));
            }
        }
    }

    int Dfs(const int selected_sources_count,
            const int s_idx,
            const int d,
            const vector<int> &sources,
            const vector<vector<int>> &dist,
            vector<bool> &visited) {
        if (selected_sources_count == sources.size()) {
            return d;
        }
        int res = 0x3f3f3f3f;
        for (int i = 1; i < sources.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            res = min(res, Dfs(selected_sources_count + 1, i, d + dist[s_idx][sources[i]], sources, dist, visited));
            visited[i] = false;
        }
        return res;
    }

    int main() {
        const int sources_num = 6;
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> sources(sources_num);
        vector<vector<pair<int, int>>> graph(n + 1);
        sources[0] = 1;
        for (int i = 1; i < sources_num; ++i) {
            scanf("%d", &sources[i]);
        }
        for (int i = 1; i <= m; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].emplace_back(w, b);
            graph[b].emplace_back(w, a);
        }
        vector<vector<int>> dist(sources_num, vector<int>(n + 1, 0x3f3f3f3f));
        for (int i = 0; i < sources_num; ++i) {
            Dijkstra(sources[i], graph, dist[i]);
        }
        vector<bool> visited(sources_num, false);
        visited[0] = true;
        printf("%d\n", Dfs(1, 0, 0, sources, dist, visited));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1135_H
