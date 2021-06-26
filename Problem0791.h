//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0791_H
#define ACWINGSOLUTION_PROBLEM0791_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0791 {
public:
    string addBigInt(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        unsigned int carry = 0;
        unsigned int num;
        for (unsigned long i = 0; i < a.size() || i < b.size(); ++i) {
            num = carry;
            if (i < a.size()) {
                num += a[i] - '0';
            }
            if (i < b.size()) {
                num += b[i] - '0';
            }
            carry = num / 10;
            num %= 10;
            result.push_back((char) ('0' + num));
        }

        // 千万别忘记最后的进位！
        if (carry) {
            result.push_back((char) ('0' + carry));
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int main() {
        string a, b;
        cin >> a >> b;
        cout << addBigInt(a, b) << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0791_H
