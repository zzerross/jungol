/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1097&sca=3030
 */
#include <stdio.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define N 9

int A[N][N], Y[N] = { 0, }, X[N] = { 0, }, B[N][N] = { 0 };

void _bits(int b) {
#ifdef use_pr
    _pr("%5s: b=0x%03x, ", "bits", b);

    for (int i = 1; i <= N; i++)
        if (b & (1 << i))
            _pr("%d ", i);
        else
            _pr(". ");

    _pr("\n");
#endif
}

void dump(const char* s = NULL, int n = N, int m = N) {
    for (int i = 0; i < n; i++) {
        if (s)
            _pr("%s: ", s);

        for (int j = 0; j < m; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }
}

int done() {
    int r = 0;

    for (int i = 0; i < N; i++)
        for (int b = 0, j = 0; j < N; j++)
            if ((b & (1 << A[i][j])))
                goto out;
            else
                b |= (1 << A[i][j]);

    for (int j = 0; j < N; j++)
        for (int b = 0, i = 0; i < N; i++)
            if ((b & (1 << A[i][j])))
                goto out;
            else
                b |= (1 << A[i][j]);

    for (int k = 0; k < 9; k += 3)
        for (int b = 0, i = k; i < k + 3; i++)
            for (int j = k; j < k + 3; j++)
               if ((b & (1 << A[i][j])))
                    goto out;
                else
                    b |= (1 << A[i][j]);

    r = 1;
out:
    _pr("%5s: r=%d\n", __func__, r);

    return r;
}

int solve(int i, int j) {
    if (N <= j) {
        j = 0;

        if (N <= ++i)
            return done();
    }

    if (A[i][j]) {
        if (solve(i, j + 1))
            return 1;
    } else {
        for (int b = Y[i] & X[j] & B[i/3][j/3], n = 1; n <= N; n++) {
            if (b & (1 << n))
                continue;

            A[i][j] = n;

            if (solve(i, j + 1))
                return 1;
        }

        A[i][j] = 0;
    }

    return 0;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);

            Y[i] |= (1 << A[i][j]);
            X[j] |= (1 << A[i][j]);
            B[i/3][j/3] |= (1 << A[i][j]);
        }
    }

    solve(0, 0);

    dump();

    return 0;
}
