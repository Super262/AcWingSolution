//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM1068_H
#define ACWINGSOLUTION_PROBLEM1068_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1068 {
    // https://www.acwing.com/solution/content/15641/
    // 化环为链，大大降低复杂度
public:
    void printMaxAndMin(const int *weight, const int N) {
        auto prefixSum = new int[2 * N + 1];
        prefixSum[0] = 0;
        for (int i = 1; i <= 2 * N; ++i) {
            prefixSum[i] = prefixSum[i - 1] + weight[i];
        }
        auto dpMax = new int *[2 * N + 1];
        auto dpMin = new int *[2 * N + 1];
        for (int i = 1; i <= 2 * N; ++i) {
            dpMax[i] = new int[2 * N + 1];
            dpMin[i] = new int[2 * N + 1];
            memset(dpMax[i], -1, sizeof(int) * (2 * N + 1));
            memset(dpMin[i], 0x7f, sizeof(int) * (2 * N + 1));
            dpMax[i][i] = 0;
            dpMin[i][i] = 0;
        }
        for (int length = 1; length <= N; ++length) {
            for (int start = 1; start + length - 1 <= 2 * N; ++start) {
                int end = start + length - 1;
                for (int mid = start; mid < end; ++mid) {
                    dpMax[start][end] = max(dpMax[start][end],
                                            dpMax[start][mid] + dpMax[mid + 1][end] + prefixSum[end] -
                                            prefixSum[start - 1]);
                    dpMin[start][end] = min(dpMin[start][end],
                                            dpMin[start][mid] + dpMin[mid + 1][end] + prefixSum[end] -
                                            prefixSum[start - 1]);
                }
            }
        }
        int resultMax = -1;
        int resultMin = 0x7f7f7f7f;
        for (int i = 1; i <= N; ++i) {
            resultMax = max(resultMax, dpMax[i][i + N - 1]);
            resultMin = min(resultMin, dpMin[i][i + N - 1]);
            delete[] dpMax[i];
            delete[] dpMin[i];
        }
        delete[] dpMin;
        delete[] dpMax;
        delete[] prefixSum;
        printf("%d\n", resultMin);
        printf("%d\n", resultMax);
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto weight = new int[2 * n + 1];
        for (int i = 1; i <= n; ++i) {
            int t;
            scanf("%d", &t);
            weight[i] = t;
            weight[i + n] = t;
        }
        printMaxAndMin(weight, n);
        delete[] weight;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1068_H
