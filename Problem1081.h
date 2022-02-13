//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM1081_H
#define ACWINGSOLUTION_PROBLEM1081_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1081 {
    // 将所有的分支看成一棵二叉树
    // https://www.acwing.com/solution/content/34003/
private:
    vector<vector<int>> initCombinations(const int n) {
        vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j) {
                    c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                } else {
                    c[i][j] = 1;
                }
            }
        }
        return c;
    }

    int dp(int n, const int k, const int b, const vector<vector<int>> &comb) {
        if (n == 0) {
            return 0; //如果上界n是0，直接就是0种
        }

        vector<int> digits; //存放n在b进制下的每一位
        while (n) { // 把n在b进制下的每一位单独拿出来
            digits.emplace_back(n % b);
            n /= b;
        }

        int res = 0; //答案：[0,n]中共有多少个合法的数

        // prefix在数位dp中存的是：右边分支往下走的时候保存前面的信息
        // 遍历当前位的时候，记录之前那些位已经占用多少个1，那么当前还能用的1的个数就是(k - prefix)
        int prefix = 0;
        for (auto i = (int) digits.size() - 1; i >= 0; --i) {  // 从最高位开始遍历
            auto x = digits[i]; //取当前位上的数
            if (x > 0) { // 只有x>0的时候才可以讨论左、右分支

                // 当前位填0，从剩下的所有位（共有i位）中选(k - prefix)个数，对应于左分支中0的情况，合法
                res += comb[i][k - prefix]; // i个数中选(K - prefix)个数的组合数是多少，选出来这些位填1，其他位填0

                if (x > 1) {
                    // 当前位填1，从剩下的所有位（共有i位）中选(k - prefix - 1)个数，对应于左分支中填1的情况，合法
                    if (k - prefix - 1 >= 0) {
                        res += comb[i][k - prefix - 1];  // i个数中选(k - prefix - 1)个数填1的组合数是多少
                    }
                    break;  // 对应于左分支中其他情况（填大于1的数）和此时右分支的情况（右侧此时也大于1），不合法
                } else {
                    // 上面统计完了左分支的所有情况，和右分支大于1的情况，
                    // 这个else分支对应于右分支为1的情况，即限定值为1的情况，也就是左分支只能取0
                    // 此时的处理是，直接放到下一位来处理
                    // 只不过下一位可使用的1的个数会少1，体现在代码上是prefix增加1
                    ++prefix;
                    if (prefix > k) {  // 如果已经填的个数prefix大于需要填的个数k，不合法
                        break;
                    }
                }

            }

            // 上面处理完了这棵树的所有左分支，就剩下最后一种右分支的情况
            // 也就是遍历到最后1位，在vector中就是下标为0的地方：i==0，并且最后1位取0
            // 因为最后1位不为0的话，它已经被上面的if-else处理了
            if (i == 0 && prefix == k) {
                ++res;
            }
        }
        return res;
    }

    int main() {
        int x, y, k, b;
        scanf("%d%d%d%d", &x, &y, &k, &b);
        auto comb = initCombinations(32);
        printf("%d\n", dp(y, k, b, comb) - dp(x - 1, k, b, comb));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1081_H
