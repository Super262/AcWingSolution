//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0016_H
#define ACWINGSOLUTION_PROBLEM0016_H

#include <string>

class Problem0016 {
public:
    std::string replaceSpaces(std::string &str) {
        std::string result;
        for (char &ch : str) {
            if (ch == ' ') {
                result.push_back('%');
                result.push_back('2');
                result.push_back('0');
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0016_H
