//
// Created by Fengwei Zhang on 1/18/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1282_H
#define ACWINGSOLUTION_PROBLEM1282_H

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class Problem1282 {
    // https://www.acwing.com/solution/content/18275/
private:
    static const int N = 10010, S = 55, M = 1000010, K = 26;
    int tree[N * S][K], counter[N * S], fail[N * S];
    int q[N * S];

    void InsertWord(const char s[], int &idx) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            auto ch = s[i] - 'a';
            if (!tree[p][ch]) {
                tree[p][ch] = ++idx;
            }
            p = tree[p][ch];
        }
        ++counter[p];
    }

    void BuildAC() {
        int hh = 0, tt = -1;
        for (int i = 0; i < K; ++i) {
            if (!tree[0][i]) {
                continue;
            }
            q[++tt] = tree[0][i];
        }
        while (hh <= tt) {
            auto cur = q[hh++];
            for (int i = 0; i < K; ++i) {
                auto p = tree[cur][i];
                if (p) {
                    fail[p] = tree[fail[cur]][i];
                    q[++tt] = p;
                } else {
                    tree[cur][i] = tree[fail[cur]][i];
                }
            }
        }
    }

    int CountKey(const char s[]) {
        int res = 0;
        for (int i = 0, j = 0; s[i]; ++i) {
            auto ch = s[i] - 'a';
            j = tree[j][ch];
            auto p = j;
            while (p) {
                res += counter[p];
                counter[p] = 0;
                p = fail[p];
            }
        }
        return res;
    }

    int main() {
        char str[M];
        memset(str, 0, sizeof str);
        int t;
        scanf("%d", &t);
        while (t--) {
            memset(tree, 0, sizeof tree);
            memset(counter, 0, sizeof counter);
            memset(fail, 0, sizeof fail);
            int n;
            scanf("%d", &n);
            for (int i = 0, idx = 0; i < n; ++i) {
                scanf("%s", str);
                InsertWord(str, idx);
            }
            BuildAC();
            scanf("%s", str);
            printf("%d\n", CountKey(str));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1282_H
