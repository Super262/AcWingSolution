//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM1081_H
#define ACWINGSOLUTION_PROBLEM1081_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1081 {
    // https://www.acwing.com/solution/content/34003/
public:
    vector<vector<int>> initCombinations(const int N) {
        vector<vector<int>> C(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j) {
                    C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                } else {
                    C[i][j] = 1;
                }
            }
        }
        return C;
    }

    int helper(int a, const int K, const int B, const vector<vector<int>> &C) {
        vector<int> nums;
        while (a) {
            nums.emplace_back(a % B);
            a /= B;
        }
        int result = 0;
        int prefixOnesCount = 0;
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            int x = nums[i];
            if (x > 0) {
                result += C[i][K - prefixOnesCount];
                if (x == 1) {
                    ++prefixOnesCount;
                    if (prefixOnesCount > K) {
                        break;  // 不要忘记这个判断
                    }
                } else {
                    if (K - prefixOnesCount - 1 >= 0) {
                        result += C[i][K - prefixOnesCount - 1];
                    }
                    break;
                }
            }
            if (i == 0 && prefixOnesCount == K) {
                ++result;
            }
        }
        return result;
    }

    int main() {
        int x, y, k, b;
        scanf("%d%d%d%d", &x, &y, &k, &b);
        vector<vector<int>> C = initCombinations(32);
        printf("%d\n", helper(y, k, b, C) - helper(x, k, b, C));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1081_H
