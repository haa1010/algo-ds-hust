#include <stdio.h>
#define maxn 1000+10
 
int table[maxn][maxn];
int n;
int getArea (int x1, int x2, int y1, int y2) {
    int a = 0;
    for (int i = x1; i <= y1; ++i) {
        for (int j = x2; j <= y2; ++j) {
            if (!table[i][j])
                return -1;
            ++a;
        }
    }
    return a;
}
int main () {
    int tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &tmp);
            table[i][j] = tmp;
        }
    }
    int high = 0;
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!table[i][j])
                continue;
            for (int u = i; u <= n; ++u) {
                for (int v = j; v <= n; ++v) {
                    if ((tmp = getArea(i, j, u, v)) > high) {
                        high = tmp;
                    }
                }
            }
        }
    }
    printf("%d\n", high);
    return 0;
}