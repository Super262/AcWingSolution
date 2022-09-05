//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1117_H
#define ACWINGSOLUTION_PROBLEM1117_H

#include <iostream>
#include <string>

using namespace std;

class Problem1117 {
private:
    static const int N = 20;
    string word[N];
    int visitCount[N];
    int minCommonLen[N][N];

    void findConnection(const int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const auto &a = word[i];
                const auto &b = word[j];
                for (int length = 1; length < min(a.size(), b.size()); ++length) {
                    if (a.substr(a.size() - length) == b.substr(0, length)) {
                        // 由于希望最后的"龙"最长，我们寻找最短的公共部分
                        minCommonLen[i][j] = length;
                        break;
                    }
                }
            }
        }
    }

    void dfs(const string &dragon, const int currentWordIdx, const int n, int &answer) {
        answer = max((int) dragon.size(), answer);
        ++visitCount[currentWordIdx];
        for (int i = 0; i < n; ++i) {
            if (visitCount[i] >= 2 || minCommonLen[currentWordIdx][i] == 0) {
                continue;
            }
            dfs(dragon + word[i].substr(minCommonLen[currentWordIdx][i]), i, n, answer);
        }
        --visitCount[currentWordIdx];
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cin >> word[i];
        }
        findConnection(n);
        char startCh;
        cin >> startCh;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (word[i][0] != startCh) {
                continue;
            }
            dfs(word[i], i, n, answer);
        }
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1117_H
