//
// Created by Fengwei Zhang on 1/18/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1053_H
#define ACWINGSOLUTION_PROBLEM1053_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1053 {
    // https://www.acwing.com/solution/content/56098/
    // 与AC自动机相关内容使用基于数组实现的数据结构
private:
    static const int N = 55, M = 1010, K = 25, C = 4, INF = 0x3f3f3f3f;
    int tree[N * K][C], counter[N * K], fail[N * K];  // AC自动机相关数组
    int q[N * K];  // BFS所需队列
    int dp[M][N * K];  // 动态规划所需数组

    int GetChIdx(char c) {
        if (c == 'A') {
            return 0;
        }
        if (c == 'G') {
            return 1;
        }
        if (c == 'C') {
            return 2;
        }
        return 3;
    }

    void InsertWord(const char s[], int &idx) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            auto u = GetChIdx(s[i]);
            if (!tree[p][u]) {
                tree[p][u] = ++idx;
            }
            p = tree[p][u];
        }
        counter[p] = 1;
    }

    void BuildAC() {
        int tt = -1, hh = 0;
        for (int i = 0; i < C; ++i) {
            if (!tree[0][i]) {
                continue;
            }
            q[++tt] = tree[0][i];
        }
        while (hh <= tt) {
            auto cur = q[hh++];
            for (int i = 0; i < C; ++i) {
                if (tree[cur][i]) {
                    fail[tree[cur][i]] = tree[fail[cur]][i];
                    q[++tt] = tree[cur][i];
                } else {
                    tree[cur][i] = tree[fail[cur]][i];
                }
            }
        }
    }

    int Solve(char s[], const int idx) {
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        auto n = (int) strlen(s);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= idx; ++j) {
                for (int k = 0; k < C; ++k) {
                    auto cost = GetChIdx(s[i]) != k;
                    auto p = tree[j][k];
                    bool flag = true;
                    auto temp = p;
                    while (temp) {
                        if (counter[temp]) {
                            flag = false;
                            break;
                        }
                        temp = fail[temp];
                    }
                    if (flag) {
                        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + cost);
                    }
                }
            }
        }
        auto res = INF;
        for (int j = 0; j <= idx; ++j) {
            res = min(res, dp[n][j]);
        }
        if (res == INF) {
            res = -1;
        }
        return res;
    }

    int main() {
        char str[M];
        int t = 1;
        while (true) {
            int n;
            scanf("%d", &n);
            if (!n) {
                break;
            }
            memset(tree, 0, sizeof tree);
            memset(counter, 0, sizeof counter);
            memset(fail, 0, sizeof fail);
            memset(str, 0, sizeof str);
            int idx = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%s", str);
                InsertWord(str, idx);
            }
            BuildAC();
            scanf("%s", str);
            printf("Case %d: %d\n", t, Solve(str, idx));
            ++t;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1053_H
