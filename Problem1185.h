//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1185_H
#define ACWINGSOLUTION_PROBLEM1185_H

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

class Problem1185 {
    // 有向图判断欧拉路径是否存在：https://www.acwing.com/solution/content/66811/
private:
    int FindRoot(const int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }

    int main() {
        const int N = 26;
        int parent[N];  // 记录节点的祖宗节点
        int in_degree[N], out_degree[N];  // 记录节点的入度和出度
        bool existed[N];  // 记录字母是否在输入中出现
        char temp[1010];
        int t;
        scanf("%d", &t);
        while (t--) {
            memset(in_degree, 0, sizeof in_degree);
            memset(out_degree, 0, sizeof out_degree);
            memset(existed, 0, sizeof existed);
            for (int i = 0; i < N; ++i) {
                parent[i] = i;
            }
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%s", temp);
                auto len = (int) strlen(temp);
                int a = temp[0] - 'a';
                int b = temp[len - 1] - 'a';
                existed[a] = true;
                existed[b] = true;
                ++out_degree[a];
                ++in_degree[b];
                parent[FindRoot(a, parent)] = FindRoot(b, parent);  // 将首尾两端的元素合并到同一个并查集里面去
            }

            bool success = true;
            int end_cnt = 0, start_cnt = 0;  // 起点和终点的数量
            for (int i = 0; i < N; ++i) {
                if (in_degree[i] == out_degree[i]) {
                    continue;
                }
                if (in_degree[i] - out_degree[i] == 1) {  // 终点
                    ++end_cnt;
                } else if (out_degree[i] - in_degree[i] == 1) {  // 起点
                    ++start_cnt;
                } else {
                    success = false;
                    break;
                }
            }
            if (!success) {
                puts("The door cannot be opened.");
                continue;
            }

            // 出入度合法的情况下不存在有向图欧拉路径的那两种情况，那么说明是不合法的
            if (success && !(end_cnt == 0 && start_cnt == 0 || end_cnt == 1 && start_cnt == 1)) {
                success = false;
            }
            if (!success) {
                puts("The door cannot be opened.");
                continue;
            }

            // 可能存在孤立点的存在，所以要判断是否是一个联通块之内的
            int root = -1;
            for (int i = 0; i < N; ++i) {
                if (!existed[i]) {
                    continue;
                }
                if (root == -1) {
                    root = FindRoot(i, parent);
                } else {
                    if (root != FindRoot(i, parent)) {
                        success = false;
                        break;
                    }
                }
            }
            if (success) {
                puts("Ordering is possible.");
            } else {
                puts("The door cannot be opened.");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1185_H
