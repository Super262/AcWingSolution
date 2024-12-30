//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0791_H
#define ACWINGSOLUTION_PROBLEM0791_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0791
{
private:
    string AddBigInt(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result;
        unsigned char carry = 0;
        for (size_t i = 0; i < a.size() || i < b.size(); ++i)
        {
            if (i < a.size())
            {
                carry += a[i] - '0';
            }
            if (i < b.size())
            {
                carry += b[i] - '0';
            }
            result.push_back((char)('0' + carry % 10));
            carry /= 10;
        }

        // 千万别忘记最后的进位！
        if (carry)
        {
            result.push_back((char)('0' + carry));
        }
        reverse(result.begin(), result.end());

        return result;
    }

    int main()
    {
        string a, b;
        cin >> a >> b;
        cout << AddBigInt(a, b) << endl;
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0791_H
