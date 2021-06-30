//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0841_H
#define ACWINGSOLUTION_PROBLEM0841_H

#include <iostream>

using namespace std;

class Problem0841 {
    // 我们不能把某个前缀映射成0。否则，不同的字符串（AA和AAAA）可能有相同的哈希值。
public:
    unsigned long long *buildPrefixHashTable(const char s[],
                                             unsigned long long p[],
                                             const unsigned long long n,
                                             const unsigned long long &base) {
        auto *table = new unsigned long long[n + 1];
        table[0] = 0;
        p[0] = 1;
        for (unsigned long long i = 1; i <= n; ++i) {
            table[i] = table[i - 1] * base + s[i - 1];
            p[i] = p[i - 1] * base;
        }
        return table;
    }

    int main() {
        const unsigned long long BASE = 131;
        unsigned long long n, m;
        scanf("%lld%lld", &n, &m);
        auto *p = new unsigned long long[n + 1];
        auto *s = new char[n + 1];
        scanf("%s", s);
        auto *table = buildPrefixHashTable(s, p, n, BASE);
        unsigned long long l1, r1, l2, r2;
        while (m--) {
            scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
            if (table[r1] - table[l1 - 1] * p[r1 - l1 + 1] == table[r2] - table[l2 - 1] * p[r2 - l2 + 1]) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        delete[] p;
        delete[] s;
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0841_H
