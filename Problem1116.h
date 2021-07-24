//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1116_H
#define ACWINGSOLUTION_PROBLEM1116_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1116 {
public:
    bool visited[10][10];
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, -1, 1, -1, 1};

    void dfs(const int startX, const int startY, const int currentCount, const int n, const int m, int &answer) {
        if (currentCount == n * m) {
            ++answer;
            return;
        }
        visited[startX][startY] = true;
        for (int i = 0; i < 8; ++i) {
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];
            if (nextX < 0 || nextX >= n || nextY < 0 | nextY >= m) {
                continue;
            }
            if (visited[nextX][nextY]) {
                continue;
            }
            dfs(nextX, nextY, currentCount + 1, n, m, answer);
        }
        visited[startX][startY] = false;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, m, startX, startY;
            scanf("%d%d%d%d", &n, &m, &startX, &startY);
            int answer = 0;
            memset(visited, 0, sizeof visited);
            dfs(startX, startY, 1, n, m, answer);
            printf("%d\n", answer);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1116_H
