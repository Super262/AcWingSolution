//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM0165_H
#define ACWINGSOLUTION_PROBLEM0165_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0165 {
    // https://www.acwing.com/solution/content/951/
private:
    static const int N = 18;
    int catW[N];
    int wSum[N];

    void dfs(int catIdx, int tankTop, int n, int maxWSum, int &answer) {
        if (tankTop + 1 >= answer) {  // 最优性剪枝
            return;
        }
        if (catIdx == n) {
            answer = tankTop + 1;
        }
        for (int i = 0; i <= tankTop; ++i) {
            if (wSum[i] + catW[catIdx] > maxWSum) {
                continue;
            }
            // 将当前猫放到现有的某辆车里
            wSum[i] += catW[catIdx];
            dfs(catIdx + 1, tankTop, n, maxWSum, answer);
            wSum[i] -= catW[catIdx];
        }
        // 将当前猫放到新的车里
        wSum[tankTop + 1] = catW[catIdx];
        dfs(catIdx + 1, tankTop + 1, n, maxWSum, answer);
        wSum[tankTop + 1] = 0;
    }

    int main() {
        int n, maxWSum;
        scanf("%d%d", &n, &maxWSum);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &catW[i]);
        }
        sort(catW, catW + n);
        reverse(catW, catW + n);
        int answer = n;
        dfs(0, 0, n, maxWSum, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0165_H
