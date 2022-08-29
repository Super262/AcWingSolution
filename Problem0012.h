//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0012_H
#define ACWINGSOLUTION_PROBLEM0012_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0012 {
    // 求具体方案时，不能使用压缩空间后的DP数组
    // f[i][j]：从第i个元素到最后一个元素总容量为j的最优解；这样可以反序求最优解，保证字典序最小：可以选择第1个物品时，一定要选上
    // https://www.acwing.com/solution/content/2687/
private:
    struct Item {
        int v;
        int w;
    };

    void knapsack(Item items[], const int n, const int m) {
        int f[n + 2][m + 1];
        memset(f, 0, sizeof f);
        for (int i = n; i >= 1; --i) {
            for (int j = m; j >= 0; --j) {  // 体积从0开始循环，不能跳过[0, items[i].v)
                f[i][j] = f[i + 1][j];
                if (j < items[i].v) {
                    continue;
                }
                f[i][j] = max(f[i][j], f[i + 1][j - items[i].v] + items[i].w);
            }
        }
        auto current_v = m;
        for (int i = 1; i <= n; ++i) {
            if (current_v < items[i].v || f[i][current_v] != f[i + 1][current_v - items[i].v] + items[i].w) {
                continue;
            }
            printf("%d ", i);
            current_v -= items[i].v;
        }
        printf("\n");
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        Item items[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &items[i].v, &items[i].w);
        }
        knapsack(items, n, m);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0012_H
