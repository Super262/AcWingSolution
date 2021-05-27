//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0078_H
#define ACWINGSOLUTION_PROBLEM0078_H

#include <string>

using namespace std;

class Problem0078 {
public:
    string leftRotateString(const string &str, int n) {
        string result(str.length(), '\0');
        int res_top = 0;
        for (int i = n; i < str.length(); ++i) {
            result[res_top++] = str[i];
        }
        for (int i = 0; i < n; ++i) {
            result[res_top++] = str[i];
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0078_H
