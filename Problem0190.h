//
// Created by Fengwei Zhang on 2021/7/23.
//

#ifndef ACWINGSOLUTION_PROBLEM0190_H
#define ACWINGSOLUTION_PROBLEM0190_H

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Problem0190 {
    // https://www.acwing.com/solution/content/5434/
public:
    int extendPath(queue<string> &qOfS,
                   unordered_map<string, int> &dis2S,
                   unordered_map<string, int> &dis2E,
                   const string patternIn[],
                   const string patternOut[],
                   const int n) {
        const int currentLevelSize = (int) qOfS.size();
        for (int k = 0; k < currentLevelSize; ++k) {
            auto root = qOfS.front();
            qOfS.pop();
            for (int i = 0; i < (int) root.size(); ++i) {
                for (int j = 0; j < n; ++j) {
                    if (root.substr(i, patternIn[j].size()) != patternIn[j]) {
                        continue;
                    }
                    auto nextS = root.substr(0, i) + patternOut[j] + root.substr(i + patternIn[j].size());
                    if (dis2S.count(nextS)) {
                        continue;
                    }
                    dis2S[nextS] = dis2S[root] + 1;
                    if (dis2E.count(nextS)) {
                        return dis2S[nextS] + dis2E[nextS];
                    }
                    qOfS.emplace(nextS);
                }
            }
        }
        return 11;
    }

    int bfs(const string &start, const string &end, const string patternIn[], const string patternOut[], const int n) {
        queue<string> qOfS;
        queue<string> qOfE;
        unordered_map<string, int> dis2S;
        unordered_map<string, int> dis2E;
        int res = 11;
        qOfS.emplace(start);
        qOfE.emplace(end);
        dis2S[start] = 0;
        dis2E[end] = 0;
        while (!qOfS.empty() && !qOfE.empty()) {
            if (qOfS.size() > qOfE.size()) {
                res = extendPath(qOfE, dis2E, dis2S, patternOut, patternIn, n);
            } else {
                res = extendPath(qOfS, dis2S, dis2E, patternIn, patternOut, n);
            }
            if (res < 11) {
                return res;
            }
        }
        return res;
    }

    int main() {
        string patternIn[6];
        string patternOut[6];
        string start, end;
        cin >> start >> end;
        int n = 0;
        while (cin >> patternIn[n] >> patternOut[n]) {
            ++n;
        }
        int res = bfs(start, end, patternIn, patternOut, n);
        if (res < 11) {
            printf("%d\n", res);
        } else {
            printf("NO ANSWER!\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0190_H
