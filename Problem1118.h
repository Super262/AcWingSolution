//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1118_H
#define ACWINGSOLUTION_PROBLEM1118_H

#include <iostream>

using namespace std;

class Problem1118 {
    // https://www.acwing.com/solution/content/56339/
public:
    const int N = 10;
    int nums[N];
    int groups[N][N];
    bool isSelected[N];

    int gcd(const int a, const int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool isCompatibleWithCurrentNums(const int num, const int groupIdx, const int groupTopIdx) {
        for (int i = 0; i < groupTopIdx; ++i) {
            if (gcd(num, groups[groupIdx][i]) > 1) {
                return false;
            }
        }
        return true;
    }

    void dfs(const int groupIdx,
             const int groupTopIdx,
             const int selectedNumsCount,
             const int currentNumIdx,
             const int n,
             int &answer) {
        if (groupIdx + 1 >= answer) {
            return;
        }
        if (selectedNumsCount == n) {
            answer = min(answer, groupIdx + 1);
        }
        bool noOneCompatible = true;
        for (int i = currentNumIdx; i < n; ++i) {
            if (isSelected[i] || !isCompatibleWithCurrentNums(nums[i], groupIdx, groupTopIdx)) {
                continue;
            }
            noOneCompatible = false;
            isSelected[i] = true;
            groups[groupIdx][groupTopIdx] = nums[i];
            dfs(groupIdx, groupTopIdx + 1, selectedNumsCount + 1, i + 1, n, answer);
            isSelected[i] = false;
        }
        if (noOneCompatible) {
            dfs(groupIdx + 1, 0, selectedNumsCount, 0, n, answer);
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
