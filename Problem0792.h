//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0792_H
#define ACWINGSOLUTION_PROBLEM0792_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0792 {
public:
    int cmpBigInts(const string &a, const string &b) {
        if (a.size() > b.size()) {
            return 1;
        }
        if (a.size() < b.size()) {
            return -1;
        }
        return a.compare(b);
    }

    string subtractBigInt(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        int num = 0;
        for (unsigned long i = 0; i < a.size(); ++i) {
            num = (a[i] - '0') - num;
            if (i < b.size()) {
                num -= b[i] - '0';
            }
            result.push_back((char) ('0' + ((num + 10) % 10)));
            if (num < 0) {
                num = 1;
            } else {
                num = 0;
            }
        }
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int main() {
        string a, b;
        cin >> a >> b;
        int dis = cmpBigInts(a, b);
        if (dis == 0) {
            cout << 0 << endl;
        } else if (dis > 0) {
            cout << subtractBigInt(a, b) << endl;
        } else {
            cout << "-" << subtractBigInt(b, a) << endl;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0792_H
