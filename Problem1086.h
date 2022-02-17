//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1086_H
#define ACWINGSOLUTION_PROBLEM1086_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1086 {
    // 数位DP + 记忆化搜索；牢记更新s1和s2的数学公式
    // https://www.acwing.com/solution/content/67450/
private:
    static const int MOD = 1e9 + 7;

    struct Node {
        // 假设当前位的数字为a，能接在a后的数字为B（aB是满足要求的整数）
        long long s0;  // 可行的B的个数
        long long s1;  // 可行的B的总和
        long long s2;  // 可行的B的平方和
        Node() {
            s0 = 0;
            s1 = 0;
            s2 = 0;
        }

        Node(long long _s0, long long _s1, long long _s2) {
            s0 = _s0;
            s1 = _s1;
            s2 = _s2;
        }

        void operator+=(const Node &t) {
            s0 = (s0 + t.s0) % MOD;
            s1 = (s1 + t.s1) % MOD;
            s2 = (s2 + t.s2) % MOD;
        }
    };

    static const int N = 20;  // 输入数据位数的最大值
    int digits[N];  // 输入数据的每位，从索引1开始存储
    int power10[N];  // power10[i]预存10^i
    Node f[N][N][N];  // f[pos][val][sum]：当前是第pos位，当前数模7的余数是val，前几位数字和模7的余数是sum

    Node dp(int pos, int val, int sum, bool op) {  // op指示当前搜索的上界是否为digits[pos]
        if (!pos) {  // 搜索完成
            if (val && sum) {  // 满足题意
                return {1, 0, 0};
            }
            return {0, 0, 0};
        }
        if (!op && f[pos][val][sum].s0 != -1) {
            return f[pos][val][sum];
        }
        Node res;
        auto maxx = op ? digits[pos] : 9;  // 当前位的上界
        for (int x = 0; x <= maxx; ++x) {
            if (x == 7) {
                continue;
            }
            auto t = dp(pos - 1, (val * 10 + x) % 7, (sum + x) % 7, op && x == digits[pos]);
            auto k = (long long) x * power10[pos - 1] % MOD;  // k = a * 10^(p - 1)
            // 更新s2和s1
            t.s2 = (t.s2 + 2ll * k % MOD * t.s1 % MOD) % MOD;
            t.s2 = (t.s2 + k * k % MOD * t.s0 % MOD) % MOD;
            t.s1 = (t.s1 + k * t.s0 % MOD) % MOD;
            res += t;
        }
        if (!op) {  // 没有紧贴上界
            f[pos][val][sum] = res;
        }
        return res;
    }

    long long calc(long long x) {
        memset(f, -1, sizeof f);
        int pos = 0;
        while (x) {
            ++pos;
            digits[pos] = (int) (x % 10);
            x /= 10;
        }
        return dp(pos, 0, 0, true).s2;
    }

    int main() {
        // 预处理10的幂
        power10[0] = 1;
        for (int i = 1; i < N; ++i) {
            power10[i] = (int) (10ll * power10[i - 1] % MOD);
        }
        int t;
        scanf("%d", &t);
        while (t--) {
            long long l, r;
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", ((calc(r) - calc(l - 1)) % MOD + MOD) % MOD);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1086_H
