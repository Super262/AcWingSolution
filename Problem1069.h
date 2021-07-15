//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM1069_H
#define ACWINGSOLUTION_PROBLEM1069_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem1069 {
    // https://www.acwing.com/solution/content/5994/
public:
    int compareBigInts(const string &a, const string &b) {
        if (a.size() > b.size()) {
            return 1;
        }
        if (a.size() < b.size()) {
            return -1;
        }
        return a.compare(b);
    }

    string addBigInts(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        unsigned int num = 0;
        string result;
        for (unsigned long long i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) {
                num += a[i] - '0';
            }
            if (i < b.size()) {
                num += b[i] - '0';
            }
            result.push_back((char) ('0' + num % 10));
            num /= 10;
        }
        if (num) {
            result.push_back((char) ('0' + num % 10));
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string mulBigInts(string a, const long long b) {
        reverse(a.begin(), a.end());
        string result;
        unsigned long long i = 0;
        unsigned long long t = 0;
        while (i < a.size() || t != 0) {
            if (i < a.size()) {
                t += (a[i] - '0') * b;
                ++i;
            }
            result.push_back((char) ('0' + t % 10));
            t /= 10;
        }
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string maxValue(const vector<long long> &weights) {
        const int N = (int) weights.size() - 1;
        vector<vector<string>> dp(N + 1, vector<string>(N + 1, "0"));
        for (int length = 3; length <= N; ++length) {
            for (int left = 1; left + length - 1 <= N; ++left) {
                int right = left + length - 1;
                dp[left][right] = string(450, '9');
                for (int mid = left + 1; mid < right; ++mid) {
                    string temp = mulBigInts(to_string(weights[left]), weights[mid]);
                    temp = mulBigInts(temp, weights[right]);
                    temp = addBigInts(temp, dp[left][mid]);
                    temp = addBigInts(temp, dp[mid][right]);
                    if (compareBigInts(dp[left][right], temp) > 0) {
                        dp[left][right] = temp;
                    }
                }
            }
        }
        return dp[1][N];
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<long long> weights(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &weights[i]);
        }
        cout << maxValue(weights) << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1069_H
