/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=729&sca=3030
 */
#include <cstdio>

int M, N, K, A[100][100] = { 0, }, Q[10000], R = 0;
int Y[] = { 1, -1,  0, 0 };
int X[] = { 0,  0, -1, 1 };

int min(int i, int j) {
    return i < j ? i : j;
}

void msrt(int* a, int n) {
    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            static int b[10000], i, j;
            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = 0; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = b[i] < b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int range(int i, int j) {
    return 0 <= i && i < M && 0 <= j && j < N;
}

int solve(int i, int j) {
    if (!range(i, j))
        return 0;

    if (0 != A[i][j])
        return 0;

    A[i][j] = -1;

    int r = 1;

    for (int d = 0; d < 4; d++)
        r += solve(i + Y[d], j + X[d]);

    return r;
}

int main() {
    scanf("%d %d %d", &M, &N, &K);

    for (int u, v, y, x, k = 0; k < K; k++) {
        scanf("%d %d %d %d", &v, &u, &x, &y);

        for (int i = u; i < y; i++)
            for (int j = v; j < x; j++)
                A[i][j] = 1;
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (Q[R] = solve(i, j))
                R++;

    msrt(Q, R);

    printf("%d\n", R);

    for (int i = 0; i < R; i++)
        printf("%d ", Q[i]);

    printf("\n");

    return 0;
}
