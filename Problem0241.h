//
// Created by Fengwei Zhang on 9/20/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0241_H
#define ACWINGSOLUTION_PROBLEM0241_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0241 {
    // https://www.acwing.com/solution/content/13818/
    // https://halfrost.com/binary_indexed_tree/
    // 输入序列中的最大值（树状数组索引的上限） <= 输入序列的长度（n）
private:
    static const int N = 200010;
    int height[N];
    int fenwickTable[N];  // 树状数组的索引从1开始
    int leftGre[N], leftLess[N], rightGre[N], rightLess[N];

    int low_bit(const int x) {
        return x & -x;
    }

    void updateItem(const int idx, const int val, const int n) {
        for (int i = idx; i <= n; i += low_bit(i)) {
            fenwickTable[i] += val;
        }
    }

    int prefixSum(const int idx) {
        int result = 0;
        for (int i = idx; i > 0; i -= low_bit(i)) {
            result += fenwickTable[i];
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &height[i]);
        }
        for (int i = 1; i <= n; ++i) {
            auto y = height[i];
            leftGre[i] = prefixSum(n) - prefixSum(y);
            leftLess[i] = prefixSum(y - 1);
            updateItem(y, 1, n);
        }
        memset(fenwickTable, 0, sizeof fenwickTable);
        for (int i = n; i > 0; --i) {
            auto y = height[i];
            rightGre[i] = prefixSum(n) - prefixSum(y);
            rightLess[i] = prefixSum(y - 1);
            updateItem(y, 1, n);
        }
        long long resV = 0, resA = 0;
        for (int i = 1; i <= n; ++i) {
            resA += (long long) leftLess[i] * rightLess[i];
            resV += (long long) leftGre[i] * rightGre[i];
        }
        printf("%lld %lld\n", resV, resA);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0241_H
