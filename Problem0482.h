//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0482_H
#define ACWINGSOLUTION_PROBLEM0482_H

class Problem0482 {
public:
    int maxLISSum(const int *a, const int N) {
        int result = 0;
        auto f = new int[N];
        for (int i = 0; i < N; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j] >= a[i]) {
                    continue;
                }
                f[i] = max(f[i], f[j] + 1);
            }
        }
        auto g = new int[N];
        for (int i = N - 1; i >= 0; --i) {
            g[i] = 1;
            for (int j = N - 1; j > i; --j) {
                if (a[j] >= a[i]) {
                    continue;
                }
                g[i] = max(g[i], g[j] + 1);
            }
        }
        for (int i = 0; i < N; ++i) {
            result = max(result, f[i] + g[i] - 1);
        }
        delete[] f;
        delete[] g;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int *a = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", n - maxLISSum(a, n));
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0482_H
