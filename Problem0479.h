//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0479_H
#define ACWINGSOLUTION_PROBLEM0479_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0479 {
private:
    const int N = 31;
    int dp[N][N];
    int rootValue[N][N];
    int scores[N];

    void preOrder(const int start, const int end) {
        if (start > end) {
            return;
        }
        printf("%d ", rootValue[start][end]);
        preOrder(start, rootValue[start][end] - 1);
        preOrder(rootValue[start][end] + 1, end);
    }

    int rangeModel(const int n) {
        for (int length = 1; length <= n; ++length) {
            for (int left = 1; left + length - 1 <= n; ++left) {
                int right = left + length - 1;
                for (int rootIdx = left; rootIdx <= right; ++rootIdx) {
                    int leftS = rootIdx == left ? 1 : dp[left][rootIdx - 1];
                    int rightS = rootIdx == right ? 1 : dp[rootIdx + 1][right];
                    int temp = 0;
                    if (left != right) {
                        temp = leftS * rightS;
                    }
                    temp += scores[rootIdx];
                    if (temp > dp[left][right]) {
                        dp[left][right] = temp;
                        rootValue[left][right] = rootIdx;
                    }
                }
            }
        }
        return dp[1][n];
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &scores[i]);
        }
        printf("%d\n", rangeModel(n));
        preOrder(1, n);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0479_H
