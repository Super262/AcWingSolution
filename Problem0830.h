//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0830_H
#define ACWINGSOLUTION_PROBLEM0830_H

#include <iostream>
#include <stack>

using namespace std;

class Problem0830
{
private:
    int closest_smaller(stack<int> &s, const int &num)
    {
        while (!s.empty() && s.top() >= num)
        {
            s.pop();
        }
        int result;
        if (s.empty())
        {
            result = -1;
        }
        else
        {
            result = s.top();
        }
        s.emplace(num);
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        stack<int> s;
        for (int i = 0, num; i < n; ++i)
        {
            scanf("%d", &num);
            printf("%d ", closest_smaller(s, num));
        }
        printf("\n");
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0830_H
