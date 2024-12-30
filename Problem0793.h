//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0793_H
#define ACWINGSOLUTION_PROBLEM0793_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0793
{
    // 类比LeetCode 43（字符串相乘：延迟进位）
private:
    string MulBigInt(string a, size_t b)
    {
        reverse(a.begin(), a.end());

        string result;
        result.reserve(a.size());
        for (size_t i = 0, carry = 0; i < a.size() || carry;)
        {
            if (i < a.size())
            {
                carry += (a[i] - '0') * b;
                ++i;
            }
            result.push_back((char)('0' + carry % 10));
            carry /= 10;
        }

        while (result.size() > 1 && result.back() == '0')
        {
            result.pop_back();
        }
        reverse(result.begin(), result.end());

        return result;
    }

    int main()
    {
        string a;
        size_t b;
        cin >> a >> b;
        cout << MulBigInt(a, b) << endl;
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0793_H
