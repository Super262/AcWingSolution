//
// Created by Fengwei Zhang on 8/24/22.
//

#ifndef ACWINGSOLUTION_PROBLEM2715_H
#define ACWINGSOLUTION_PROBLEM2715_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem2715 {
    // 后缀数组，索引从1开始，可将字符串s的所有后缀按照字典序排序，时间复杂度为O(N*logN)（倍增法）
    // 第j个后缀：首字符为s[j]的后缀；sa[i]：排名为i的后缀的编号j；rk[j]：第j个后缀的排名；height[i]：sa[i-1]和sa[i]的最长公共前缀
    // https://www.acwing.com/solution/content/58924/
private:
    static const int N = 1000010;
    int x[2 * N + 1];
    int y[2 * N + 1];
    int cnt[2 * N + 1];  // 用于radix sort

    int sa[2 * N + 1];
    int rk[2 * N + 1];
    int height[2 * N + 1];

    void get_sa(const char str[], int n, int m) {
        for (int i = 1; i <= n; ++i) {
            x[i] = (unsigned char) str[i];
            ++cnt[x[i]];
        }
        for (int i = 2; i <= m; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n; i > 0; --i) {
            sa[cnt[x[i]]] = i;
            --cnt[x[i]];
        }

        for (int k = 1; k <= n; k *= 2) {
            int num = 0;
            for (auto i = n - k + 1; i <= n; ++i) {
                ++num;
                y[num] = i;
            }
            for (int i = 1; i <= n; ++i) {
                if (sa[i] > k) {
                    ++num;
                    y[num] = sa[i] - k;
                }
            }
            memset(cnt, 0, sizeof cnt);
            for (int i = 1; i <= n; ++i) {
                ++cnt[x[i]];
            }
            for (int i = 2; i <= m; ++i) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n; i > 0; --i) {
                sa[cnt[x[y[i]]]] = y[i];
                --cnt[x[y[i]]];
                y[i] = 0;
            }
            swap(x, y);
            x[sa[1]] = 1;
            num = 1;
            for (int i = 2; i <= n; ++i) {
                bool dup = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k];
                if (!dup) {
                    ++num;
                }
                x[sa[i]] = num;
            }
            if (num == n) {
                break;
            }
            m = num;
        }
    }

    void get_height_and_rk(const char str[], int n) {
        for (int i = 1; i <= n; ++i) {
            rk[sa[i]] = i;
        }
        for (int i = 1, k = 0; i <= n; ++i) {
            if (rk[i] == 1) {  // 跳过排名为1的后缀（height[1]=0）
                continue;
            }
            if (k) {
                --k;
            }
            auto j = sa[rk[i] - 1];
            while (i + k <= n && str[i + k] == str[j + k]) {
                ++k;
            }
            height[rk[i]] = k;
        }
    }

    int main() {
        char str[N + 1];
        scanf("%s", str + 1);  // 从索引1开始保存
        const auto &n = (int) strlen(str + 1);

        get_sa(str, n, 'z');
        for (int i = 1; i <= n; ++i) {
            printf("%d ", sa[i]);
        }
        printf("\n");

        get_height_and_rk(str, n);
        for (int i = 1; i <= n; ++i) {
            printf("%d ", height[i]);
        }
        printf("\n");

        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2715_H
