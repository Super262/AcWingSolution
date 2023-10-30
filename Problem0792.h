//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0792_H
#define ACWINGSOLUTION_PROBLEM0792_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0792
{
private:
    int cmp_big_int(const string &a, const string &b)
    {
        if (a.size() > b.size())
        {
            return 1;
        }
        if (a.size() < b.size())
        {
            return -1;
        }
        return a.compare(b);
    }

    string subtract_big_int(string a, string b)
    { // 前提：a >= b
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        for (int i = 0, num = 0; i < a.size(); ++i)
        {
            num = (a[i] - '0') - num;
            if (i < b.size())
            {
                num -= b[i] - '0';
            }
            result.push_back((char)('0' + (num + 10) % 10));
            if (num < 0)
            {
                num = 1;
            }
            else
            {
                num = 0;
            }
        }
        while (result.size() > 1 && result.back() == '0')
        { // 注意：result最小长度为1，result最小值为0
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int main()
    {
        string a, b;
        cin >> a >> b;
        auto dis = cmp_big_int(a, b);
        if (dis == 0)
        {
            cout << 0 << endl;
        }
        else if (dis > 0)
        {
            cout << subtract_big_int(a, b) << endl;
        }
        else
        {
            cout << "-" << subtract_big_int(b, a) << endl;
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0792_H
