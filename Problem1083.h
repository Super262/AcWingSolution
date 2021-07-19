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
public:
    const int N = 11;
    int f[N + 1][10];

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

    int helper(int a) {
        vector<int> nums;
        while (a) {
            nums.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prevNum = -2;  // 初始值，使0～9都能被选中
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            int x = nums[i];
            for (int j = (i == nums.size() - 1 ? 1 : 0); j < x; ++j) {
                if (abs(j - prevNum) < 2) {
                    continue;
                }
                result += f[i + 1][j];
            }
            if (abs(x - prevNum) < 2) {
                break;
            }
            prevNum = x;
            if (i == 0) {
                ++result;
            }
        }

        // 长度小于nums.size()的数字
        for (int length = 1; length < nums.size(); ++length) {
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
        printf("%d\n", helper(b) - helper(a - 1));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1083_H
