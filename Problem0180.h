//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0180_H
#define ACWINGSOLUTION_PROBLEM0180_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0180 {
    // https://www.acwing.com/solution/content/4050/
public:
    const int MAX_DEPTH = 5, N = 15;
    int books[N];
    int levelTemp[MAX_DEPTH][N];

    int funcF(const int n) {
        int tot = 0;
        for (int i = 1; i < n; ++i) {
            if (books[i] == books[i - 1] + 1) {
                continue;
            }
            ++tot;
        }
        return (tot + 2) / 3;
    }

    bool dfs(const int currentDepth, const int n, const int maxDepth) {
        if (currentDepth + funcF(n) > maxDepth) {
            return false;
        }
        if (funcF(n) == 0) {
            return true;
        }
        for (int length = 1; length <= n; ++length) {
            for (int start = 0; start + length - 1 < n; ++start) {
                int end = start + length - 1;
                for (int k = end + 1; k < n; ++k) {
                    memcpy(levelTemp[currentDepth], books, n * sizeof(int));
                    int y = start;
                    for (int x = end + 1; x <= k; ++x, ++y) {
                        books[y] = levelTemp[currentDepth][x];
                    }
                    for (int x = start; x <= end; ++x, ++y) {
                        books[y] = levelTemp[currentDepth][x];
                    }
                    if (dfs(currentDepth + 1, n, maxDepth)) {
                        return true;
                    }
                    memcpy(books, levelTemp[currentDepth], n * sizeof(int));
                }
            }
        }
        return false;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &books[i]);
            }
            int d = 0;
            while (d < 5 && !dfs(0, n, d)) {
                ++d;
            }
            if (d >= 5) {
                printf("5 or more\n");
            } else {
                printf("%d\n", d);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0180_H
