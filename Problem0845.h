//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0845_H
#define ACWINGSOLUTION_PROBLEM0845_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class Problem0845 {
public:
    int bfs(const string &start) {
        const string end = "12345678x";
        queue<string> q;
        unordered_map<string, int> distance;
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        q.emplace(start);
        distance[start] = 0;
        while (!q.empty()) {
            string node = q.front();
            if (node == end) {
                return distance[node];
            }
            q.pop();
            const int currentDistance = distance[node];
            const int emptyIndex = (int) node.find('x');
            const int currentX = emptyIndex / 3;
            const int currentY = emptyIndex % 3;
            for (int i = 0; i < 4; ++i) {
                const int nextX = currentX + dx[i];
                const int nextY = currentY + dy[i];
                if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 3) {
                    continue;
                }
                swap(node[nextX * 3 + nextY], node[emptyIndex]);
                if (distance.find(node) == distance.end()) {
                    distance[node] = currentDistance + 1;
                    q.emplace(node);
                }
                swap(node[nextX * 3 + nextY], node[emptyIndex]);
            }
        }
        return -1;
    }

    int main() {
        string s(9, '\0');
        for (int i = 0; i < 9; ++i) {
            cin >> s[i];
        }
        printf("%d", bfs(s));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0845_H
