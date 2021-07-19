//
// Created by Fengwei Zhang on 2021/7/18.
//

#ifndef ACWINGSOLUTION_PROBLEM1082_H
#define ACWINGSOLUTION_PROBLEM1082_H

#include <iostream>
#include <vector>

using namespace std;


class problem1082 {
// https://www.acwing.com/solution/content/33446/
public:
    const int N = 10;
    int dp[N + 1][10];

    void init() {
        for (int i = 0; i <= 9; ++i) {
            dp[1][i] = 1;
        }
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= 9; ++i) {
                for (int j = i; j <= 9; ++j) {
                    dp[length][i] += dp[length - 1][j];
                }
            }
        }
    }

    int helper(int a) {
        if (a == 0) {
            return 1;  // 特殊情况！！
        }
        vector<int> nums;
        while (a) {
            nums.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prevMax = 0;
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            int x = nums[i];
            if (x < prevMax) {
                break;
            }
            for (int j = prevMax; j < x; ++j) {
                result += dp[i + 1][j];
            }
            prevMax = x;
            if (i == 0) {
                ++result;  // 将输入值（a）也添加到结果集中
            }
        }
        return result;
    }

    int main() {
        int a, b;
        init();
        while (scanf("%d%d", &a, &b) != -1) {
            printf("%d\n", helper(b) - helper(a - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1082_H
