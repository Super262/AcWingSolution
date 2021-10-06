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
    const int N = 26;
    int parent[N];  // 记录节点的祖宗节点
    int degreeIn[N], degreeOut[N];  // 记录节点的入度和出度
    int used[N];  // 记录字母的使用情况
    char temp[1010];

    int findRoot(const int x) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            memset(degreeIn, 0, sizeof degreeIn);
            memset(degreeOut, 0, sizeof degreeOut);
            memset(used, 0, sizeof used);
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
                used[a] = true;
                used[b] = true;
                ++degreeOut[a];
                ++degreeIn[b];
                parent[findRoot(a)] = findRoot(b);  // 将首位两端的元素合并到同一个并查集里面去
            }

            bool success = true;
            int endCnt = 0, startCnt = 0;  // 起点和终点的数量
            for (int i = 0; i < N; ++i) {
                if (degreeIn[i] == degreeOut[i]) {
                    continue;
                }
                if (degreeIn[i] - degreeOut[i] == 1) {  // 终点
                    ++endCnt;
                } else if (degreeOut[i] - degreeIn[i] == 1) {  // 起点
                    ++startCnt;
                } else {
                    success = false;
                    break;
                }
            }

            // 出入度合法的情况下不存在有向图欧拉路径的那两种情况，那么说明是不合法的
            if (success && !(endCnt == 0 && startCnt == 0 || endCnt == 1 && startCnt == 1)) {
                success = false;
            }

            // 可能存在孤立点的存在，所以要判断是否是一个联通块之内的
            int root = -1;
            for (int i = 0; i < N; ++i) {
                if (!used[i]) {
                    continue;
                }
                if (root == -1) {
                    root = findRoot(i);
                } else {
                    if (root != findRoot(i)) {
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
