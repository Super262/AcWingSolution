//
// Created by Fengwei Zhang on 2021/7/19.
//

#ifndef ACWINGSOLUTION_PROBLEM1084_H
#define ACWINGSOLUTION_PROBLEM1084_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem1084 {
public:
    const int N = 11;
    int f[N + 1][10][100];
    int P;

    int mod(const int x, const int m) {
        return (x % m + m) % m;
    }

    void init() {
        memset(f, 0, sizeof f);
        for (int i = 0; i <= 9; ++i) {
            ++f[1][i][mod(i, P)];
        }
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= 9; ++i) {
                for (int k = 0; k < P; ++k) {
                    for (int j = 0; j <= 9; ++j) {
                        f[length][i][k] += f[length - 1][j][mod(k - i, P)];
                    }
                }
            }
        }
    }

    int helper(int a) {
        if (a == 0) {
            return 1;
        }
        vector<int> nums;
        while (a) {
            nums.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prefixSum = 0;
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            int x = nums[i];
            for (int j = 0; j < x; ++j) {
                result += f[i + 1][j][mod(-prefixSum, P)];
            }
            prefixSum += x;
            if (i == 0 && prefixSum % P == 0) {
                ++result;
            }
        }
        return result;
    }

    int main() {
        int a, b;
        while (scanf("%d%d%d", &a, &b, &P) != -1) {
            init();
            printf("%d\n", helper(b) - helper(a - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1084_H
