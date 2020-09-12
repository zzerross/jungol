/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=954&sca=3030
 */
#include <cstdio>

#define S 12
#define C (100 * S)

int N, A[S][S], V[S] = { 0, };

int min(int i, int j) {
    return i < j ? i : j;
}

int solve(int i, int n) {
    int r = C;

    if (n < 1)
        return A[i][0] ? A[i][0] : C;

    V[i] = 1;

    for (int j = 1; j < N; j++)
        if (!V[j] && A[i][j])
            r = min(r, A[i][j] + solve(j, n - 1));

    V[i] = 0;

    return r;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("%d\n", solve(0, N - 1));

    return 0;
}
