/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=386&sca=3030
 */

#include <stdio.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define S 101
#define Z (S * S)

int N, M, A, B, C, D, V[S][S] = { 0, };
int Y[] = { 1, 2,  2,  1, -1, -2, -2, -1, };
int X[] = { 2, 1, -1, -2, -2, -1,  1,  2, };

int dump(const char* s = NULL, int i = -1, int j = -1) {
#ifdef use_pr
    _pr("%8s: %d %d\n", s ? s : __func__, i, j);
    _pr("%8s: ", "");

    for (int j = 1; j <= M; j++)
        _pr("%d ", j % 10);

    _pr("\n");

    for (int i = 1; i <= N; i++) {
        _pr("%8d: ", i);

        for (int j = 1; j <= M; j++)
            if (V[i][j])
                _pr("%d ", V[i][j]);
            else
                _pr(". ");

        _pr("\n");
    }
#endif

    return 0;
}

int range(int i, int j) {
    return 1 <= i && i <= N && 1 <= j && j <= M;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int solve(int i, int j) {
    if (!range(i, j) || V[i][j] == 3)
        return Z;

    if (i == C && j == D)
        return 0;

    V[i][j] = 3;

    dump(__func__, i, j);

    int r = Z;

    for (int d = 0; d < 8; d++)
        r = min(r, solve(i + Y[d], j + X[d]) + 1);

    return r;
}

int main() {
    scanf("%d %d  %d %d  %d %d", &N, &M, &A, &B, &C, &D);

    V[A][B] = 1;
    V[C][D] = 2;
#if 0
    for (int d = 0; d < 8; d++) {
        V[A+Y[d]][B+X[d]] = 3;
        dump(__func__);
    }
    return 0;
#endif
    dump(__func__);

    printf("%d\n", solve(A, B));

    return 0;
}
