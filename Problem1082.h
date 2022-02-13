//
// Created by Fengwei Zhang on 2021/7/18.
//

#ifndef ACWINGSOLUTION_PROBLEM1082_H
#define ACWINGSOLUTION_PROBLEM1082_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1082 {
    // https://www.acwing.com/solution/content/33446/
private:
    static const int N = 10;
    int f[N + 1][10];  // f[i][j]：共有i位，且最高位为j的不降数的个数

    void init() {
        for (int i = 0; i <= 9; ++i) {
            f[1][i] = 1;
        }
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= 9; ++i) {
                for (int j = i; j <= 9; ++j) {
                    f[length][i] += f[length - 1][j];
                }
            }
        }
    }

    int dp(int a) {
        if (a == 0) {
            return 1;  // 特殊情况！！
        }
        vector<int> digits;
        while (a) {
            digits.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prev = 0;
        for (int i = (int) digits.size() - 1; i >= 0; --i) {
            int x = digits[i];
            if (x < prev) {  // 当前位比前位小，无需后续处理
                break;
            }
            for (int j = prev; j < x; ++j) {  // 汇总当前位为j（j < x）的所有结果
                result += f[i + 1][j];
            }
            prev = x;
            if (i == 0) {  // 说明a本身是不降数
                ++result;  // 将输入值（a）也添加到结果集中
            }
        }
        return result;
    }

    int main() {
        int a, b;
        init();
        while (scanf("%d%d", &a, &b) != -1) {
            printf("%d\n", dp(b) - dp(a - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1082_H
