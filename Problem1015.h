//
// Created by Fengwei Zhang on 2021/7/6.
//

#ifndef ACWINGSOLUTION_PROBLEM1015_H
#define ACWINGSOLUTION_PROBLEM1015_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1015 {
private:
    static const int N = 101;
    int graph[N][N];

    int maxValue(const int r, const int c) {
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                graph[i][j] += max(graph[i - 1][j], graph[i][j - 1]);
            }
        }
        return graph[r][c];
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int r, c;
            scanf("%d%d", &r, &c);
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    scanf("%d", &graph[i][j]);
                }
            }
            printf("%d\n", maxValue(r, c));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1015_H
