//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0885_H
#define ACWINGSOLUTION_PROBLEM0885_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0885 {
private:
    int main() {
        const int LENGTH = 2001;
        const int M = 1e9 + 7;
        int combination[LENGTH][LENGTH];
        memset(combination, 0, sizeof combination);
        for (auto &ci: combination) {
            ci[0] = 1;
        }
        for (int i = 1; i < LENGTH; ++i) {
            for (int j = 1; j < LENGTH; ++j) {
                combination[i][j] = (int) (((long long) combination[i - 1][j] + combination[i - 1][j - 1]) % M);
            }
        }
        int n, a, b;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", combination[a][b]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0885_H
