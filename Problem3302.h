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
        }
        if (op == '-') {
            return a - b;
        }
        if (op == '*') {
            return a * b;
        }
        if (op == '/') {
            return a / b;
        }
        return 0;
    }

    void dealWithOperators(const char op,
                           const unordered_map<char, char> &preferenceIn,
                           const unordered_map<char, char> &preferenceOut,
                           stack<int> &nums,
                           stack<char> &operators) {
        if (operators.empty() || preferenceOut.find(operators.top())->second < preferenceIn.find(op)->second) {
            operators.emplace(op);
            return;
        }
        while (!operators.empty() && preferenceOut.find(operators.top())->second > preferenceIn.find(op)->second) {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            nums.emplace(doOperation(a, b, operators.top()));
            operators.pop();
        }
        if (preferenceOut.find(operators.top())->second != preferenceIn.find(op)->second) {
            operators.emplace(op);
        } else {
            operators.pop();
        }
    }

    int calculate(const string &s) {
        unordered_map<char, char> preferenceIn;
        unordered_map<char, char> preferenceOut;
        preferenceIn['+'] = 2;
        preferenceIn['-'] = 2;
        preferenceIn['/'] = 4;
        preferenceIn['*'] = 4;
        preferenceIn['('] = 6;
        preferenceIn[')'] = 1;
        preferenceOut['+'] = 3;
        preferenceOut['-'] = 3;
        preferenceOut['/'] = 5;
        preferenceOut['*'] = 5;
        preferenceOut['('] = 1;
        preferenceOut[')'] = 6;
        stack<int> nums;
        stack<char> operators;
        bool waitingForNums = true;
        for (char ch:s) {
            if (ch >= '0' && ch <= '9') {
                if (waitingForNums) {
                    nums.emplace(ch - '0');
                    waitingForNums = false;
                } else {
                    int t = nums.top();
                    nums.pop();
                    t = 10 * t + (ch - '0');
                    nums.emplace(t);
                }
            } else {
                waitingForNums = true;
                dealWithOperators(ch, preferenceIn, preferenceOut, nums, operators);
            }
        }
        if (nums.empty()) {
            return 0;
        }
        return nums.top();
    }

    int main() {
        string s;
        getline(cin, s);
        cout << calculate("(" + s + ")") << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM3302_H
