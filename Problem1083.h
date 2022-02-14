//
// Created by Fengwei Zhang on 2021/7/19.
//

#ifndef ACWINGSOLUTION_PROBLEM1083_H
#define ACWINGSOLUTION_PROBLEM1083_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Problem1083 {
    // 我们规定0不合法
private:
    static const int N = 11;
    int f[N + 1][10];  // f[i][j]：长度为i、最高位为j的Windy数的个数

    void init() {
        for (int i = 0; i <= 9; ++i) {
            f[1][i] = 1;
        }
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= 9; ++i) {
                for (int j = 0; j <= 9; ++j) {
                    if (abs(i - j) < 2) {
                        continue;
                    }
                    f[length][i] += f[length - 1][j];
                }
            }
        }
    }

    int dp(int a) {
        if (!a) {
            return 0;
        }
        vector<int> digits;
        while (a) {
            digits.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prev = -2;  // 上个高位：初始值为-2，使0～9都能被选中（abs(x - prev) >= 2）
        for (auto i = (int) digits.size() - 1; i >= 0; --i) {  // 统计长度为digits.size()的Windy数，没有前导零
            const auto &x = digits[i];
            for (int j = (i == (int) digits.size() - 1 ? 1 : 0); j < x; ++j) {  // 若是最高位，候选值j从1开始
                if (abs(j - prev) < 2) {
                    continue;
                }
                result += f[i + 1][j];
            }
            if (abs(x - prev) < 2) {
                break;
            }
            prev = x;
            if (i == 0) {
                ++result;
            }
        }

        // 长度小于digits.size()的数字
        for (int length = 1; length < (int) digits.size(); ++length) {
            for (int j = 1; j <= 9; ++j) {
                result += f[length][j];
            }
        }
        return result;
    }

    int main() {
        init();
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dp(b) - dp(a - 1));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1083_H
