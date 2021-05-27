//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0087_H
#define ACWINGSOLUTION_PROBLEM0087_H

#include <string>

using namespace std;

class Solution {
public:
    int strToInt(const string &str) {

        // 处理空字符串
        int i = 0;
        while (i < str.length() && str[i] == ' ') {
            ++i;
        }
        if (i == str.length()) {
            return 0;
        }

        long result = 0;
        bool is_negative = false;

        // 处理先导符号
        if (str[i] == '-') {
            is_negative = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        // 处理前导零
        while (i < str.length() && (str[i] == '0')) {
            ++i;
        }

        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            result *= 10;
            result += str[i] - '0';
            ++i;
        }

        if (is_negative) {
            result = -result;
        }
        if (result >= INT_MAX) {
            return INT_MAX;
        }
        if (result <= INT_MIN) {
            return INT_MIN;
        }
        return (int) result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0087_H
