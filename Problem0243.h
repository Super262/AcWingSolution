//
// Created by Fengwei Zhang on 9/21/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0243_H
#define ACWINGSOLUTION_PROBLEM0243_H

#include <iostream>

using namespace std;

class Problem0243 {
    // https://www.acwing.com/solution/content/44886/
private:
    const int N = 100010;
    long long ft1[N], ft2[N], nums[N];

    int lowBit(const int x) {
        return x & -x;
    }

    void updateItem(long long ft[], const int idx, const long long val, const int n) {
        for (auto i = idx; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }

    long long prefixSum(const long long ft[], const int idx) {
        long long res = 0;
        for (auto i = idx; i > 0; i -= lowBit(i)) {
            res += ft[i];
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &nums[i]);
        }
        for (int i = 1; i <= n; ++i) {
            int d = nums[i] - nums[i - 1];
            updateItem(ft1, i, d, n);
            updateItem(ft2, i, (long long) d * i, n);
        }
        char op[2];
        int x1, x2, d;
        for (int i = 0; i < m; ++i) {
            scanf("%s%d%d", op, &x1, &x2);
            if (op[0] == 'Q') {
                printf("%lld\n", (prefixSum(ft1, x2) * (x2 + 1) - prefixSum(ft2, x2)) -
                                 (prefixSum(ft1, x1 - 1) * x1 - prefixSum(ft2, x1 - 1)));
            } else {
                scanf("%d", &d);
                updateItem(ft1, x1, d, n);
                updateItem(ft2, x1, (long long) x1 * d, n);
                updateItem(ft1, x2 + 1, -d, n);
                updateItem(ft2, x2 + 1, -(long long) (x2 + 1) * d, n);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0243_H
