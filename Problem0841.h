//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0841_H
#define ACWINGSOLUTION_PROBLEM0841_H

#include <iostream>

using namespace std;

class Problem0841 {
    // 我们不能把某个前缀映射成0。否则，不同的字符串（AA和AAAA）可能有相同的哈希值。
private:
    const int N = 100010;
    const int BASE = 13331;  // BASE 取 131 或 13331
    unsigned long long power[N];
    unsigned long long prefixHashValue[N];
    char str[N];

    void buildHashTable() {
        power[0] = 1;
        prefixHashValue[0] = 0;
        for (int i = 1; str[i - 1]; ++i) {
            power[i] = power[i - 1] * BASE;
            prefixHashValue[i] = prefixHashValue[i - 1] * BASE + str[i - 1];  // 注意，i从1开始，表示字符序号
        }
    }

    unsigned long long hashValue(const int start, const int end) {
        return prefixHashValue[end] - prefixHashValue[start - 1] * power[end - start + 1];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", str);
        buildHashTable();
        for (int i = 0; i < m; ++i) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (hashValue(x1, y1) == hashValue(x2, y2)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0841_H
