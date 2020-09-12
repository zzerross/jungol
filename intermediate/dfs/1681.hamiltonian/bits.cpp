/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=954&sca=3030
 */
#include <cstdio>

#define S 12
#define C (100 * S)

int N, A[S][S];

static int min(int i, int j) {
    return i < j ? i : j;
}

int solve(int i, int n, int v) {
    int r = C;

    if (n < 1)
        return A[i][0] ? A[i][0] : C;

    for (int b = 1 << 1, j = 1; j < N; j++, b = b << 1)
        if (!(v & b) && A[i][j])
            r = min(r, A[i][j] + solve(j, n - 1, v | b));

    return r;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("%d\n", solve(0, N - 1, 1));

    return 0;
}
