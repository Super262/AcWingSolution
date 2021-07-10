//
// Created by Fengwei Zhang on 2021/7/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0278_H
#define ACWINGSOLUTION_PROBLEM0278_H

#include <iostream>

using namespace std;

class Problem0278 {
public:
    int main() {
        int N, M;
        scanf("%d%d", &N, &M);
        auto dp = new int[M + 1];
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            int num;
            scanf("%d", &num);
            for (int j = M; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        printf("%d\n", dp[M]);
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0278_H
