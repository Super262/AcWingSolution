//
// Created by Fengwei Zhang on 10/30/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0100_H
#define ACWINGSOLUTION_PROBLEM0100_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0100 {
    // 设b[1:n+1]为差分数组，最后的状态是b1=a, b[2:n]全0，b[n+1]为任意值
    // https://www.acwing.com/solution/content/5060/
private:
    int main() {
        int n;
        scanf("%d", &n);
        int arr[n + 2];
        memset(arr, 0, sizeof arr);
        int x;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            arr[i] += x;
            arr[i + 1] -= x;
        }
        long long pos_sum = 0;  // 正数的和
        long long neg_sum = 0;  // 负数绝对值的和
        for (int i = 2; i <= n; ++i) {
            if (arr[i] > 0) {
                pos_sum += (long long) arr[i];
            } else {
                neg_sum += -((long long) arr[i]);
            }
        }
        printf("%lld\n", min(pos_sum, neg_sum) + abs(pos_sum - neg_sum));
        // 如果剩下3个数没有处理掉那么左边有0 1 2 3 对应的右边 3 2 1 0 一共是3+1也就是abs(p-q)+1种可能
        printf("%lld\n", abs(pos_sum - neg_sum) + 1);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0100_H
