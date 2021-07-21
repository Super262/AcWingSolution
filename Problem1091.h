//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1091_H
#define ACWINGSOLUTION_PROBLEM1091_H

#include <iostream>

using namespace std;

class Problem1091 {
    // https://www.acwing.com/solution/content/12800/
public:
    const int N = 1000;
    int matrix[N + 1][N + 1];
    int q[N + 1];

    void maxInRow(const int row[], int maximal[], const int n, const int k) {
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; i++) {
            if (hh <= tt && q[hh] <= i - k) hh++;
            while (hh <= tt && row[q[tt]] <= row[i]) tt--;

            q[++tt] = i;
            //因为第i个元素也可能包含，所以最后再处理
            maximal[i] = row[q[hh]];
        }
    }

    void minInRow(const int row[], int minimal[], const int n, const int k) {
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; i++) {
            if (hh <= tt && q[hh] < i - k + 1) hh++;
            while (hh <= tt && row[q[tt]] >= row[i]) tt--;
            q[++tt] = i;
            minimal[i] = row[q[hh]];
        }
    }

    int minPart(const int a, const int b, const int k) {
        int rowMinimal[a + 1][b + 1];
        int rowMaximal[a + 1][b + 1];
        for (int i = 1; i <= a; ++i) {
            maxInRow(matrix[i], rowMaximal[i], b, k);
            minInRow(matrix[i], rowMinimal[i], b, k);
        }
        int result = 1e9;
        int windowMaximal[a + 1];
        int windowMinimal[a + 1];
        int temp[N + 1];
        for (int j = k; j <= b; ++j) {
            for (int i = 1; i <= a; ++i) {
                temp[i] = rowMaximal[i][j];
            }
            maxInRow(temp, windowMaximal, a, k);
            for (int i = 1; i <= a; ++i) {
                temp[i] = rowMinimal[i][j];
            }
            minInRow(temp, windowMinimal, a, k);
            for (int i = k; i <= a; ++i) {
                result = min(result, windowMaximal[i] - windowMinimal[i]);
            }
        }
        return result;
    }

    int main() {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", minPart(a, b, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1091_H
