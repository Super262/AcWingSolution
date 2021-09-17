//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1118_H
#define ACWINGSOLUTION_PROBLEM1118_H

#include <iostream>

using namespace std;

class Problem1118 {
    // https://www.acwing.com/solution/content/56339/
private:
    const int N = 10;
    int groups[N][N];
    int nums[N];
    bool selected[N];

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool groupCompatible(const int a, const int gIdx, const int gTop) {
        for (int i = 0; i < gTop; ++i) {
            if (gcd(a, groups[gIdx][i]) > 1) {
                return false;
            }
        }
        return true;
    }

    void dfs(const int numIdx, const int gIdx, const int gTop, const int selectedCount, const int n, int &answer) {
        if (gIdx + 1 >= answer) {  // 剪枝，避免无效搜索
            return;
        }
        if (selectedCount == n) {
            answer = gIdx + 1;
        }
        bool noGroupFits = true;
        for (int i = numIdx; i < n; ++i) {
            if (selected[i] || !groupCompatible(nums[i], gIdx, gTop)) {
                continue;
            }
            // 某个组满足要求
            noGroupFits = false;
            selected[i] = true;
            groups[gIdx][gTop] = nums[i];
            dfs(i + 1, gIdx, gTop + 1, selectedCount + 1, n, answer);
            selected[i] = false;
        }
        // 当前存在的组都不满足要求
        if (noGroupFits) {
            dfs(0, gIdx + 1, 0, selectedCount, n, answer);
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        int answer = n;
        dfs(0, 0, 0, 0, n, answer);
        printf("%d\n", answer);
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM1118_H
