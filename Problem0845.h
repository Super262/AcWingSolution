//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0845_H
#define ACWINGSOLUTION_PROBLEM0845_H

#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class Problem0845 {
private:
    int bfs(const string &start, const string &end) {
        queue<string> q;
        unordered_map<string, int> dist;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        dist[start] = 0;
        q.emplace(start);
        while (!q.empty()) {
            auto node = q.front();
            if (node == end) {
                return dist[node];
            }
            q.pop();
            auto tagPos = (int) node.find('x');
            auto currentDis = dist[node];
            for (int i = 0; i < 4; ++i) {
                auto nextX = tagPos / 3 + dx[i];
                auto nextY = tagPos % 3 + dy[i];
                if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 3) {
                    continue;
                }
                swap(node[nextX * 3 + nextY], node[tagPos]);
                if (dist.find(node) == dist.end()) {
                    q.emplace(node);
                    dist[node] = currentDis + 1;
                }
                swap(node[nextX * 3 + nextY], node[tagPos]);
            }
        }
        return -1;
    }

    int main() {
        string start(9, '\0');
        string end = "12345678x";
        for (int i = 0; i < 9; ++i) {
            cin >> start[i];
        }
        printf("%d\n", bfs(start, end));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0845_H
