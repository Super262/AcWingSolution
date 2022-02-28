//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0154_H
#define ACWINGSOLUTION_PROBLEM0154_H

#include <iostream>

class Problem0154 {
private:
    static const int N = 1000010;
    int a[N];
    int dq[N];

    void printMax(int n, int k) {
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

    void printMin(int n, int k) {
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
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printMin(n, k);
        printMax(n, k);
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0154_H
