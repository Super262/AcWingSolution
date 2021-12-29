//
// Created by Fengwei Zhang on 2021/7/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0342_H
#define ACWINGSOLUTION_PROBLEM0342_H

#include <iostream>
#include <vector>
#include <queue>

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

    void Dfs(const int st,
             const int block_idx,
             vector<int> &vertex_block,
             vector<vector<int>> &block_vertexes,
             const vector<vector<pair<int, int>>> &graph) {
        vertex_block[st] = block_idx;
        block_vertexes[block_idx].emplace_back(st);
        for (const auto &nt: graph[st]) {
            auto nv = nt.second;
            if (vertex_block[nv] != -1) {
                continue;
            }
            Dfs(nv, block_idx, vertex_block, block_vertexes, graph);
        }
    }

    void Dijkstra(const int b_idx,
                  const vector<vector<int>> &block_vertexes,
                  vector<int> &block_in_degree,
                  const vector<int> &vertex_block,
                  queue<int> &block_queue,
                  const vector<vector<pair<int, int>>> &graph,
                  vector<int> &dist,
                  vector<bool> &selected) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // 请问为什么一开始要将所有该连通块的点都加入进来呢？
        // 因为不确定连通块内的哪个点可以作为起点，所以就一股脑全加进来就行了，可以作为起点的就自然出现在堆顶了
        for (const auto &v: block_vertexes[b_idx]) {
            heap.push({dist[v], v});
        }
        while (!heap.empty()) {
            auto rt = heap.top();
            heap.pop();
            auto rv = rt.second;
            if (selected[rv]) {
                continue;
            }
            selected[rv] = true;
            for (const auto &nt: graph[rv]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] > dist[rv] + nd) {
                    dist[nv] = dist[rv] + nd;
                    if (vertex_block[nv] == vertex_block[rv]) {
                        heap.push({dist[nv], nv});
                    }
                }
                // 删除横跨2个连通块的边
                if (vertex_block[nv] != vertex_block[rv]) {
                    --block_in_degree[vertex_block[nv]];
                    if (block_in_degree[vertex_block[nv]] == 0) {
                        block_queue.emplace(vertex_block[nv]);
                    }
                }
            }
        }
    }

    void TopoSort(const int st,
                  const int block_count,
                  vector<int> &block_in_degree,
                  const vector<vector<int>> &block_vertexes,
                  const int vertex_count,
                  vector<int> &dist,
                  const vector<int> &vertex_block,
                  const vector<vector<pair<int, int>>> &graph) {
        queue<int> block_queue;
        for (int i = 0; i < block_count; ++i) {
            if (block_in_degree[i] != 0) {
                continue;
            }
            block_queue.emplace(i);
        }
        vector<bool> selected(vertex_count + 1, false);
        dist[st] = 0;
        while (!block_queue.empty()) {
            auto b_idx = block_queue.front();
            block_queue.pop();
            Dijkstra(b_idx, block_vertexes, block_in_degree, vertex_block, block_queue, graph, dist, selected);
        }
    }

    int main() {
        int t, r, p, s;
        scanf("%d%d%d%d", &t, &r, &p, &s);
        vector<vector<pair<int, int>>> graph(t + 1);
        for (int i = 0; i < r; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].emplace_back(w, b);
            graph[b].emplace_back(w, a);
        }
        vector<int> vertex_block(t + 1, -1);
        vector<vector<int>> block_vertexes(t + 1);
        int block_count = 0;
        for (int i = 1; i <= t; ++i) {
            if (vertex_block[i] != -1) {
                continue;
            }
            Dfs(i, block_count, vertex_block, block_vertexes, graph);
            ++block_count;
        }
        vector<int> block_in_degree(t + 1, 0);
        for (int i = 1; i <= p; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].emplace_back(w, b);
            ++block_in_degree[vertex_block[b]];
        }
        vector<int> dist(t + 1, INF);
        TopoSort(s, block_count, block_in_degree, block_vertexes, t, dist, vertex_block, graph);
        for (int i = 1; i <= t; ++i) {
            if (dist[i] >= INF - 50000 * 10000) {  // 不通的路可能有负边，不能直接用INF
                puts("NO PATH");
            } else {
                printf("%d\n", dist[i]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0342_H
