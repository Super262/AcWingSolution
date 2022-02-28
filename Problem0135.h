//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0135_H
#define ACWINGSOLUTION_PROBLEM0135_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0135 {
private:
    static const int N = 300010;
    int dq[N];
    int a[N];

    int maxSeq(int n, int m) {
        int result = -0x7f7f7f7f;
        int hh = 0, tt = -1;
        for (int i = 0; i <= n; ++i) {  // 从0开始遍历！！
            // 根据题意：窗口长度为(m + 1)
            while (hh <= tt && i - dq[hh] + 1 > m + 1) {
                ++hh;
            }
            if (hh <= tt) {
                result = max(result, a[i] - a[dq[hh]]);
            }
            while (hh <= tt && a[i] <= a[dq[tt]]) {
                --tt;
            }
            dq[++tt] = i;
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        printf("%d\n", maxSeq(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0135_H
