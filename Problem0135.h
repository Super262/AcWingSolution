//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0135_H
#define ACWINGSOLUTION_PROBLEM0135_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0135 {
public:
    int maxSeq(const int *prefixSum, const int N, const int M) {
        int *q = new int[2 * N];
        int hh = 0;
        int tt = 0;  // tt初始值为0，相当于队列包含初识元素0，简化了后续步骤
        int result = -0x7f7f7f7f;
        for (int i = 1; i <= N; ++i) {
            if (hh <= tt && i - q[hh] > M) {
                ++hh;
            }
            result = max(result, prefixSum[i] - prefixSum[q[hh]]);
            while (hh <= tt && prefixSum[q[tt]] >= prefixSum[i]) {
                --tt;
            }
            q[++tt] = i;
        }
        delete[] q;
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto a = new int[n + 1];
        memset(a, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        printf("%d\n", maxSeq(a, n, m));
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0135_H
