//
// Created by Fengwei Zhang on 9/20/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0237_H
#define ACWINGSOLUTION_PROBLEM0237_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0237 {
private:
    struct Query {
        int a, b, e;
    };

    unordered_map<int, int> dataTable;
    static const int N = 100010;
    Query queries[N];
    int parent[2 * N];
    int pTop = 0;

    int findRoot(int x) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    int getIdx(int a) {
        // 获得离散化（无序的）后的索引值
        if (dataTable.count(a) == 0) {
            dataTable[a] = pTop;
            return pTop++;
        }
        return dataTable[a];
    }

    bool checkConstraint(int a, int b, int e) {
        auto pa = findRoot(getIdx(a));
        auto pb = findRoot(getIdx(b));
        if (e) {
            parent[pa] = pb;
            return true;
        }
        return pa != pb;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            dataTable.clear();
            pTop = 0;
            for (int i = 0; i < 2 * N; ++i) {
                parent[i] = i;
            }
            int n;
            scanf("%d", &n);
            // 先处理完所有相等关系，再处理所有不等关系
            for (int i = 0; i < n; ++i) {
                scanf("%d%d%d", &queries[i].a, &queries[i].b, &queries[i].e);
            }
            for (int i = 0; i < n; ++i) {
                if (queries[i].e == 0) {
                    continue;
                }
                checkConstraint(queries[i].a, queries[i].b, queries[i].e);
            }
            bool hasConflict = false;
            for (int i = 0; i < n; ++i) {
                if (queries[i].e == 1) {
                    continue;
                }
                if (!checkConstraint(queries[i].a, queries[i].b, queries[i].e)) {
                    hasConflict = true;
                    break;
                }
            }
            if (hasConflict) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0237_H
