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
    const int N = 18;
    int catWeight[N];
    int weightSum[N];

    void dfs(const int catIdx, const int currentCount, const int n, const int maxVolume, int &answer) {
        if (currentCount >= answer) {
            return;
        }
        if (catIdx == n) {
            answer = min(answer, currentCount);
        }

        // 尝试将猫放入已有的车内
        for (int i = 0; i < currentCount; ++i) {
            if (weightSum[i] + catWeight[catIdx] > maxVolume) {
                continue;
            }
            weightSum[i] += catWeight[catIdx];
            dfs(catIdx + 1, currentCount, n, answer);
            weightSum[i] -= catWeight[catIdx];
        }

        // 尝试将猫放入新的车内
        weightSum[currentCount] = catWeight[catIdx];
        dfs(catIdx + 1, currentCount + 1, n, answer);
        weightSum[currentCount] = 0;
    }

    int main() {
        int n, maxVolume;
        scanf("%d%d", &n, &maxVolume);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &catWeight[i]);
        }
        // 优化搜索顺序，先处理体重较大的
        sort(catWeight, catWeight + n);
        reverse(catWeight, catWeight + n);
        int answer = n;
        dfs(0, 1, n, maxVolume, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0165_H
