//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0795_H
#define ACWINGSOLUTION_PROBLEM0795_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0795 {
public:
    vector<int> getPrefixSum(const vector<int> &a) {
        vector<int> result(a.size() + 1, 0);
        for (unsigned long i = 1; i < result.size(); ++i) {
            result[i] = result[i - 1] + a[i - 1];
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        vector<int> prefixSum = getPrefixSum(arr);
        int l, r;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &l, &r);
            printf("%d\n", prefixSum[r] - prefixSum[l - 1]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0795_H
