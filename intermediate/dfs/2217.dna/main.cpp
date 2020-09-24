/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1478&sca=3030
 */
#include <stdio.h>

#define S 7
#define Z (S * S)

int N, W[S][S], M = 0, L = 0;
char A[S][S+1];

int min(int i, int j) {
    return i < j ? i : j;
}

int max(int i, int j) {
    return i > j ? i : j;
}

int wrap(char* a, char* b) {
    int r = 0;

    for (int w, i = 0; a[i]; i++) {
        for (w = 0; a[i+w]; w++)
            if (a[i+w] != b[w])
                break;

        if (!a[i+w])
            r = max(r, w);
    }

    return r;
}

int solve(int f, int i) {
    if (f == M)
        return 0;

    int r = 0;

    for (int j = 0; j < N; j++)
        if (!(f & (1 << j)))
            r = max(r, solve(f | (1 << j), j) + (f ? W[i][j] : 0));

    return r;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; L += W[i][i], M |= (1 << i++)) {
        scanf("%s", A[i]);

        for (W[i][i] = 0; A[i][W[i][i]]; W[i][i]++);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            W[i][j] = i == j ? 0 : wrap(A[i], A[j]);

    printf("%d\n", L - solve(0, 0));

    return 0;
}
