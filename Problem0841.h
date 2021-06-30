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
    // unsigned 类型变量溢出后会自动退回0，这里无需取模运算
    void buildHashTable(const char *str,
                        unsigned long long *p,
                        unsigned long long *h,
                        const unsigned long long N,
                        const unsigned long long BASE) {
        p[0] = 1;
        h[0] = 0;
        for (unsigned long long i = 1; i <= N; ++i) {
            p[i] = p[i - 1] * BASE;
            h[i] = h[i - 1] * BASE + str[i - 1];  // 注意，i从1开始，表示字符序号
        }
    }

    unsigned long long hashValue(const unsigned long long start,
                                 const unsigned long long end,
                                 const unsigned long long *p,
                                 const unsigned long long *h) {
        return h[end] - h[start - 1] * p[end - start + 1];
    }

    int main() {
        unsigned long long n, m;
        scanf("%lld%lld", &n, &m);
        auto str = new char[n + 1];
        scanf("%s", str);
        auto p = new unsigned long long[n + 1];
        auto h = new unsigned long long[n + 1];
        const unsigned long long BASE = 131;  // BASE 取 131 或 13331
        buildHashTable(str, p, h, n, BASE);
        unsigned long long l1, r1, l2, r2;
        for (unsigned long long i = 0; i < m; ++i) {
            scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
            if (hashValue(l1, r1, p, h) == hashValue(l2, r2, p, h)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        delete[] str;
        delete[] p;
        delete[] h;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0841_H
