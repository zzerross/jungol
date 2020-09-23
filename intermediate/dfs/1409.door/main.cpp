/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=685&sca=3030
 */

#include <stdio.h>

#define S 20
#define Z (S * S)

int N, O, P, M, T[S], R = 0;

int min(int i, int j) {
    return i < j ? i : j;
}

int range(int i) {
    return 1 <= i && i <= N;
}

int solve(int t, int o, int p);

int solve(int t, int o, int u, int p, int v) {
    if (!range(o) || !range(p) || o == p)
        return Z;

    if (T[t] == o || T[t] == p)
        return solve(t + 1, o, p);

    return solve(t, o + u, u, p + v, v) + 1;
}

int solve(int t, int o, int p) {
    int r = Z;

    if (M <= t)
        return 0;

    if (T[t] == o || T[t] == p)
        return solve(t + 1, o, p);

    r = min(r, solve(t, o, -1, p,  0));
    r = min(r, solve(t, o,  1, p,  0));
    r = min(r, solve(t, o,  0, p, -1));
    r = min(r, solve(t, o,  0, p,  1));

    return r;
}

int main() {
    scanf("%d %d %d %d", &N, &O, &P, &M);

    for (int i = 0; i < M; i++)
        scanf("%d", &T[i]);

    printf("%d\n", solve(0, O, P));

    return 0;
}
