//
// Created by Fengwei Zhang on 9/20/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0239_H
#define ACWINGSOLUTION_PROBLEM0239_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0239 {
    // https://www.acwing.com/solution/content/29308/
    // 异或运算自己是自己的逆运算
private:
    const int N = 20010;
    int parent[N], dist[N];
    unordered_map<int, int> dataTable;
    int pTop = 0;

    int findRoot(const int x) {
        if (x != parent[x]) {
            auto root = findRoot(parent[x]);
            dist[x] ^= dist[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    int getIdx(const int a) {
        if (dataTable.count(a) == 0) {
            dataTable[a] = pTop;
            ++pTop;
        }
        return dataTable[a];
    }

    bool mergeSets(const int a, const int b, const string &type) {
        int t = 0;
        if (type == "odd") {
            t = 1;
        }
        auto pa = findRoot(a);
        auto pb = findRoot(b);
        if (pa == pb) {
            return dist[a] ^ dist[b] == t;
        }
        parent[pa] = pb;
        dist[pa] = dist[a] ^ dist[b] ^ t;
        return true;
    }

    int main() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
        int n, m;
        scanf("%d%d", &n, &m);
        auto result = m;
        int a, b;
        string type;
        for (int i = 1; i <= m; ++i) {
            cin >> a >> b >> type;
            a = a - 1;
            if (!mergeSets(getIdx(a), getIdx(b), type)) {
                result = i - 1;
                break;
            }
        }
        cout << result << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0239_H
