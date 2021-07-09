//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0006_H
#define ACWINGSOLUTION_PROBLEM0006_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0006 {
    // https://www.acwing.com/solution/content/6500/
public:
    int main() {
        auto dq = new int[20010];
        int itemsNum, packVolume;
        scanf("%d%d", &itemsNum, &packVolume);
        auto dp = new int[packVolume + 1];
        auto pre = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        memset(pre, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            int v, w, s;
            scanf("%d%d%d", &v, &w, &s);
            memcpy(pre, dp, sizeof(int) * (packVolume + 1));
            for (int j = 0; j < v; ++j) {
                int dqHead = 0;
                int dqTail = -1;
                for (int k = j; k <= packVolume; k += v) {
                    while (dqHead <= dqTail && dq[dqHead] < k - s * v) {
                        // 队头划出大小为s的窗口
                        ++dqHead;
                    }
                    while (dqHead <= dqTail && pre[dq[dqTail]] - (dq[dqTail] - j) / v * w <= pre[k] - (k - j) / v * w) {
                        // 新元素大于队尾，不满足单调下降
                        --dqTail;
                    }
                    if (dqHead <= dqTail) {
                        dp[k] = pre[dq[dqHead]] + (k - dq[dqHead]) / v * w;
                    }
                    dq[++dqTail] = k;
                }
            }
        }
        printf("%d\n", dp[packVolume]);
        delete[] dp;
        delete[] pre;
        delete[] dq;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0006_H
