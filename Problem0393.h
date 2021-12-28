//
// Created by Fengwei Zhang on 12/27/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0393_H
#define ACWINGSOLUTION_PROBLEM0393_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem0393 {
    // https://www.acwing.com/solution/content/8219/
    // worker[i]：在i时刻开始工作的收银员
    // need[i]：i时刻需要的收银员
    // s[i]：0 ～ i 时间段工作的收银员
    // 1. 0 <= s[i] - s[i - 1] <= worker[i]
    // 2. s[i] - s[i - 8] >= need[i], i >= 8
    // 3. s[i] + s[24] - s[16 + i] >= need[i], 1 <= i <= 7
    // 为了便于计算前缀和，我们设置1 <= i <= 24
    // 观察发现，通过0点可以便利所有的边，且i - 1 >= 0，无需添加超级源点
    // 通过枚举s[24]以利用第3个约束：s[24] >= k, s[24] <= k
private:
    const int N = 25;

    bool Spfa(const int s24, int need[], int worker[], int dist[]) {
        int counter[N];
        bool in_queue[N];
        queue<int> q;
        vector<vector<pair<int, int>>> graph(N);
        memset(dist, -0x3f, sizeof(int) * N);
        memset(counter, 0, sizeof counter);
        memset(in_queue, 0, sizeof in_queue);
        for (int i = 1; i < N; ++i) {
            graph[i - 1].emplace_back(0, i);
            graph[i].emplace_back(-worker[i], i - 1);
            if (i >= 8) {
                graph[i - 8].emplace_back(need[i], i);
            } else {
                graph[i + 16].emplace_back(need[i] - s24, i);
            }
        }
        graph[0].emplace_back(s24, N - 1);
        graph[N - 1].emplace_back(-s24, 0);
        q.emplace(0);
        dist[0] = 0;
        in_queue[0] = true;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            in_queue[root] = false;
            for (const auto &nt: graph[root]) {
                auto nd = nt.first;
                auto nv = nt.second;
                if (dist[nv] >= dist[root] + nd) {
                    continue;
                }
                dist[nv] = dist[root] + nd;
                counter[nv] = counter[root] + 1;
                if (counter[nv] >= N) {
                    return true;
                }
                if (in_queue[nv]) {
                    continue;
                }
                in_queue[nv] = true;
                q.emplace(nv);
            }
        }
        return false;
    }

    int main() {
        int t;
        scanf("%d", &t);
        int need[N];
        int worker[N];
        int dist[N];  // s[N]
        while (t--) {
            memset(need, 0, sizeof need);
            memset(worker, 0, sizeof worker);
            for (int i = 1; i < N; ++i) {
                scanf("%d", &need[i]);
            }
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                int x;
                scanf("%d", &x);
                ++worker[x + 1];
            }
            bool has_answer = false;
            for (int s24 = 1; s24 <= n; ++s24) {
                if (!Spfa(s24, need, worker, dist)) {
                    has_answer = true;
                    printf("%d\n", dist[N - 1]);
                    break;
                }
            }
            if (!has_answer) {
                printf("No Solution\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0393_H
