//
// Created by Fengwei Zhang on 2021/7/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0171_H
#define ACWINGSOLUTION_PROBLEM0171_H

#include <algorithm>
#include <iostream>

using namespace std;

class Problem0171 {
    // https://www.acwing.com/solution/content/38250/
public:
    const int N = 46;
    int g[N];
    int firstHalfWeights[1 << (N / 2)];
    int wEnd = 0;

    int findUpperValue(const int *arr, int start, int end, const int target) {
        while (start < end) {
            auto mid = start + (end - start + 1) / 2;
            if (arr[mid] <= target) {
                start = mid;
            } else {
                end = mid - 1;
            }
        }
        return arr[start];
    }

    void dfs1(const int currentIdx, const int currentSum, const int n, const int maxSum) {
        if (currentIdx == n) {
            firstHalfWeights[wEnd++] = currentSum;
            return;
        }
        dfs1(currentIdx + 1, currentSum, n, maxSum);
        if ((long long) currentSum + g[currentIdx] > maxSum) {
            return;
        }
        dfs1(currentIdx + 1, currentSum + g[currentIdx], n, maxSum);
    }

    void dfs2(const int currentIdx, const int currentSum, const int n, const int maxSum, int &answer) {
        if (currentIdx == n) {
            int maxOfFirstHalf = findUpperValue(firstHalfWeights, 0, wEnd - 1, maxSum - currentSum);
            answer = max(answer, maxOfFirstHalf + currentSum);
            return;
        }
        dfs2(currentIdx + 1, currentSum, n, maxSum, answer);
        if ((long long) currentSum + g[currentIdx] > maxSum) {
            return;
        }
        dfs2(currentIdx + 1, currentSum + g[currentIdx], n, maxSum, answer);
    }

    int main() {
        int maxSum, n;
        scanf("%d%d", &maxSum, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &g[i]);
        }
        sort(g, g + n);
        reverse(g, g + n);
        dfs1(0, 0, n / 2, maxSum);
        sort(firstHalfWeights, firstHalfWeights + wEnd);
        wEnd = (int) (unique(firstHalfWeights, firstHalfWeights + wEnd) - firstHalfWeights);
        int answer = -1;
        dfs2(n / 2, 0, n, maxSum, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0171_H
