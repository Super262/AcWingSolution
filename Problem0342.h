//
// Created by Fengwei Zhang on 2021/7/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0342_H
#define ACWINGSOLUTION_PROBLEM0342_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Problem0342 {
// https://www.acwing.com/solution/content/3950/
// 由于数据范围，不能直接使用SPFA算法
// 依照拓扑序依次处理每个团：在团内部通过Dijkstra计算最短路
// 1. 先输入所有双向道路，然后DFS出所有连通块，计算两个数组的值：vertex_block（顶点对应的连通块），block_vertexes（每个连通块包含哪些点）。
// 2. 输入所有航线，同时统计出每个连通块的入度。
// 3. 按照拓扑序依次处理每个连通块：先将入度为0的连通块加入队列blocks_queue中。
// 4. 每次从队头取出一个连通块的编号block_idx。
// 5. 将block_vertexes[block_idx]中所有的点加入小根堆中，执行Dijkstra算法。
// 6. 在上一步的过程中，若某个连通块的入度减小为0，则将其加入到队列blocks_queue中。
private:
    const int INF = 0x3f3f3f3f;

    void Dfs(const int root,
             const int block_idx,
             const vector<vector<pair<int, int>>> &graph,
             vector<int> &vertex_block,
             vector<vector<int>> &block_vertexes) {
        vertex_block[root] = block_idx;
        block_vertexes[block_idx].emplace_back(root);
        for (const auto &nt: graph[root]) {
            auto childV = nt.second;
            if (vertex_block[childV] != -1) {
                continue;
            }
            Dfs(childV, block_idx, graph, vertex_block, block_vertexes);
        }
    }

    void Dijkstra(const int block_idx,
                  const vector<vector<pair<int, int>>> &graph,
                  const vector<int> &vertex_block,
                  vector<int> &dist,
                  queue<int> &blocks_queue,
                  const vector<vector<int>> &block_vertexes,
                  vector<bool> &visited,
                  vector<int> &block_in_degree) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto v: block_vertexes[block_idx]) {
            heap.emplace(pair<int, int>(dist[v], v));
        }
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto root_v = t.second;
            if (visited[root_v]) {
                continue;
            }
            visited[root_v] = true;
            auto root_d = t.first;
            for (const auto &nt: graph[root_v]) {
                auto child_v = nt.second;
                auto child_d = nt.first;
                if (dist[root_v] != INF && dist[child_v] > root_d + child_d) {
                    dist[child_v] = root_d + child_d;
                    if (vertex_block[child_v] == vertex_block[root_v]) {
                        heap.emplace(pair<int, int>(dist[child_v], child_v));
                    }
                }
                // 删除横跨2个连通块的边
                if (vertex_block[child_v] != vertex_block[root_v]) {
                    --block_in_degree[vertex_block[child_v]];
                    if (block_in_degree[vertex_block[child_v]] == 0) {
                        blocks_queue.emplace(vertex_block[child_v]);
                    }
                }
            }
        }
    }

    void TopoSort(const int block_count,
                  const int st,
                  const int vertex_count,
                  const vector<vector<pair<int, int>>> &graph,
                  const vector<int> &vertex_block,
                  vector<int> &dist,
                  const vector<vector<int>> &block_vertexes,
                  vector<int> &block_in_degree) {
        queue<int> blocks_queue;
        for (int i = 0; i < block_count; ++i) {
            if (block_in_degree[i] != 0) {
                continue;
            }
            blocks_queue.emplace(i);
        }
        vector<bool> visited(vertex_count, false);
        dist[st] = 0;
        while (!blocks_queue.empty()) {
            auto b_idx = blocks_queue.front();
            blocks_queue.pop();
            Dijkstra(b_idx, graph, vertex_block, dist, blocks_queue, block_vertexes, visited, block_in_degree);
        }
    }

    int main() {
        int t, r, p, s;
        scanf("%d%d%d%d", &t, &r, &p, &s);
        vector<vector<pair<int, int>>> graph(t + 1);
        vector<int> vertex_block(t + 1, -1);
        vector<int> dist(t + 1, 0x3f3f3f3f);
        vector<vector<int>> block_vertexes(t + 1);
        vector<int> block_in_degree(t + 1, 0);
        for (int i = 0; i < r; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].emplace_back(w, b);
            graph[b].emplace_back(w, a);
        }
        int block_count = 0;
        for (int i = 1; i <= t; ++i) {
            if (vertex_block[i] != -1) {
                continue;
            }
            Dfs(i, block_count, graph, vertex_block, block_vertexes);
            block_count++;
        }
        for (int i = 1; i <= p; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].emplace_back(w, b);
            ++block_in_degree[vertex_block[b]];
        }
        TopoSort(block_count, s, t, graph, vertex_block, dist, block_vertexes, block_in_degree);
        for (int i = 1; i <= t; ++i) {
            if (dist[i] >= INF - (10000 * 50000)) { // 不通的路可能有负边，不能直接用INF
                puts("NO PATH");
            } else {
                printf("%d\n", dist[i]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0342_H
