//
// Created by Fengwei Zhang on 12/25/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1145_H
#define ACWINGSOLUTION_PROBLEM1145_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Problem1145 {
    // Kruskal算法的巧妙应用：距离d以内的点是相连的，求解满足连通块数量不多于k的最小d
private:
    struct Edge {
        int a, b;
        double w;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int FindRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }

    double GetDistance(int i, int j, pair<int, int> points[]) {
        auto dx = points[i].first - points[j].first;
        auto dy = points[i].second - points[j].second;
        return sqrt(dx * dx + dy * dy);
    }

    double Kruskal(int n, vector<Edge> &edges, const int k, int parent[]) {
        sort(edges.begin(), edges.end());
        auto counter = n;  // 当前剩余连通块的数量
        double result = 0;
        for (const auto &e: edges) {
            auto pa = FindRoot(e.a, parent);
            auto pb = FindRoot(e.b, parent);
            if (pa == pb) {
                continue;
            }
            parent[pa] = pb;
            result = e.w;
            --counter;
            if (counter <= k) {
                break;
            }
        }
        return result;
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        pair<int, int> temp[n];
        int parent[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &temp[i].first, &temp[i].second);
            parent[i] = i;
        }
        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {  // 避免加入重复边
                edges.push_back({i, j, GetDistance(i, j, temp)});
            }
        }
        printf("%.2lf\n", Kruskal(n, edges, k, parent));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1145_H
