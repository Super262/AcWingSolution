//
// Created by Fengwei Zhang on 12/23/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0383_H
#define ACWINGSOLUTION_PROBLEM0383_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0383 {
    // 最短路的搜索过程、次短路搜索过程都具有拓扑顺序
    // 采用Dijkstra算法的思想：https://www.acwing.com/solution/content/12246/
private:
    struct Node {
        int id;  // 顶点编号
        int type;  // 0：最短路径；1：次短路径
        int value;  // 路径长度

        bool operator>(const Node &node) const {
            return value > node.value;
        }
    };

    int Dijkstra(int st, int ed, const vector<vector<pair<int, int>>> &graph) {
        int dist[graph.size()][2];
        int counter[graph.size()][2];
        bool selected[graph.size()][2];
        priority_queue<Node, vector<Node>, greater<Node>> heap;
        memset(dist, 0x3f, sizeof dist);
        memset(counter, 0, sizeof counter);
        memset(selected, 0, sizeof selected);
        dist[st][0] = 0;
        heap.push({st, 0, 0});
        counter[st][0] = 1;
        while (!heap.empty()) {
            auto root = heap.top();
            heap.pop();
            if (selected[root.id][root.type]) {
                continue;
            }
            auto rv = root.id;
            auto rt = root.type;
            selected[rv][rt] = true;
            for (const auto &nt: graph[rv]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv][0] > dist[rv][rt] + nd) {
                    dist[nv][1] = dist[nv][0];
                    counter[nv][1] = counter[nv][0];
                    heap.push({nv, 1, dist[nv][1]});
                    dist[nv][0] = dist[rv][rt] + nd;
                    counter[nv][0] = counter[rv][rt];
                    heap.push({nv, 0, dist[nv][0]});
                } else if (dist[nv][0] == dist[rv][rt] + nd) {
                    counter[nv][0] += counter[rv][rt];
                } else if (dist[nv][1] > dist[rv][rt] + nd) {
                    dist[nv][1] = dist[rv][rt] + nd;
                    counter[nv][1] = counter[rv][rt];
                    heap.push({nv, 1, dist[nv][1]});
                } else if (dist[nv][1] == dist[rv][rt] + nd) {
                    counter[nv][1] += counter[rv][rt];
                }
            }
        }
        auto result = counter[ed][0];
        if (dist[ed][1] == dist[ed][0] + 1) {
            result += counter[ed][1];
        }
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, m;
            scanf("%d%d", &n, &m);
            vector<vector<pair<int, int>>> graph(n + 1);
            for (int i = 0; i < m; ++i) {
                int a, b, l;
                scanf("%d%d%d", &a, &b, &l);
                graph[a].emplace_back(l, b);
            }
            int s, f;
            scanf("%d%d", &s, &f);
            printf("%d\n", Dijkstra(s, f, graph));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0383_H
