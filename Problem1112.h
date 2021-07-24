//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1112_H
#define ACWINGSOLUTION_PROBLEM1112_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1112 {
public:
    char graph[110][110];
    bool visited[110][110];
    int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

    bool dfs(const int startX, const int startY, const int endX, const int endY, const int N) {
        // 这里的DFS不需要恢复现场（visited[startX][startY] = false），相当于“剪枝”。
        bool result = false;
        visited[startX][startY] = true;
        if (startX == endX && startY == endY) {
            result = true;
        } else {
            for (int i = 0; i < 4; ++i) {
                auto nextX = startX + dx[i];
                auto nextY = startY + dy[i];
                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) {
                    continue;
                }
                if (graph[nextX][nextY] == '#' || visited[nextX][nextY]) {
                    continue;
                }
                if (dfs(nextX, nextY, endX, endY, N)) {
                    result = true;
                    break;
                }
            }
        }
        return result;
    }

    int main() {
        int k;
        scanf("%d", &k);
        while (k--) {
            memset(visited, 0, sizeof visited);
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%s", graph[i]);
            }
            int startX, startY, endX, endY;
            scanf("%d%d%d%d", &startX, &startY, &endX, &endY);
            if (graph[startX][startY] == '#' || graph[endX][endY] == '#' || !dfs(startX, startY, endX, endY, n)) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1112_H
