//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0793_H
#define ACWINGSOLUTION_PROBLEM0793_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0793 {
private:
    string MulBigInts(string &a, int b) {
        reverse(a.begin(), a.end());
        string result;
        int i = 0;
        int t = 0;
        while (i < a.size() || t != 0) {
            if (i < a.size()) {
                t += (a[i] - '0') * b;
                ++i;
            }
            result.push_back((char) ('0' + t % 10));
            t /= 10;
        }
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int main() {
        string a;
        int b;
        cin >> a >> b;
        cout << MulBigInts(a, b) << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0793_H
