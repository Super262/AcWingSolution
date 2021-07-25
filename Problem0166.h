//
// Created by Fengwei Zhang on 2021/7/25.
//

#ifndef ACWINGSOLUTION_PROBLEM0166_H
#define ACWINGSOLUTION_PROBLEM0166_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Problem0166 {
    // https://www.acwing.com/solution/content/31873/
public:
    const int N = 9, M = 1 << N;
    int numOfOnes[M], idxOfOne[M];
    int rowState[N], columnState[N], cellState[3][3];  // state二进制的9位对应1～9的出现情况（0不出现，1出现）
    char str[100];

    int lowBit(const int x) {
        return x & (-x);
    }

    void modifyValue(const int x, const int y, const int value, bool toIncrease) {
        if (toIncrease) {
            str[x * N + y] = (char) ('0' + value);
            int s = 1 << (value - 1);
            rowState[x] -= s;
            columnState[y] -= s;
            cellState[x / 3][y / 3] -= s;
        } else {
            str[x * N + y] = '.';
            int s = 1 << (value - 1);
            rowState[x] += s;
            columnState[y] += s;
            cellState[x / 3][y / 3] += s;
        }
    }

    int pointState(const int x, const int y) {
        return rowState[x] & columnState[y] & cellState[x / 3][y / 3];
    }

    int initialize() {
        fill(rowState, rowState + N, M - 1);
        fill(columnState, columnState + N, M - 1);
        fill(cellState[0], cellState[0] + N, M - 1);
        int cnt = 0;
        int k = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (str[k] == '.') {
                    ++cnt;
                } else {
                    modifyValue(i, j, str[k] - '0', true);
                }
                ++k;
            }
        }
        return cnt;
    }

    bool dfs(const int cnt) {
        if (cnt <= 0) {
            return true;
        }
        int minSelection = 10;
        int x = 0, y = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (str[i * N + j] != '.') {
                    continue;
                }
                auto s = numOfOnes[pointState(i, j)];
                if (s < minSelection) {
                    x = i;
                    y = j;
                    minSelection = s;
                }
            }
        }
        for (int s = pointState(x, y); s > 0; s -= lowBit(s)) {
            int value = idxOfOne[lowBit(s)] + 1;
            modifyValue(x, y, value, true);
            if (dfs(cnt - 1)) {
                return true;
            }
            modifyValue(x, y, value, false);
        }
        return false;
    }

    int main() {
        for (int i = 0; i < N; ++i) {
            idxOfOne[1 << i] = i;
        }
        for (int i = 0; i < M; ++i) {
            for (int j = i; j > 0; j -= lowBit(j)) {
                ++numOfOnes[i];
            }
        }
        while (true) {
            scanf("%s", str);
            int cnt = initialize();
            if (str[0] == 'e') {
                break;
            }
            dfs(cnt);
            puts(str);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0166_H
