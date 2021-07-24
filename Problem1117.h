//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1117_H
#define ACWINGSOLUTION_PROBLEM1117_H

#include <iostream>
#include <string>

using namespace std;

class Problem1117 {
public:
    const int N = 20;
    string word[N];
    int readCount[N];
    int commonLength[N][N];

    void findConnection(const int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const auto &a = word[i];
                const auto &b = word[j];
                for (int length = 1; length < min(a.size(), b.size()); ++length) {
                    if (a.substr(a.size() - length) == b.substr(0, length)) {
                        // 寻找最短的公共部分
                        commonLength[i][j] = length;
                        break;
                    }
                }
            }
        }
    }

    void dfs(const string& dragon, const int currentWordIdx, const int n, int &answer) {
        answer = max((int) dragon.size(), answer);
        ++readCount[currentWordIdx];
        for (int i = 0; i < n; ++i) {
            if (readCount[i] >= 2 || commonLength[currentWordIdx][i] == 0) {
                continue;
            }
            dfs(dragon + word[i].substr(commonLength[currentWordIdx][i]), i, n, answer);
        }
        --readCount[currentWordIdx];
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
