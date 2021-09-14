//
// Created by Fengwei Zhang on 2021/7/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1107_H
#define ACWINGSOLUTION_PROBLEM1107_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Problem1107 {
    // https://www.acwing.com/solution/content/19847/
    // 保证字典序：按照字典序从A开始处理
public:
    string moveA(string s) {
        for (int i = 0; i < 4; i++) {
            swap(s[i], s[7 - i]);
        }
        return s;
    }

    string moveB(string s) {
        char t1 = s[3];
        char t2 = s[4];
        for (int i = 3; i >= 1; --i) {
            s[i] = s[i - 1];
        }
        for (int i = 4; i < 7; ++i) {
            s[i] = s[i + 1];
        }
        s[0] = t1;
        s[7] = t2;
        return s;
    }

    string moveC(string s) {
        swap(s[1], s[2]), swap(s[5], s[6]), swap(s[1], s[5]);
        return s;
    }

    void bfs(const string &start,
             const string &end,
             unordered_map<string, int> &dist,
             unordered_map<string, pair<char, string>> &preOp) {
        if (start == end) {
            return;
        }
        queue<string> q;
        q.emplace(start);
        dist[start] = 0;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            string nextS[3];
            nextS[0] = moveA(root);
            nextS[1] = moveB(root);
            nextS[2] = moveC(root);
            for (int i = 0; i < 3; i++) {
                if (dist.count(nextS[i])) {
                    continue;
                }
                q.emplace(nextS[i]);
                dist[nextS[i]] = dist[root] + 1;
                preOp[nextS[i]] = {'A' + i, root};
            }
        }
    }

    int main() {
        unordered_map<string, int> dist;
        unordered_map<string, pair<char, string>> preOp;
        const string start = "12345678";
        string end = "00000000";
        for (int i = 0; i < 8; ++i) {
            int t;
            scanf("%d", &t);
            end[i] = (char) ('0' + t);
        }
        bfs(start, end, dist, preOp);
        printf("%d\n", dist[end]);
        if (dist[end] > 0) {
            string opList;
            string current = end;
            while (current != start) {
                auto op = preOp[current];
                opList.push_back(op.first);
                current = op.second;
            }
            reverse(opList.begin(), opList.end());
            printf("%s\n", opList.data());
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1107_H
