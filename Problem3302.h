//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM3302_H
#define ACWINGSOLUTION_PROBLEM3302_H

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Problem3302
{
private:
    int do_operation(const int &a, const int &b, const char &op)
    {
        if (op == '+')
        {
            return a + b;
        }
        else if (op == '-')
        {
            return a - b;
        }
        else if (op == '*')
        {
            return a * b;
        }
        else if (op == '/')
        {
            return a / b;
        }
        return 0;
    }

    void handle_operators(const char &op,
                          unordered_map<char, char> &preference_in,
                          unordered_map<char, char> &preference_out,
                          stack<int> &nums,
                          stack<char> &operators)
    {
        if (operators.empty() || preference_out[operators.top()] < preference_in[op])
        {
            operators.emplace(op);
            return;
        }
        while (!operators.empty() && preference_out[operators.top()] > preference_in[op])
        {
            auto temp = operators.top();
            operators.pop();
            auto b = nums.top();
            nums.pop();
            auto a = nums.top();
            nums.pop();
            nums.emplace(do_operation(a, b, temp));
        }
        if (!operators.empty() && operators.top() == '(' && op == ')')
        {
            operators.pop();
        }
        else
        {
            operators.emplace(op);
        }
    }

    int calculate(const string &s)
    {
        unordered_map<char, char> preference_in;
        unordered_map<char, char> preference_out;
        stack<int> nums;
        stack<char> operators;
        preference_in['+'] = 2;
        preference_in['-'] = 2;
        preference_in['*'] = 4;
        preference_in['/'] = 4;
        preference_in['('] = 6;
        preference_in[')'] = 1;
        preference_out['+'] = 3;
        preference_out['-'] = 3;
        preference_out['*'] = 5;
        preference_out['/'] = 5;
        preference_out['('] = 1;
        preference_out[')'] = 6;
        bool waiting_next_num = true;
        for (const char &ch : s)
        {
            if (ch >= '0' && ch <= '9')
            {
                if (waiting_next_num)
                {
                    nums.emplace(ch - '0');
                    waiting_next_num = false;
                }
                else
                {
                    auto t = nums.top();
                    nums.pop();
                    t = t * 10 + (ch - '0');
                    nums.emplace(t);
                }
            }
            else
            {
                waiting_next_num = true;
                handle_operators(ch, preference_in, preference_out, nums, operators);
            }
        }
        if (!nums.empty())
        {
            return nums.top();
        }
        return 0;
    }

    int main()
    {
        string s;
        cin >> s;
        cout << calculate("(" + s + ")") << endl;
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM3302_H
