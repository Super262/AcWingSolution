//
// Created by Fengwei Zhang on 2021/7/23.
//

#ifndef ACWINGSOLUTION_PROBLEM0175_H
#define ACWINGSOLUTION_PROBLEM0175_H

#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

class Problem0175 {
    // https://www.acwing.com/solution/content/26973/
    // 边权为0/1，找最短路径：双端队列BFS
private:
    static const int MAX_N = 510;
    char graph[MAX_N + 1][MAX_N + 1];
    int dist[MAX_N + 1][MAX_N + 1];
    bool isSelected[MAX_N + 1][MAX_N + 1];

    int bfs(const int startX, const int startY, const int endX, const int endY, const int N, const int M) {
        deque<pair<int, int>> q;
        int nextPointDX[] = {-1, -1, 1, 1};
        int nextPointDY[] = {-1, 1, 1, -1};
        int nextGridDX[] = {-1, -1, 0, 0};
        int nextGridDY[] = {-1, 0, 0, -1};
        char expectedPath[] = {'\\', '/', '\\', '/'};
        memset(dist, 0x7f, sizeof dist);
        memset(isSelected, 0, sizeof isSelected);
        q.push_front(pair<int, int>(startX, startY));
        dist[startX][startY] = 0;
        while (!q.empty()) {
            auto root = q.front();
            q.pop_front();
            if (root.first == endX && root.second == endY) {
                return dist[endX][endY];
            }
            if (isSelected[root.first][root.second]) {
                continue;
            }
            isSelected[root.first][root.second] = true;
            for (int i = 0; i < 4; ++i) {
                auto nextPX = nextPointDX[i] + root.first;
                auto nextPY = nextPointDY[i] + root.second;
                if (nextPX < 0 || nextPX >= N || nextPY < 0 || nextPY >= M) {
                    continue;
                }
                auto nextGX = nextGridDX[i] + root.first;
                auto nextGY = nextGridDY[i] + root.second;
                int w = graph[nextGX][nextGY] == expectedPath[i] ? 0 : 1;
                if (dist[nextPX][nextPY] <= dist[root.first][root.second] + w) {
                    continue;
                }
                dist[nextPX][nextPY] = dist[root.first][root.second] + w;
                if (w) {
                    q.emplace_back(pair<int, int>(nextPX, nextPY));
                } else {
                    q.push_front(pair<int, int>(nextPX, nextPY));
                }
            }
        }
        return -1;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, m;
            scanf("%d%d", &n, &m);
            for (int i = 0; i < n; ++i) {
                scanf("%s", graph[i]);
            }
            int res = bfs(0, 0, n, m, n + 1, m + 1);
            if (res == -1) {
                printf("NO SOLUTION\n");
            } else {
                printf("%d\n", res);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0175_H
