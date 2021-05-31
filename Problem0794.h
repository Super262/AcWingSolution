//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0794_H
#define ACWINGSOLUTION_PROBLEM0794_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0794 {
public:
    string divBigInts(const string &a, int b, int &r) {
        r = 0;
        string result;
        for (char ch : a) {
            r = r * 10 + (ch - '0');
            result.push_back((char) ('0' + r / b));
            r %= b;
        }
        reverse(result.begin(), result.end());
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int main() {
        string a;
        int b;
        int r;
        cin >> a >> b;
        cout << divBigInts(a, b, r) << endl;
        cout << r << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0794_H
