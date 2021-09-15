//
// Created by Fengwei Zhang on 2021/7/23.
//

#ifndef ACWINGSOLUTION_PROBLEM0179_H
#define ACWINGSOLUTION_PROBLEM0179_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Problem0179 {
    // https://www.acwing.com/solution/content/15289/
    // 引入一个估值函数，用来估计某个点到达终点的距离
    // 算法正确性：保证估计距离f + 距源点的距离d <= 真实距离g
public:
    int expDisToEnd(const string &state) { // 求估值函数,这里是曼哈顿距离
        int res = 0;
        for (int i = 0; i < 9; i++) {
            if (state[i] != 'x') {
                int t = state[i] - '1';
                res += abs(t / 3 - i / 3) + abs(t % 3 - i % 3);
            }
        }
        return res;
    }

    string bfs(const string &start, const string &end) {
        unordered_map<string, int> distFromStart;
        unordered_map<string, pair<string, char>> preOp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        char opCh[] = "urdl";
        heap.push(pair<int, string>(expDisToEnd(start), start));
        distFromStart[start] = 0;
        while (!heap.empty()) {
            auto root = heap.top();
            heap.pop();
            const string currentS = root.second;
            if (currentS == end) {
                break;
            }
            int signIdx = (int) currentS.find('x');
            int signX = signIdx / 3;
            int signY = signIdx % 3;
            for (int i = 0; i < 4; ++i) {
                int nextX = signX + dx[i];
                int nextY = signY + dy[i];
                if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 3) {
                    continue;
                }
                string nextS = currentS;
                swap(nextS[nextX * 3 + nextY], nextS[signX * 3 + signY]);
                if (distFromStart.count(nextS) > 0 && distFromStart[nextS] <= distFromStart[currentS] + 1) {
                    continue;
                }
                distFromStart[nextS] = distFromStart[currentS] + 1;
                preOp[nextS] = pair<string, char>(currentS, opCh[i]);
                heap.push(pair<int, string>(distFromStart[nextS] + expDisToEnd(nextS), nextS));
            }
        }
        string result;
        string str = end;
        while (str != start && preOp.count(str)) {
            result += preOp[str].second;
            str = preOp[str].first;
        }
        if (str != start && preOp.count(str) == 0) {
            return "unsolvable";
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int main() {
        string start = "000000000";
        string seq;
        for (int i = 0; i < 9; ++i) {
            cin >> start[i];
            if (start[i] != 'x') {
                seq += start[i];
            }
        }
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                if (seq[i] <= seq[j]) {
                    continue;
                }
                cnt++;
            }
        }
        if (cnt % 2) {
            puts("unsolvable");
        } else {
            printf("%s\n", bfs(start, "12345678x").data());
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0179_H
