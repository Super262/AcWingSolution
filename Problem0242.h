//
// Created by Fengwei Zhang on 9/21/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0242_H
#define ACWINGSOLUTION_PROBLEM0242_H

#include <iostream>

using namespace std;

class Problem0242 {
    // 差分数组（树状数组）
    // https://www.acwing.com/solution/content/1429/
private:
    const int N = 100010;
    int fenwickTable[N];

    int lowBit(const int x) {
        return x & -x;
    }

    void updateItem(const int idx, const int val, const int n) {
        for (int i = idx; i <= n; i += lowBit(i)) {
            fenwickTable[i] += val;
        }
    }

    int prefixSum(const int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            res += fenwickTable[i];
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int t;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &t);
            updateItem(i, t, n);
            updateItem(i + 1, -t, n);
        }
        int x1, x2, d;
        char op[2];
        for (int i = 0; i < m; ++i) {
            scanf("%s%d", op, &x1);
            if (op[0] == 'C') {
                scanf("%d%d", &x2, &d);
                updateItem(x1, d, n);
                updateItem(x2 + 1, -d, n);
            } else {
                printf("%d\n", prefixSum(x1));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0242_H
