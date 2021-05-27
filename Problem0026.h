//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0026_H
#define ACWINGSOLUTION_PROBLEM0026_H

class Problem0026 {
public:
    int NumberOf1(int n) {
        int result = 0;
        unsigned int num = n;
        while (num) {
            result += num & 1;
            num >>= 1;
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0026_H
