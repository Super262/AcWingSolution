//
// Created by Fengwei Zhang on 1/18/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1322_H
#define ACWINGSOLUTION_PROBLEM1322_H

#include <iostream>
#include <cstring>

using namespace std;

static const int N = 1010;

class Problem1322 {
    // https://www.acwing.com/solution/content/26286/
private:
    static const int N = 1010;

    int main() {
        int a[N];
        int left[N][N];
        int right[N][N];
        memset(left, 0, sizeof left);
        memset(right, 0, sizeof right);
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &a[i]);
            }
            for (int len = 1; len <= n; ++len) {
                for (int i = 1; i + len - 1 <= n; i++) {
                    auto j = i + len - 1;
                    // 区间只有一个堆x 则左右取为x -> x [x] x
                    // 只要先手取哪一堆 后手在另一堆取一样多的石子
                    // 则只要先手取得这堆有,后手取得另一堆也一定有,
                    // 直到先手取得那堆取完,后手把另一堆取完 先手必败
                    if (len == 1) {
                        left[i][j] = right[i][j] = a[i];
                    } else {
                        auto L = left[i][j - 1];
                        auto R = right[i][j - 1];
                        auto X = a[j];
                        if (R == X) {  // 情况1
                            left[i][j] = 0;
                        } else if (X < L && X < R || X > L && X > R) {  // 情况2 情况4
                            left[i][j] = X;
                        } else if (L > R) {
                            left[i][j] = X - 1;  // 情况3.1 情况4.1
                        } else {
                            left[i][j] = X + 1;  // 情况3.2 情况4.2
                        }
                        // 与上述情况对称的四种情况
                        L = left[i + 1][j];
                        R = right[i + 1][j];
                        X = a[i];
                        if (L == X) {
                            right[i][j] = 0;
                        } else if (X < L && X < R || X > L && X > R) {
                            right[i][j] = X;
                        } else if (R > L) {
                            right[i][j] = X - 1;
                        } else {
                            right[i][j] = X + 1;
                        }
                    }
                }
            }
            if (n == 1) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", left[2][n] != a[1]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1322_H
