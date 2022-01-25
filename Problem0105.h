//
// Created by Fengwei Zhang on 1/19/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0105_H
#define ACWINGSOLUTION_PROBLEM0105_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem0105 {
    // https://www.acwing.com/solution/content/20259/
private:
    long long Work(const int items[], const int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += items[i];
        }
        if (sum % n) {
            return -1;
        }
        auto avg = sum / n;
        int c[n + 1];
        c[1] = 0;
        for (int i = 2; i <= n; ++i) {
            c[i] = c[i - 1] + items[i - 1] - avg;  // 动态求解加上前缀和、减去avg
        }
        sort(c + 1, c + n + 1);
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            res += abs(c[i] - c[(n + 1) / 2]);
        }
        return res;
    }

    int main() {
        int n, m, t;
        scanf("%d%d%d", &n, &m, &t);
        int row[n + 1];
        int column[m + 1];
        memset(row, 0, sizeof row);
        memset(column, 0, sizeof column);
        for (int i = 0; i < t; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            ++row[x];
            ++column[y];
        }
        auto res1 = Work(row, n);
        auto res2 = Work(column, m);
        if (res1 != -1 && res2 != -1) {
            printf("both %lld\n", res1 + res2);
        } else if (res1 != -1) {
            printf("row %lld\n", res1);
        } else if (res2 != -1) {
            printf("column %lld\n", res2);
        } else {
            printf("impossible\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0105_H
