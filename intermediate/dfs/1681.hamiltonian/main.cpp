/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=954&sca=3030
 */
#include <cstdio>

#define S 12
#define C (100 * S)

int N, A[S][S], V[S] = { 0, }, R = C;

int min(int i, int j) {
    return i < j ? i : j;
}

void solve(int i, int n, int s) {
    if (n < 2) {
        R = min(R, A[i][0] ? s + A[i][0] : C);
        return;
    }

    if (R <= s)
        return;

    V[i] = 1;

    for (int j = 1; j < N; j++)
        if (!V[j] && A[i][j])
            solve(j, n - 1, s + A[i][j]);

    V[i] = 0;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    solve(0, N, 0);

    printf("%d\n", R);

    return 0;
}
