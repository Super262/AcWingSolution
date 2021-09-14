//
// Created by Fengwei Zhang on 2021/7/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1076_H
#define ACWINGSOLUTION_PROBLEM1076_H

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

class Problem1076 {
public:
    const int N = 1000;
    int graph[N][N];
    pair<int, int> preNode[N][N];  // preNode代替visited，标记被访问的节点
    pair<int, int> q[N * N + 1];

    void bfs(const int startX, const int startY, const int endX, const int endY, const int n) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        memset(preNode, -1, sizeof preNode);
        int hh = 0, tt = -1;
        q[++tt] = pair<int, int>(startX, startY);
        while (hh <= tt) {
            auto root = q[hh++];
            if (root.first == endX && root.second == endY) {
                return;
            }
            for (int i = 0; i < 4; ++i) {
                auto nextX = root.first + dx[i];
                auto nextY = root.second + dy[i];
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || graph[nextX][nextY] == 1 ||
                    preNode[nextX][nextY].first != -1) {
                    continue;
                }
                q[++tt] = pair<int, int>(nextX, nextY);
                preNode[nextX][nextY] = root;
            }
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        bfs(n - 1, n - 1, 0, 0, n);  // 反向bfs，避免逆向输出路径
        int currentX = 0;
        int currentY = 0;
        while (true) {
            printf("%d %d\n", currentX, currentY);
            if (currentX == n - 1 && currentY == n - 1) {
                break;
            }
            auto temp = preNode[currentX][currentY];
            currentX = temp.first;
            currentY = temp.second;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1076_H
