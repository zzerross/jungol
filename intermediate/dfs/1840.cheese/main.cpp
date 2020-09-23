/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1113&sca=3030
 */
#include <cstdio>

#define S 100

int Y, X, T = 0, A[S][S], R = 0;
int U[] = { 1, -1,  0, 0 };
int V[] = { 0,  0, -1, 1 };

int range(int i, int j) {
    return 0 <= i && i < Y && 0 <= j && j < X;
}

int solve(int i, int j, int f) {
    if (!range(i, j))
        return 0;

    if (A[i][j] == 1) {
        A[i][j] = f - 1;

        return 1;
    }

    int r = 0;

    if (A[i][j] == f || A[i][j] == 0) {
        A[i][j] = f - 1;

        for (int d = 0; d < 4; d++)
            r += solve(i + U[d], j + V[d], f);
    }

    return r;
}

int main() {
    setbuf(stdout, NULL);

    scanf("%d %d", &Y, &X);

    for (int i = 0; i < Y; i++)
        for (int j = 0; j < X; j++)
            scanf("%d", &A[i][j]);

    for (int f = T, r = 1; r; T++, f--) {
        r = 0;

        for (int i = 0; i < Y; i++) {
            r += solve(i, 0, f);
            r += solve(i, X - 1, f);
        }

        for (int j = 0; j < X; j++) {
            r += solve(0, j, f);
            r += solve(Y - 1, j, f);
        }

        if (r)
            R = r;
    }

    printf("%d\n%d\n", T - 1, R);

    return 0;
}
