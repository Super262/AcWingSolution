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
    int extendPath(queue<string> &qSrc,
                   unordered_map<string, int> &distFromSrc,
                   unordered_map<string, int> &distFromTarget,
                   const string *srcNodes,
                   const string *targetNodes,
                   const int N) {
        const int currentLevelSize = (int) qSrc.size();
        for (int k = 0; k < currentLevelSize; ++k) {
            auto root = qSrc.front();
            qSrc.pop();
            for (int i = 0; i < (int) root.size(); ++i) {
                for (int j = 0; j < N; ++j) {
                    if (root.substr(i, srcNodes[j].size()) != srcNodes[j]) {
                        continue;
                    }
                    auto nextS = root.substr(0, i) + targetNodes[j] + root.substr(i + srcNodes[j].size());
                    if (distFromSrc.count(nextS)) {
                        continue;
                    }
                    distFromSrc[nextS] = distFromSrc[root] + 1;
                    if (distFromTarget.count(nextS)) {
                        return distFromSrc[nextS] + distFromTarget[nextS];
                    }
                    qSrc.emplace(nextS);
                }
            }
        }
        return 11;
    }

    int bfs(const string &start, const string &end, const string srcNodes[], const string targetNodes[], const int N) {
        queue<string> qSrc;
        queue<string> qTarget;
        unordered_map<string, int> distFromSrc;
        unordered_map<string, int> distFromTarget;
        int res = 11;
        qSrc.emplace(start);
        qTarget.emplace(end);
        distFromSrc[start] = 0;
        distFromTarget[end] = 0;
        while (!qSrc.empty() && !qTarget.empty()) {
            if (qSrc.size() > qTarget.size()) {
                res = extendPath(qTarget, distFromTarget, distFromSrc, targetNodes, srcNodes, N);
            } else {
                res = extendPath(qSrc, distFromSrc, distFromTarget, srcNodes, targetNodes, N);
            }
            if (res < 11) {
                return res;
            }
        }
        return res;
    }

    int main() {
        string srcNodes[6];
        string targetNodes[6];
        string src, target;
        cin >> src >> target;
        int n = 0;
        while (cin >> srcNodes[n] >> targetNodes[n]) {
            ++n;
        }
        int res = bfs(src, target, srcNodes, targetNodes, n);
        if (res < 11) {
            printf("%d\n", res);
        } else {
            printf("NO ANSWER!\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0190_H
