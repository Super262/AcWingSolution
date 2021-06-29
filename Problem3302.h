//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM3302_H
#define ACWINGSOLUTION_PROBLEM3302_H

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Problem3302 {
public:
    int doOperation(const int a, const int b, const char op) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        } else if (op == '*') {
            return a * b;
        } else if (op == '/') {
            return a / b;
        }
        return 0;
    }

    void dealOperators(const char op, unordered_map<char,char> &preferenceIn, unordered_map<char,char> &preferenceOut, stack<int> &nums, stack<char> &operators) {
        if (operators.empty() || preferenceOut[operators.top()] < preferenceIn[op]) {
            operators.emplace(op);
            return;
        }
        while (!operators.empty() && preferenceOut[operators.top()] > preferenceIn[op]) {
            char temp = operators.top();
            operators.pop();
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            nums.emplace(doOperation(a, b, temp));
        }
        if(operators.empty() || preferenceOut[operators.top()] != preferenceIn[op]) {
            operators.emplace(op);
        } else {
            operators.pop();
        }
    }

    int calculate(const string &s) {
        unordered_map<char,char> preferenceIn;
        unordered_map<char,char> preferenceOut;
        stack<int> nums;
        stack<char> operators;
        preferenceIn['+'] = 2;
        preferenceIn['-'] = 2;
        preferenceIn['*'] = 4;
        preferenceIn['/'] = 4;
        preferenceIn['('] = 6;
        preferenceIn[')'] = 1;
        preferenceOut['+'] = 3;
        preferenceOut['-'] = 3;
        preferenceOut['*'] = 5;
        preferenceOut['/'] = 5;
        preferenceOut['('] = 1;
        preferenceOut[')'] = 6;
        bool waitingNum = true;
        for (const char ch : s) {
            if (ch >= '0' && ch <= '9') {
                if (waitingNum) {
                    nums.emplace(ch - '0');
                    waitingNum = false;
                } else {
                    auto t = nums.top();
                    nums.pop();
                    t = t * 10 + (ch - '0');
                    nums.emplace(t);
                }
            } else {
                waitingNum = true;
                dealOperators(ch, preferenceIn, preferenceOut, nums, operators);
            }
        }
        if (!nums.empty()) {
            return nums.top();
        }
        return 0;
    }

    int main() {
        string s;
        cin >> s;
        cout << calculate("(" + s + ")") << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM3302_H
