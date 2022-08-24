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
    // 双关键字排序：先按照第2关键字排序，再按照第1关键字排序
    // https://www.acwing.com/solution/content/58924/
private:
    static const int N = 1000010;
    int x[2 * N + 1];  // x[i]表示第1个关键字离散化后的值
    int y[2 * N + 1];  // y[i]表示第2个关键字离散化后的值
    int cnt[2 * N + 1];  // 关键字频率，用于radix sort

    int sa[2 * N + 1];
    int rk[2 * N + 1];
    int height[2 * N + 1];

    void get_sa(const char str[], int n, int m) {
        // 第1轮排序（按照首字母）
        for (int i = 1; i <= n; ++i) {  // 初始时，由于str[i]较小，我们设置x[i]=str[i]
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

        for (int k = 1; k <= n; k *= 2) {  // logN轮双关键字排序
            // 根据第2个关键字排序
            int num = 0;
            for (auto i = n - k + 1; i <= n; ++i) {  // 经观察，编号为[n-k+1,n]的后缀不包含第2个关键字，它们排名最低
                ++num;
                y[num] = i;
            }
            for (int i = 1; i <= n; ++i) {  // 经观察，编号为i的后缀的第2个关键字是编号为i+k的后缀的第1个关键字
                if (sa[i] > k) {  // sa[i]>k时，编号为sa[i]的后缀的第1个关键字是编号为sa[i]-k的后缀的第2个关键字
                    ++num;
                    y[num] = sa[i] - k;
                }
            }

            // 根据第1个关键字排序
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

            // 将字符串（包含2个关键字）离散化为从1开始的数字
            x[sa[1]] = 1;
            num = 1;
            for (int i = 2; i <= n; ++i) {
                bool dup = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k];
                if (!dup) {  // 不完全相同
                    ++num;
                }
                x[sa[i]] = num;
            }
            if (num == n) {  // 已完全区别这n个后缀
                break;
            }
            m = num;  // 下轮的不同字符串个数为num
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
