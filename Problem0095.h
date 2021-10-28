//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0095_H
#define ACWINGSOLUTION_PROBLEM0095_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0095 {
    // https://www.acwing.com/solution/content/8747/
private:
    const int N = 5;
    char g[N][N + 1], temp[N][N + 1];

    void changeState(const int &x, const int &y) {
        int dy[] = {0, 1, -1, 0, 0};
        int dx[] = {0, 0, 0, 1, -1};
        for (int i = 0; i < 5; i++) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            g[nx][ny] = g[nx][ny] == '1' ? '0' : '1';
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        while (n--) {
            int result = 7;
            for (int i = 0; i < N; i++) {
                scanf("%s", g[i]);
            }
            // 枚举我们对第0行施加的操作
            for (int op = 0; op < (1 << N); op++) {
                // 保存状态
                memcpy(temp, g, sizeof g);
                int curStep = 0;
                for (int i = 0; i < N; i++) {
                    if (((op >> i) & 1) == 0) {
                        continue;
                    }
                    changeState(0, i);
                    curStep++;
                }
                // 根据第i行的状态操作i + 1行
                for (int r = 0; r < N - 1; r++) {
                    for (int c = 0; c < N; c++) {
                        if (g[r][c] == '1') {
                            continue;
                        }
                        changeState(r + 1, c);
                        curStep++;
                    }
                }
                // 检查最后1行是否都为1
                bool allWhite = true;
                for (int i = 0; i < N; ++i) {
                    if (g[N - 1][i] == '1') {
                        continue;
                    }
                    allWhite = false;
                    break;
                }
                // 恢复状态
                memcpy(g, temp, sizeof temp);
                if (!allWhite) {
                    continue;
                }
                result = min(result, curStep);
            }
            if (result > 6) {
                result = -1;
            }
            printf("%d\n", result);
        }
        return 0;
    }
};


#endif //ACWINGSOLUTION_PROBLEM0095_H
