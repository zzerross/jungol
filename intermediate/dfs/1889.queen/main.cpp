#include <stdio.h>

#define S 13

int N, M[S][S] = { 0, }, J[S] = { 0, };

int check(int i, int j) {
    register int y, x;

    if (J[j])
        return 0;

    for (y = i + 1, x = j + 1; y < N && x < N; y++, x++)
        if (M[y][x])
            return 0;

    for (y = i + 1, x = j - 1; y < N && 0 <= x; y++, x--)
        if (M[y][x])
            return 0;

    return 1;
}

int solve(int i) {
    int r = 0;

    if (i < 0)
        return 1;

    for (register int j = 0; j < N; j++) {
        if (check(i, j)) {
            M[i][j] = J[j] = 1;

            r += solve(i - 1);

            M[i][j] = J[j] = 0;
        }
    }

    return r;
}

int main() {
    scanf("%d", &N);

    printf("%d\n", solve(N - 1));

    return 0;
}
