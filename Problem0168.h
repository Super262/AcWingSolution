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
    static const int M = 20;
    int minS[M + 2], minV[M + 2];
    int R[M + 2], H[M + 2];
    const int INF = 0x3f3f3f3f;

    void dfs(int currentL, int prevV, int prevS, int lowestL, int targetV, int &answer) {
        if (currentL == 0) {
            if (prevV == targetV) {
                answer = min(answer, prevS);
            }
            return;
        }
        if (prevV + minV[currentL] > targetV) {
            return;
        }
        if (prevS + minS[currentL] >= answer) {
            return;
        }
        if (prevS + 2 * (targetV - prevV) / R[currentL + 1] >= answer) {
            return;
        }
        for (int r = min(R[currentL + 1] - 1, (int) sqrt((targetV - prevV - minV[currentL - 1]) / currentL));
             r >= currentL; --r) {
            for (int h = min(H[currentL + 1] - 1, (targetV - prevV - minV[currentL - 1]) / r / r); h >= currentL; --h) {
                R[currentL] = r;
                H[currentL] = h;
                int topS = currentL == lowestL ? r * r : 0;  // 所有层的顶部面积和 = Rm * Rm
                dfs(currentL - 1, prevV + r * r * h, prevS + 2 * r * h + topS, lowestL, targetV, answer);
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            minV[i] = minV[i - 1] + i * i * i;
            minS[i] = minS[i - 1] + 2 * i * i;  // 不包括顶部面积
        }
        R[m + 1] = H[m + 1] = INF;
        int answer = INF;
        dfs(m, 0, 0, m, n, answer);
        if (answer == INF) {
            answer = 0;
        }
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0168_H
