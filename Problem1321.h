//
// Created by Fengwei Zhang on 1/17/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1321_H
#define ACWINGSOLUTION_PROBLEM1321_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1321 {
    // https://www.acwing.com/solution/content/26214/
private:
    static const int N = 51, M = 50051;

    int dp(int a, int b, int f[][M]) {
        auto &v = f[a][b];
        if (v != -1) {
            return v;
        }
        if (!a) {
            v = b % 2;
            return v;
        }
        if (b == 1) {
            return dp(a + 1, 0, f);
        }
        if (!dp(a - 1, b, f)) {
            v = 1;
            return v;
        }
        if (b && !dp(a, b - 1, f)) {
            v = 1;
            return v;
        }
        if (a >= 2 && !dp(a - 2, b + (b ? 3 : 2), f)) {
            v = 1;
            return v;
        }
        if (b && !dp(a - 1, b + 1, f)) {
            v = 1;
            return v;
        }
        v = 0;
        return v;
    }

    int main() {
        int f[N][M];
        memset(f, -1, sizeof f);
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            int a = 0, b = 0;
            for (int i = 0; i < n; ++i) {
                int x;
                scanf("%d", &x);
                if (x == 1) {
                    ++a;
                } else {
                    b += b ? x + 1 : x;
                }
            }
            if (dp(a, b, f)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1321_H
