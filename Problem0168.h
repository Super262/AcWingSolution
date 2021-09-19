//
// Created by Fengwei Zhang on 2021/7/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0168_H
#define ACWINGSOLUTION_PROBLEM0168_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0168 {
    // https://www.acwing.com/solution/content/31876/
private:
    const int INF = 0x7f7f7f7f;
    const int M = 20;
    int minV[M + 2], minS[M + 2];
    int R[M + 2], H[M + 2];

    void dfs(const int currentLevel,
             const int prevVolume,
             const int prevArea,
             const int lowestLevel,
             const int targetVolume,
             int &answer) {
        if (currentLevel == 0) {
            if (prevVolume == targetVolume) {
                answer = min(answer, prevArea);
            }
            return;
        }
        if (prevVolume + minV[currentLevel] > targetVolume) {
            return;
        }
        if (prevArea + minS[currentLevel] >= answer) {
            return;
        }
        if (prevArea + 2 * (targetVolume - prevVolume) / R[currentLevel + 1] >= answer) {
            return;
        }
        // 先处理半径，再处理高（R^2 比 H 对结果影响大）
        for (int r = min(R[currentLevel + 1] - 1,
                         (int) sqrt((targetVolume - prevVolume - minV[currentLevel - 1]) / currentLevel));
             r >= currentLevel; --r) {
            for (int h = min(H[currentLevel + 1] - 1, (targetVolume - prevVolume - minV[currentLevel - 1]) / r / r);
                 h >= currentLevel; --h) {
                R[currentLevel] = r;
                H[currentLevel] = h;
                int topArea = currentLevel == lowestLevel ? r * r : 0;  // 加入顶部的面积（所有层的顶部面积和 == Rm * Rm）
                dfs(currentLevel - 1,
                    prevVolume + r * r * h,
                    prevArea + 2 * r * h + topArea,
                    lowestLevel,
                    targetVolume,
                    answer);
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        R[m + 1] = INF;
        H[m + 1] = INF;
        for (int i = 1; i <= m; ++i) {
            minV[i] = minV[i - 1] + i * i * i;
            minS[i] = minS[i - 1] + 2 * i * i;  // 这里的minS不包含顶部的面积，只有侧面积
        }
        int answer = INF;
        dfs(m, 0, 0, m, n, answer);
        if (answer == INF) {
            printf("0\n");
        } else {
            printf("%d\n", answer);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0168_H
