//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0154_H
#define ACWINGSOLUTION_PROBLEM0154_H

#include <iostream>

class Problem0154 {
private:
    void printMax(int n, int k, int *a, int *dq) {
        int hh = 0, tt = -1;
        for (int i = 0; i < n; ++i) {
            while (hh <= tt && i - k + 1 > dq[hh]) {
                ++hh;
            }
            while (hh <= tt && a[i] >= a[dq[tt]]) {
                --tt;
            }
            dq[++tt] = i;
            if (i + 1 >= k) {
                printf("%d ", a[dq[hh]]);
            }
        }
        printf("\n");
    }

    void printMin(int n, int k, int *a, int *dq) {
        int hh = 0, tt = -1;
        for (int i = 0; i < n; ++i) {
            while (hh <= tt && i - k + 1 > dq[hh]) {
                ++hh;
            }
            while (hh <= tt && a[i] <= a[dq[tt]]) {
                --tt;
            }
            dq[++tt] = i;
            if (i + 1 >= k) {
                printf("%d ", a[dq[hh]]);
            }
        }
        printf("\n");
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        int a[n];
        int dq[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printMin(n, k, a, dq);
        printMax(n, k, a, dq);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0154_H
