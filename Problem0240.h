//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0240_H
#define ACWINGSOLUTION_PROBLEM0240_H

#include <iostream>

using namespace std;

class Problem0240 {
    // https://www.acwing.com/solution/content/24842/
private:
    const int N = 50005;
    int parent[N];
    int dist[N];  // 当前节点到根结点的距离

    int findRoot(const int x) {
        if (x != parent[x]) {
            auto root = findRoot(parent[x]);
            dist[x] += dist[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    bool mergeSets(const int x, const int y, const int rel) {
        auto px = findRoot(x);
        auto py = findRoot(y);
        if (rel == 1 && px == py && (dist[x] - dist[y]) % 3) {
            return false;
        }
        if (rel == 2 && px == py && (dist[x] - dist[y] - 1) % 3) {
            return false;
        }
        if (px == py) {
            return true;
        }
        parent[px] = py;
        if (rel == 1) {
            dist[px] = dist[y] - dist[x];
        } else {
            dist[px] = dist[y] - dist[x] + 1;
        }
        return true;
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        int result = 0;
        int op, x, y;
        while (k--) {
            scanf("%d%d%d", &op, &x, &y);
            if (x > n || y > n) {
                ++result;
                continue;
            }
            if (!mergeSets(x, y, op)) {
                ++result;
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0240_H
