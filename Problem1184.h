//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1184_H
#define ACWINGSOLUTION_PROBLEM1184_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1184 {
    // https://www.acwing.com/solution/content/16024/
private:
    void AddEdge(const int a, const int b, int &idx, int head_idx[], int next_idx[], int vertex_value[]) {
        vertex_value[idx] = b;
        next_idx[idx] = head_idx[a];
        head_idx[a] = idx;
        ++idx;
    }

    void Dfs(const int u,
             const int type,
             int head_idx[],
             int next_idx[],
             int vertex_value[],
             bool used[],
             int answer[],
             int &ans_top) {
        for (auto &i = head_idx[u]; i != -1;) {  // 注意，i是引用
            if (used[i]) {  // 如果当前边已经被使用
                i = next_idx[i];  // 删除当前边
                continue;
            }
            used[i] = true;  // 标记当前边
            if (type == 1) {  // 无向图边和反向边的索引组合：(0, 1)，(2, 3)，……
                used[i ^ 1] = true;  // 标记反向边
            }
            int t;
            if (type == 1) {  // 无向图
                t = i / 2 + 1;  // t是索引对的位置：(0, 1) -> 1，(2, 3) -> 2，……
                if (i & 1) {  // 是反向边
                    t = -t;
                }
            } else {  // 有向图
                t = i + 1;
            }
            auto v = vertex_value[i];
            i = next_idx[i];
            Dfs(v, type, head_idx, next_idx, vertex_value, used, answer, ans_top);
            answer[ans_top++] = t;
        }
    }

    int main() {
        int type, n, m;
        scanf("%d%d%d", &type, &n, &m);
        int head_idx[n + 10];
        int next_idx[2 * m + 10];  // 注意：无向图边数为2*m
        int vertex_value[2 * m + 10];
        int din[n + 1];
        int dout[n + 1];
        memset(head_idx, -1, sizeof head_idx);
        memset(next_idx, -1, sizeof next_idx);
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            AddEdge(a, b, idx, head_idx, next_idx, vertex_value);
            if (type == 1) {
                AddEdge(b, a, idx, head_idx, next_idx, vertex_value);
            }
            ++din[b];
            ++dout[a];
        }
        if (type == 1) {
            for (int v = 1; v <= n; ++v) {
                // 无向图含欧拉回路的充要条件是每个点的度都为偶数
                if ((din[v] + dout[v]) & 1) {
                    puts("NO");
                    return 0;
                }
            }
        } else {
            for (int v = 1; v <= n; ++v) {
                // 有向图含欧拉回路的充要条件是每个点的入度等于出度
                if (din[v] != dout[v]) {
                    puts("NO");
                    return 0;
                }
            }
        }
        int answer[2 * m + 10];
        bool used[2 * m + 10];
        int ans_top = 0;
        memset(used, 0, sizeof used);
        for (int v = 1; v <= n; ++v) {
            if (head_idx[v] != -1) {
                Dfs(v, type, head_idx, next_idx, vertex_value, used, answer, ans_top);
                break;
            }
        }
        if (ans_top < m) {  // 图不连通
            puts("NO");
            return 0;
        }
        puts("YES");
        for (int i = ans_top - 1; i >= 0; --i) {
            printf("%d ", answer[i]);
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1184_H
