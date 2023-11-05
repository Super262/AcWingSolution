//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0841_H
#define ACWINGSOLUTION_PROBLEM0841_H

#include <iostream>

using namespace std;

class Problem0841
{
    // 我们不能把某个前缀映射成0。否则，不同的字符串（AA和AAAA）可能有相同的哈希值。
private:
    void build_hash_table(char *str, unsigned long long *power,
                          unsigned long long *prefix)
    {
        const int BASE = 13331; // BASE 取 131 或 13331
        power[0] = 1;
        prefix[0] = 0;
        for (int i = 1; str[i - 1]; ++i)
        {
            power[i] = power[i - 1] * BASE;
            prefix[i] = prefix[i - 1] * BASE + str[i - 1]; // 注意，i从1开始，表示字符序号
        }
    }

    unsigned long long get_hash_value(const int &l, const int &r,
                                      unsigned long long *power, unsigned long long *prefix)
    {
        return prefix[r] - prefix[l - 1] * power[r - l + 1];
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        unsigned long long power[n + 1];
        unsigned long long prefix[n + 1];
        char str[n + 1];
        scanf("%s", str);
        build_hash_table(str, power, prefix);
        for (int i = 0, x1, y1, x2, y2; i < m; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (get_hash_value(x1, y1, power, prefix) == get_hash_value(x2, y2, power, prefix))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0841_H
