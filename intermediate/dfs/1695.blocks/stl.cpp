/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=968&sca=3030
 */
#include <cstdio>
#include <algorithm>

#define Z 25

char S[Z][Z+1];
int Y[] = { -1, 1,  0, 0 };
int X[] = {  0, 0, -1, 1 };
int N, Q[Z*Z], B = 0;

int range(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

int solve(int i, int j) {
    if (!range(i, j))
        return 0;

    if (S[i][j] == '0')
        return 0;

    int r = 1;

    S[i][j] = '0';

    for (int d = 0; d < 4; d++)
        r += solve(i + Y[d], j + X[d]);

    return r;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%s", S[i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (Q[B] = solve(i, j))
                B++;

    std::sort(Q, Q + B);

    printf("%d\n", B);

    for (int i = 0; i < B; i++)
        printf("%d\n", Q[i]);

    return 0;
}
