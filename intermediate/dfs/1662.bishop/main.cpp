/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=935&sca=3030
 */
#include <stdio.h>

#define S 10

int N, A[S][S];

int max(int i, int j) {
    return i > j ? i : j;
}

int range(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
} 

int valid(int i, int j) {
    if (A[i][j]) {
        for (int y = i + 1, x = j + 1; range(y, x); y++, x++)
            if (A[y][x] == 2)
                return 0;

        for (int y = i + 1, x = j - 1; range(y, x); y++, x--)
            if (A[y][x] == 2)
                return 0;

        for (int y = i - 1, x = j + 1; range(y, x); y--, x++)
            if (A[y][x] == 2)
                return 0;

        for (int y = i - 1, x = j - 1; range(y, x); y--, x--)
            if (A[y][x] == 2)
                return 0;

        return 1;
    }

    return 0;
}

int solve(int i, int j) {
    if (N <= j) {
        if (N <= ++i)
            return 0;

        j = !(j % 2);
    }

    int r = solve(i, j + 2);

    if (valid(i, j)) {
        A[i][j] = 2;

        r = max(r, solve(i, j + 2) + 1);

        A[i][j] = 1;
    }

    return r;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("%d\n", solve(0, 0) + solve(0, 1));

    return 0;
}
