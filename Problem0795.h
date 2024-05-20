//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0795_H
#define ACWINGSOLUTION_PROBLEM0795_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0795
{
private:
    vector<int> GetPrefixSum(const vector<int> &arr)
    {
        vector<int> result(arr.size() + 1, 0);
        for (int i = 1; i < result.size(); ++i)
        {
            result[i] = result[i - 1] + arr[i - 1];
        }
        return result;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        const auto &arr_prefix_sum = GetPrefixSum(arr);
        for (int i = 0, l, r; i < m; ++i)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", arr_prefix_sum[r] - arr_prefix_sum[l - 1]);
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0795_H
