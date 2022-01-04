//
// Created by Fengwei Zhang on 1/3/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0372_H
#define ACWINGSOLUTION_PROBLEM0372_H

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Problem0372 {
    // 匈牙利算法的应用：https://www.acwing.com/solution/content/8559/
private:
    int GetIdx(const int x, const int y, const int base) {  // 映射2维到1维
        return (x - 1) * base + (y - 1);
    }

    bool FindFriend(const int x, const int y, const int n, bool graph[], int matched_idx[], bool visited[]) {
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > n || graph[GetIdx(nx, ny, n)] || visited[GetIdx(nx, ny, n)]) {
                continue;
            }
            visited[GetIdx(nx, ny, n)] = true;
            auto t = matched_idx[GetIdx(nx, ny, n)];
            auto tx = t / n + 1;
            auto ty = t % n + 1;
            if (t == -1 || FindFriend(tx, ty, n, graph, matched_idx, visited)) {
                matched_idx[GetIdx(nx, ny, n)] = GetIdx(x, y, n);
                return true;
            }
        }
        return false;
    }

    int main() {
        int n, t;
        scanf("%d%d", &n, &t);
        bool graph[n * n];
        int matched_idx[n * n];
        bool visited[n * n];
        memset(graph, 0, sizeof graph);
        memset(matched_idx, -1, sizeof matched_idx);
        while (t--) {
            int x, y;
            scanf("%d%d", &x, &y);
            graph[GetIdx(x, y, n)] = true;
        }
        int result = 0;
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                if ((x + y) % 2 == 0 || graph[GetIdx(x, y, n)]) {
                    continue;
                }
                memset(visited, 0, sizeof visited);
                if (FindFriend(x, y, n, graph, matched_idx, visited)) {
                    ++result;
                }
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0372_H
