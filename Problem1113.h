//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1113_H
#define ACWINGSOLUTION_PROBLEM1113_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1113 {
public:
    char graph[30][30];
    bool isSelected[30][30];
    const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

    int dfs(const int startX, const int startY, const int H, const int W) {
        int result = 1;
        isSelected[startX][startY] = true;
        for (int i = 0; i < 4; ++i) {
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];
            if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= W) {
                continue;
            }
            if (graph[nextX][nextY] == '#' || isSelected[nextX][nextY]) {
                continue;
            }
            result += dfs(nextX, nextY, H, W);
        }
        return result;
    }

    int main() {
        int w, h;
        while (true) {
            scanf("%d%d", &w, &h);
            if (w == 0 || h == 0) {
                break;
            }
            memset(isSelected, 0, sizeof isSelected);
            int startX = 0, startY = 0;
            for (int i = 0; i < h; ++i) {
                scanf("%s", graph[i]);
                for (int j = 0; j < w; ++j) {
                    if (graph[i][j] == '@') {
                        startX = i;
                        startY = j;
                        break;
                    }
                }
            }
            printf("%d\n", dfs(startX, startY, h, w));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1113_H
