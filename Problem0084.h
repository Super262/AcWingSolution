//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0084_H
#define ACWINGSOLUTION_PROBLEM0084_H

class Problem0084 {
public:
    int getSum(int n) {
        if (n == 1) {
            return 1;
        }
        return n + getSum(n - 1);
    }
};

#endif //ACWINGSOLUTION_PROBLEM0084_H
