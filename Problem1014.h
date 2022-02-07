//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1014_H
#define ACWINGSOLUTION_PROBLEM1014_H

#include <iostream>

using namespace std;


class Problem1014 {
private:
    static const int N = 1000;
    int height[N];
    int lisLength[N];
    int ldsLength[N];

    int maxRange(const int n) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            lisLength[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (height[j] >= height[i]) {
                    continue;
                }
                lisLength[i] = max(lisLength[j] + 1, lisLength[i]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            ldsLength[i] = 1;
            for (int j = n - 1; j > i; --j) {
                if (height[j] >= height[i]) {
                    continue;
                }
                ldsLength[i] = max(ldsLength[j] + 1, ldsLength[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            result = max(result, ldsLength[i] + lisLength[i] - 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &height[i]);
        }
        printf("%d\n", maxRange(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1014_H
