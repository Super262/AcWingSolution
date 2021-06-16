//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0892_H
#define ACWINGSOLUTION_PROBLEM0892_H

#include <iostream>

using namespace std;

class Problem0892 {
public:
    bool canWin(const unsigned int *stairs, const unsigned int n) {
        // 若 a(1) ^ a(3) ^ ... a(2 * k + 1) != 0 成立，先手必胜；反之，先手必败
        unsigned int result = 0;
        for (unsigned int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                continue;
            }
            result ^= stairs[i - 1];
        }
        return result != 0;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto stairs = new unsigned int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &stairs[i]);
        }
        if (canWin(stairs, n)) {
            puts("Yes");
        } else {
            puts("No");
        }
        delete[] stairs;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0892_H
