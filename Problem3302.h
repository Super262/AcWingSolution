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
    int my_eval(char op, int x, int y)
    {
        if (op == '+')
            return x + y;
        if (op == '-')
            return x - y;
        if (op == '*')
            return x * y;
        if (op == '/')
            return x / y;
        return 0;
    }

    int main()
    {
        stack<int> nums;
        stack<char> ops;
        int pri[256] = {0};
        string s;
        int t = -1, x, y, z;
    
        pri['+'] = 1;
        pri['-'] = 1;
        pri['*'] = 2;
        pri['/'] = 2;
        
        cin >> s;
        
        for (const char &ch : s)
        {
            if (ch == '(')
            {
                if (t != -1)
                {
                    nums.emplace(t);
                    t = -1;
                }
                ops.emplace(ch);
            }
            else if (ch == ')')
            {
                if (t != -1)
                {
                    nums.emplace(t);
                    t = -1;
                }
                while (ops.size() && ops.top() != '(')
                {
                    y = nums.top();
                    nums.pop();
                    x = nums.top();
                    nums.pop();
                    z = my_eval(ops.top(), x, y);
                    ops.pop();
                    nums.emplace(z);
                }
                ops.pop();
            }
            else if (ch >= '0' && ch <= '9')
            {
                if (t == -1)
                    t = ch - '0';
                else
                    t = t * 10 + (ch - '0');
            }
            else
            {
                if (t != -1)
                {
                    nums.emplace(t);
                    t = -1;
                }
                while (ops.size() && pri[ops.top()] >= pri[ch])
                {
                    y = nums.top();
                    nums.pop();
                    x = nums.top();
                    nums.pop();
                    z = my_eval(ops.top(), x, y);
                    ops.pop();
                    nums.emplace(z);
                }
                ops.emplace(ch);
            }
        }
        
        // 处理残余数字
        if (t != -1)
            nums.emplace(t);
        
        // 处理残余的运算符
        while (ops.size())
        {
            y = nums.top();
            nums.pop();
            x = nums.top();
            nums.pop();
            z = my_eval(ops.top(), x, y);
            ops.pop();
            nums.emplace(z);
        }
    
        printf("%d\n", nums.top());
        
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM3302_H
