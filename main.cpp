#include <iostream>

using namespace std;

int main() {
    int n, m, x;
    scanf("%d %d %d\n", &n, &m, &x);
    int *a = new int[n];
    int *b = new int[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int j = 0; j < m; ++j) {
        scanf("%d", b + j);
    }
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0) {
        if (a[i] + b[j] == x) {
            printf("%d %d\n", i, j);
            ++i;
            --j;
        } else if (a[i] + b[j] > x) {
            --j;
        } else {
            ++i;
        }
    }
    return 0;
}
