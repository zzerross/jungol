/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2073&sca=2020
 */
#include <stdio.h>

#define S ('Z' - 'A' + 1)

int N, C = 0;
char A[202][202];

char next() {
    return 'A' + C++ % S;
}

int dump() {
    for (int i = 1; i < 2 * (N + 1); i++) {
        for (int j = 1; j < 2 * (N + 1); j++)
            printf("%c ", A[i][j] ? A[i][j] : ' ');

        printf("\n");
    }

    return 0;
}

int main() {
    scanf("%d", &N);

    int i, j, k, n, m;

    for (n = N, m = 1; 1 < n; n--, m++) {
        i = m, j = N;

        for (k = 1; k++ < n; i++, j--)
            A[i][j] = next();

        for (k = 1; k++ < n; i++, j++)
            A[i][j] = next();

        for (k = 1; k++ < n; i--, j++)
            A[i][j] = next();

        for (k = 1; k++ < n; i--, j--)
            A[i][j] = next();
    }

    A[m][N] = next();

    return dump();
}
