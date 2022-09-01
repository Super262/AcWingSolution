#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

void dfs(const char a[], int i,
         const char b[], int j,
         const char c[], int k,
         bool has_carry, int ch2Num[], int num2Ch[], const bool isInitial[], int &ans) {
    if (i >= 0 && ch2Num[a[i]] == -1) {
        for (int y = 0; y <= 9; ++y) {
            if (num2Ch[y] != -1) {
                continue;
            }
            if (isInitial[a[i]] && y == 0) {
                continue;
            }
            num2Ch[y] = (unsigned char) a[i];
            ch2Num[a[i]] = y;
            dfs(a, i, b, j, c, k, has_carry, ch2Num, num2Ch, isInitial, ans);
            num2Ch[y] = -1;
            ch2Num[a[i]] = -1;
        }
        return;
    }
    if (j >= 0 && ch2Num[b[j]] == -1) {
        for (int y = 0; y <= 9; ++y) {
            if (num2Ch[y] != -1) {
                continue;
            }
            if (isInitial[b[j]] && y == 0) {
                continue;
            }
            num2Ch[y] = (unsigned char) b[j];
            ch2Num[b[j]] = y;
            dfs(a, i, b, j, c, k, has_carry, ch2Num, num2Ch, isInitial, ans);
            num2Ch[y] = -1;
            ch2Num[b[j]] = -1;
        }
        return;
    }

    int x = has_carry ? 1 : 0;
    if (i >= 0) {
        x += ch2Num[a[i]];
        --i;
    }
    if (j >= 0) {
        x += ch2Num[b[j]];
        --j;
    }

    if (k < 0) {
        if (x == 0) {
            ++ans;
        }
        return;
    }
    has_carry = x >= 10;
    x %= 10;
    if (ch2Num[c[k]] == -1) {
        if (num2Ch[x] == -1) {
            ch2Num[c[k]] = x;
            num2Ch[x] = (unsigned char) c[k];
            dfs(a, i, b, j, c, k - 1, has_carry, ch2Num, num2Ch, isInitial, ans);
            ch2Num[c[k]] = -1;
            num2Ch[x] = -1;
        }
        return;
    }
    if (ch2Num[c[k]] == x && num2Ch[x] == c[k]) {
        dfs(a, i, b, j, c, k - 1, has_carry, ch2Num, num2Ch, isInitial, ans);
    }
}

int main() {
    const int M = 256;
    bool isInitial[M];
    int num2Ch[M];
    int ch2Num[M];

    memset(isInitial, 0, sizeof isInitial);
    memset(num2Ch, -1, sizeof num2Ch);
    memset(ch2Num, -1, sizeof ch2Num);

    string a = "ONE";
    string b = "TWO";
    string c = "THREE";

    isInitial[a[0]] = true;
    isInitial[b[0]] = true;
    isInitial[c[0]] = true;


    int ans = 0;
    dfs(a.c_str(), (int) a.size() - 1,
        b.c_str(), (int) b.size() - 1,
        c.c_str(), (int) c.size() - 1,
        false, ch2Num, num2Ch, isInitial, ans);

    printf("%d\n", ans);

    return 0;
}