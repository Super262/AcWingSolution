//
// Created by Fengwei Zhang on 2021/7/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0170_H
#define ACWINGSOLUTION_PROBLEM0170_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0170 {
    // https://www.acwing.com/solution/content/38248/
public:
    int path[101];

    bool dfs(const int prevDepth, const int maxDepth, const int n) {
        if (prevDepth == maxDepth) {
            return path[prevDepth] == n;
        }
        bool isSelected[2 * path[prevDepth] + 1];
        memset(isSelected, 0, sizeof isSelected);
        for (int i = prevDepth; i >= 0; --i) {
            for (int j = i; j >= 0; --j) {
                int nextS = path[i] + path[j];
                if (nextS > n || nextS <= path[prevDepth] || isSelected[nextS]) {
                    continue;
                }
                isSelected[nextS] = true;
                path[prevDepth + 1] = nextS;
                if (dfs(prevDepth + 1, maxDepth, n)) {
                    return true;
                }
            }
        }
        return false;
    }

    int main() {
        path[0] = 1;
        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            int maxDepth = 0;
            while (!dfs(0, maxDepth, n)) {
                ++maxDepth;
            }
            for (int i = 0; i <= maxDepth; ++i) {
                printf("%d ", path[i]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0170_H
