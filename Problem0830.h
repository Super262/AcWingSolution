//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0830_H
#define ACWINGSOLUTION_PROBLEM0830_H

#include <iostream>
#include <stack>

using namespace std;


class Problem0830 {
public:
    int getClosestSmaller(int num, stack<int> &s) {
        while (!s.empty() && s.top() >= num) {
            s.pop();
        }
        int result = -1;
        if (!s.empty()) {
            result = s.top();
        }
        s.emplace(num);
        return result;

    }

    int main() {
        stack<int> s;
        unsigned long n;
        cin >> n;
        int num;
        for (unsigned long i = 0; i < n; ++i) {
            cin >> num;
            cout << getClosestSmaller(num, s) << " ";
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0830_H
