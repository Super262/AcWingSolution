//
// Created by Fengwei Zhang on 2021/6/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0890_H
#define ACWINGSOLUTION_PROBLEM0890_H

#include <iostream>

using namespace std;

class Problem0890 {
    // https://www.acwing.com/solution/content/29702/
private:
    int CountHelper(const int n, const int primes[], const int p_cnt) {
        int result = 0;
        for (int s = 1; s < (1 << p_cnt); ++s) {  // 利用位运算枚举所有因子包含的质数：选择primes[i]，s[i] == 1
            long long factor = 1;  // 当前因子
            int sets_count = 0;  // 可整除当前因子的质数个数
            for (int j = 0; j < p_cnt; ++j) {
                if (!((s >> j) & 1)) {
                    continue;
                }
                factor *= primes[j];
                if (factor > n) {
                    factor = 0;
                    break;
                }
                ++sets_count;
            }
            if (!factor) {
                continue;
            }
            if (sets_count % 2) {
                result += n / (int) factor;  // 加上奇数个集合交集的大小
            } else {
                result -= n / (int) factor;  // 减去偶数个集合交集的大小
            }
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int primes[m];
        for (int i = 0; i < m; ++i) {
            scanf("%d", &primes[i]);
        }
        printf("%d\n", CountHelper(n, primes, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0890_H
