//
// Created by Fengwei Zhang on 2021/7/19.
//

#ifndef ACWINGSOLUTION_PROBLEM1085_H
#define ACWINGSOLUTION_PROBLEM1085_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1085 {
private:
    static const int N = 10;
    int f[N + 1][10];

    void init() {
        for (int i = 0; i <= 9; ++i) {
            if (i == 4) {
                continue;
            }
            f[1][i] = 1;
        }
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= 9; ++i) {
                if (i == 4) {
                    continue;
                }
                for (int j = 0; j <= 9; ++j) {
                    if (j == 4 || (i == 6 && j == 2)) {
                        continue;
                    }
                    f[length][i] += f[length - 1][j];
                }
            }
        }
    }

    int dp(int a) {
        if (a == 0) {
            return 1;
        }
        vector<int> digits;
        while (a) {
            digits.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prev = 0;
        for (auto i = (int) digits.size() - 1; i >= 0; --i) {
            const auto &x = digits[i];
            for (int j = 0; j < x; ++j) {
                if (j == 4 || (prev == 6 && j == 2)) {
                    continue;
                }
                result += f[i + 1][j];
            }
            if (x == 4 || (prev == 6 && x == 2)) {
                break;
            }
            prev = x;
            if (i == 0) {
                ++result;
            }
        }
        return result;
    }

    int main() {
        init();
        int n, m;
        while (true) {
            scanf("%d%d", &n, &m);
            if (n == 0 || m == 0) {
                break;
            }
            printf("%d\n", dp(m) - dp(n - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1085_H
